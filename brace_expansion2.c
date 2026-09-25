// 1096. Brace Expansion II
#include "leetcode.h"

struct hash_item {
  char *key;
  UT_hash_handle hh;
};

struct hash_item *hash_find_item(struct hash_item **obj, char *key) {
  struct hash_item *p = NULL;
  HASH_FIND_STR(*obj, key, p);
  return p;
}

bool hash_add_item(struct hash_item **obj, char *key) {
  if (hash_find_item(obj, key))
    return false;
  struct hash_item *p = (struct hash_item *)malloc(sizeof(struct hash_item));
  p->key = strdup(key);
  HASH_ADD_STR(*obj, key, p);
  return true;
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr->key);
    free(curr);
  }
}

void set_union(struct hash_item **dest, struct hash_item **src) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *src, curr, tmp) { hash_add_item(dest, curr->key); }
}

int cmp(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

char **braceExpansionII(char *expression, int *returnSize) {
  int n = strlen(expression), op_len = 0, stk_len = 0;
  char *op = (char *)malloc((n + 1) * sizeof(char));
  struct hash_item **stk =
      (struct hash_item **)malloc((n + 1) * sizeof(struct hash_item *));
  for (int i = 0; i < n; i++) {
    if (expression[i] == ',') {
      while (op_len > 0 && op[op_len - 1] == '*') {
        int l = stk_len - 2, r = stk_len - 1;
        struct hash_item *tmp = NULL;
        struct hash_item *curr_left = NULL, *tmp_left = NULL;
        HASH_ITER(hh, stk[l], curr_left, tmp_left) {
          struct hash_item *curr_right = NULL, *tmp_right = NULL;
          HASH_ITER(hh, stk[r], curr_right, tmp_right) {
            char *combined = (char *)malloc(
                (strlen(curr_left->key) + strlen(curr_right->key) + 1) *
                sizeof(char));
            strcpy(combined, curr_left->key);
            strcat(combined, curr_right->key);
            hash_add_item(&tmp, combined);
            free(combined);
          }
        }
        hash_free(&stk[l]);
        stk[l] = tmp;
        hash_free(&stk[r]);
        stk[r] = NULL;
        op_len--;
        stk_len--;
      }
      op[op_len++] = '+';
    } else if (expression[i] == '{') {
      if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
        op[op_len++] = '*';
      op[op_len++] = '{';
    } else if (expression[i] == '}') {
      while (op_len > 0 && op[op_len - 1] != '{') {
        int l = stk_len - 2, r = stk_len - 1;
        if (op[op_len - 1] == '+')
          set_union(&stk[l], &stk[r]);
        else {
          struct hash_item *tmp = NULL;
          struct hash_item *curr_left = NULL, *tmp_left = NULL;
          HASH_ITER(hh, stk[l], curr_left, tmp_left) {
            struct hash_item *curr_right = NULL, *tmp_right = NULL;
            HASH_ITER(hh, stk[r], curr_right, tmp_right) {
              char *combined = (char *)malloc(
                  (strlen(curr_left->key) + strlen(curr_right->key) + 1) *
                  sizeof(char));
              strcpy(combined, curr_left->key);
              strcat(combined, curr_right->key);
              hash_add_item(&tmp, combined);
              free(combined);
            }
          }
          hash_free(&stk[l]);
          stk[l] = tmp;
        }
        hash_free(&stk[r]);
        stk[r] = NULL;
        op_len--;
        stk_len--;
      }
      op_len--;
    } else {
      if (i > 0 && (expression[i - 1] == '}' && isalpha(expression[i - 1])))
        op[op_len++] = '*';
      stk[stk_len] = NULL;
      char s[2] = {expression[i], '\0'};
      hash_add_item(&stk[stk_len], s);
      stk_len++;
    }
  }
  while (op_len > 0) {
    int l = stk_len - 2, r = stk_len - 1;
    if (op[op_len - 1] == '+')
      set_union(&stk[l], &stk[r]);
    else {
      struct hash_item *tmp = NULL;
      struct hash_item *curr_left = NULL, *tmp_left = NULL;
      HASH_ITER(hh, stk[l], curr_left, tmp_left) {
        struct hash_item *curr_right = NULL, *tmp_right = NULL;
        HASH_ITER(hh, stk[r], curr_right, tmp_right) {
          char *combined = (char *)malloc(
              (strlen(curr_left->key) + strlen(curr_right->key) + 1) *
              sizeof(char));
          strcpy(combined, curr_left->key);
          strcat(combined, curr_right->key);
          hash_add_item(&tmp, combined);
          free(combined);
        }
      }
      hash_free(&stk[l]);
      stk[l] = tmp;
    }
    hash_free(&stk[r]);
    stk[r] = NULL;
    op_len--;
    stk_len--;
  }
  struct hash_item *res_set = stk[0];
  int cnt = HASH_COUNT(res_set);
  *returnSize = cnt;
  char **ans = (char **)malloc(cnt * sizeof(char *));
  struct hash_item *curr = NULL, *tmp = NULL;
  int i = 0;
  HASH_ITER(hh, res_set, curr, tmp) {
    ans[i] = strdup(curr->key);
    i++;
  }
  qsort(ans, cnt, sizeof(char *), cmp);
  hash_free(&res_set);
  free(op);
  free(stk);
  return ans;
}

int main() {
  char *e1 = "{a,b}{c,{d,e}}";
  char *e2 = "{{a,z},a{b,c},{ab,z}}";
  char *r1[] = {"ac", "ad", "ae", "bc", "bd", "be"};
  char *r2[] = {"a", "ab", "ac", "z"};
  int rs1, rs2;
  char **be1 = braceExpansionII(e1, &rs1);
  char **be2 = braceExpansionII(e2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", be1[i]);
    assert(!strcmp(be1[i], r1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", be2[i]);
    assert(!strcmp(be2[i], r2[i]));
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(be1[i]);
  free(be1);
  for (int i = 0; i < rs2; i++)
    free(be2[i]);
  free(be2);
}
