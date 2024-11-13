// 1106. Parsing A Boolean Expression
#include "leetcode.h"

/*
 * a boolean expression is an expression that evaluates to either 'true' or
 * 'false'. it can be one of the following shapes:
 * - 't' that evaluates to true
 * - 'f' that evaluates to false
 * - '!(subExpr)' that evalutes to the logical not of the inner expression
 * 'subExpr'
 * - '&(subExpr1, subExpr2, ..., subExprn)' that evalutes to the logical AND of
 * the inner expressions 'subExpr1, subExpr2, ..., subExprn' where 'n >= 1'
 * - '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of
 * the inner expressions 'subExpr1, subExpr2, ..., subExprn' where 'n >= 1'
 * given a string 'expression' that represents a boolean expression, return the
 * evaluation of that expression
 */

struct parse_node {
  char op;
  char val;
  int num_ops;
  int cap;
  struct parse_node **operand;
};

struct parse_node *parse_node_create(void) {
  struct parse_node *p = (struct parse_node *)malloc(sizeof(struct parse_node));
  p->op = '\0';
  p->num_ops = 0;
  p->cap = 4;
  p->operand =
      (struct parse_node **)malloc(p->cap * sizeof(struct parse_node *));
  p->val = '?';
  return p;
}

void parse_node_free(struct parse_node *p) {
  for (int i = 0; i < p->num_ops; i++)
    parse_node_free(p->operand[i]);
  free(p->operand);
  free(p);
}

void parse_node_addop(struct parse_node *res, const struct parse_node *expr) {
  res->operand[res->num_ops++] = (struct parse_node *)expr;
  if (res->num_ops >= res->cap) {
    res->cap <<= 1;
    res->operand = (struct parse_node **)realloc(
        res->operand, res->cap * sizeof(struct parse_node *));
  }
}

int parse_expr(const char *expr, struct parse_node *res) {
  char *orig_expr = (char *)expr;
  switch (*expr) {
  case '&':
  case '|':
  case '!':
    res->op = *expr;
    expr++;
    do {
      expr++;
      struct parse_node *e = parse_node_create();
      expr += parse_expr(expr, e);
      parse_node_addop(res, e);
    } while (*expr != ')');
    expr++;
    break;
  case 't':
  case 'f':
    res->val = *expr++;
    break;
  }
  return expr - orig_expr;
}

bool parse_node_eval(struct parse_node *p) {
  if (p->val != '?')
    return p->val == 't';
  if (p->op == '!')
    return p->val = !parse_node_eval(p->operand[0]);
  if (p->op == '&') {
    for (int i = 0; i < p->num_ops; i++) {
      bool v = parse_node_eval(p->operand[i]);
      if (!v)
        return p->val = false;
    }
    return p->val = true;
  }
  if (p->op == '|') {
    for (int i = 0; i < p->num_ops; i++) {
      bool v = parse_node_eval(p->operand[i]);
      if (v)
        return p->val = true;
    }
    return p->val = false;
  }
  return false;
}

bool parseBoolExpr(char *expression) {
  struct parse_node *root = parse_node_create();
  int len = parse_expr(expression, root);
  bool eval = parse_node_eval(root);
  parse_node_free(root);
  return eval;
}

int main() {
  char e1[] = {"&(|(f))"}, e2[] = {"|(f,f,f,t)"}, e3[] = {"!(&(f,t))"};
  printf("%d\n", parseBoolExpr(e1)); // expect: 0
  printf("%d\n", parseBoolExpr(e2)); // expect: 1
  printf("%d\n", parseBoolExpr(e3)); // expect: 1
}
