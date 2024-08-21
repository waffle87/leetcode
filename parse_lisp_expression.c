// 736. Parse Lisp Expression
#include "leetcode.h"

struct var {
  int val;
  int name_size;
  char *name;
  struct var *next;
};

struct scope {
  struct var *head;
  struct scope *up;
};

static struct var *scope_local_lookup(struct scope *s, char *var_name,
                                      int name_size) {
  for (struct var *n = s->head; n; n = n->next) {
    int cmp_size = n->name_size;
    cmp_size = cmp_size < name_size ? name_size : cmp_size;
    if (!strncmp(var_name, n->name, cmp_size))
      return n;
  }
  return NULL;
}

static struct var *scope_local_define(struct scope *s, char *var_name,
                                      int name_size) {
  struct var **n;
  int cmp_size;
  for (n = &s->head; *n; n = &(*n)->next) {
    cmp_size = (*n)->name_size;
    cmp_size = cmp_size < name_size ? name_size : cmp_size;
    if (!strncmp(var_name, (*n)->name, cmp_size))
      return *n;
  }
  *n = (struct var *)malloc(sizeof(struct var));
  if (!(*n))
    return NULL;
  (*n)->name = var_name;
  (*n)->name_size = name_size;
  (*n)->next = NULL;
  return *n;
}

static struct var *scope_global_lookup(struct scope *s, char *var_name,
                                       int name_size) {
  for (struct scope *n = s; n; n = n->up) {
    struct var *v = scope_local_lookup(n, var_name, name_size);
    if (v)
      return v;
  }
  return NULL;
}

static void scope_free_data(struct scope *s) {
  for (struct var *n = s->head, *t; n;) {
    t = n;
    n = n->next;
    free(t);
  }
  s->head = NULL;
}

static void scope_free(struct scope *s) {
  for (struct scope *n = s, *t; n;) {
    t = n;
    n = n->up;
    scope_free_data(t);
    free(t);
  }
}

static struct scope *push_scope(struct scope **s) {
  struct scope *parent = *s;
  *s = (struct scope *)malloc(sizeof(struct scope));
  if (!(*s)) {
    *s = parent;
    return NULL;
  }
  (*s)->up = parent;
  (*s)->head = NULL;
  return *s;
}

static struct scope *pop_scope(struct scope **s) {
  struct scope *parent = (*s)->up;
  scope_free_data(*s);
  free(*s);
  return *s = parent;
}

enum token_state { END, INT, NAME, SEXP, CLOSE };

struct token {
  int type;
  int len;
  int val;
  char *str;
};

static int token_next(char **s, struct token *dst) {
  int status = 1, sign;
  for (; isspace(**s); ++(*s))
    ;
  if (**s == '\0') {
    dst->len = 0;
    dst->type = END;
    return 1;
  }
  dst->str = *s;
  if (isdigit(**s) || **s == '-' || **s == '+') {
    sign = **s == '-';
    if (**s == '-' || **s == '+')
      ++(*s);
    dst->type = INT;
    dst->val = 0;
    for (; isdigit(**s); ++(*s))
      dst->val = dst->val * 10 - (**s - '0');
    dst->val = sign ? dst->val : -dst->val;
  } else if (isalpha(**s)) {
    dst->type = NAME;
    for (; isalnum(**s); ++(*s))
      ;
  } else if (**s == '(') {
    dst->type = SEXP;
    ++(*s);
  } else if (**s == ')') {
    status = 0;
    dst->type = CLOSE;
    ++(*s);
  }
  dst->len = *s - dst->str;
  return status;
}

static int eval(char **s, int *res, struct token *t, struct scope **curr);

static int evaluate_command_let(char **s, int *res, struct token *t,
                                struct scope **curr) {
  struct var *v;
  char *old_pos, *var_name;
  int var_name_size, var_val;
  if (!push_scope(curr))
    return 0;
  for (;;) {
    old_pos = *s;
    if (!token_next(s, t))
      return 0;
    if (t->type == NAME) {
      var_name = t->str;
      var_name_size = t->len;
      if (!eval(s, &var_val, t, curr)) {
        *s = old_pos;
        break;
      }
      v = scope_local_define(*curr, var_name, var_name_size);
      if (!v)
        return 0;
      v->val = var_val;
    } else {
      *s = old_pos;
      break;
    }
  }
  if (!eval(s, res, t, curr))
    return 0;
  if (token_next(s, t))
    return 0;
  pop_scope(curr);
  return 1;
}

static int evaluate_command_add(char **s, int *res, struct token *t,
                                struct scope **curr) {
  int op1, op2;
  if (!eval(s, &op1, t, curr))
    return 0;
  if (!eval(s, &op2, t, curr))
    return 0;
  *res = op1 + op2;
  if (token_next(s, t))
    return 0;
  return 1;
}

static int evaluate_command_mult(char **s, int *res, struct token *t,
                                 struct scope **curr) {
  int op1, op2;
  if (!eval(s, &op1, t, curr))
    return 0;
  if (!eval(s, &op2, t, curr))
    return 0;
  *res = op1 * op2;
  if (token_next(s, t))
    return 0;
  return 1;
}

static int evaluate_command(char **s, int *res, struct token *t,
                            struct scope **curr) {
  char *cmd = t->str;
  int cmd_size = t->len;
  if (!strncmp(cmd, "let", cmd_size))
    return evaluate_command_let(s, res, t, curr);
  if (!strncmp(cmd, "add", cmd_size))
    return evaluate_command_add(s, res, t, curr);
  if (!strncmp(cmd, "mult", cmd_size))
    return evaluate_command_mult(s, res, t, curr);
}

static int evaluate_sexp(char **s, int *res, struct token *t,
                         struct scope **curr) {
  if (!token_next(s, t))
    return 0;
  if (t->type == NAME)
    return evaluate_command(s, res, t, curr);
  return 0;
}

static int eval(char **s, int *res, struct token *t, struct scope **curr) {
  struct var *v;
  if (!token_next(s, t))
    return 0;
  switch (t->type) {
  case END:
    *res = 0;
    return 1;
  case SEXP:
    return evaluate_sexp(s, res, t, curr);
  case INT:
    *res = t->val;
    return 1;
  case NAME:
    v = scope_global_lookup(*curr, t->str, t->len);
    if (!v)
      return 0;
    *res = v->val;
    return 1;
  default:
    return 0;
  }
}

int evaluate(char *expression) {
  struct scope *curr = NULL;
  struct token t;
  char *s = expression;
  int ans = 0;
  if (!eval(&s, &ans, &t, &curr)) {
    scope_free(curr);
    return -1;
  }
  return ans;
}

int main() {
  char *e1 = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
  char *e2 = "let x 3 x 2 x)";
  char *e3 = "(let x 1 y 2 x (add x y) (add x y))";
  printf("%d\n", evaluate(e1)); // expect: 14
  printf("%d\n", evaluate(e2)); // expect: 2
  printf("%d\n", evaluate(e3)); // expect: 5
}
