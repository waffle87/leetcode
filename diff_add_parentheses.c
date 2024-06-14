// 241. Different Ways to Add Parentheses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 'expression' of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. you may return the answer in any order. the test cases are
 * generated such that the output values fit in a 32-bit integer and the number
 * of different results is <10^4
 */

#define CAL(a, b, op) ('+' == op ? a + b : '-' == op ? a - b : a * b)

void token_size(char *s, char **op, int **num, int *return_size) {
  int i, s_len = (int)strlen(s), len = 0;
  int *res = malloc(sizeof(int) * ((s_len + 1) >> 1));
  char *ops = malloc(s_len >> 1);
  res[0] = 0;
  for (int i = 0; i < s_len; ++i) {
    if ('0' > s[i] || s[i] > '9') {
      ops[len++] = s[i];
      res[len] = 0;
    } else
      res[len] = res[len] * 10 + s[i] - '0';
  }
  len++;
  *return_size = len;
  *num = res;
  *op = ops;
}

int *helper(int *return_size, int *nums, int len, char *op) {
  int i, j, k, cnt = 0, cap = 10, *set = malloc(sizeof(int) * cap);
  int *ss1 = NULL, *ss2 = NULL, sl1 = 0, sl2 = 0;
  if (2 >= len) {
    set[cnt++] = 1 == len ? nums[0] : CAL(nums[0], nums[1], op[0]);
    *return_size = cnt;
    return set;
  }
  for (i = 1; i <= len - 1; ++i) {
    ss1 = helper(&sl1, nums, i, op);
    ss2 = helper(&sl2, nums + i, len - i, op + i);
    if (cnt + sl1 * sl2 >= cap) {
      cap += (sl1 * sl2) << 1;
      set = realloc(set, sizeof(int) * cap);
    }
    for (j = 0; j < sl1; ++j)
      for (k = 0; k < sl2; ++k)
        set[cnt++] = CAL(ss1[j], ss2[k], op[i - 1]);
    free(ss1);
    free(ss2);
  }
  *return_size = cnt;
  return set;
}

int *diffWaysToCompute(char *expression, int *return_size) {
  int *nums, *ans, len;
  char *op;
  if (!expression) {
    *return_size = 0;
    return NULL;
  }
  token_size(expression, &op, &nums, &len);
  ans = helper(return_size, nums, len, op);
  free(op);
  free(nums);
  return ans;
}

int main() {
  char e1[] = {"2 - 1 - 1"}, e2[] = {"2 * 3 - 4 * 5"};
  int *dwtc1 = diffWaysToCompute(e1, NULL);
  int *dwtc2 = diffWaysToCompute(e2, NULL);
  for (int i = 0; i < 2; i++)
    printf("%d ", dwtc1[i]); // expect: 0,2
  printf("\n");
  for (int i = 0; i < 5; i++)
    printf("%d ", dwtc2[i]); // expect: -34,-14,-10,-10,10
}
