// 241. Different Ways to Add Parentheses
#include "leetcode.h"

/*
 * given a string 'expression' of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. you may return the answer in any order. the test cases are
 * generated such that the output values fit in a 32-bit integer and the number
 * of different results does not exceed 10^4
 */

int compute(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  default:
    return 0;
  }
}

bool is_num(char *expression) {
  for (int i = 0; i < strlen(expression); i++)
    if (!isdigit(expression[i]))
      return false;
  return true;
}

int *grow_array(int *arr, int curr_size, int new_size) {
  return (int *)realloc(arr, new_size * sizeof(int));
}

int *diffWaysToCompute(char *expression, int *returnSize) {
  int capacity = 10;
  int *ans = (int *)malloc(capacity * sizeof(int));
  *returnSize = 0;
  if (is_num(expression)) {
    ans[0] = atoi(expression);
    *returnSize = 1;
    return ans;
  }
  for (int i = 0; i < strlen(expression); i++) {
    char e = expression[i];
    if (e == '+' || e == '-' || e == '*') {
      char left[100], right[100];
      strncpy(left, expression, i);
      left[i] = '\0';
      strcpy(right, expression + i + 1);
      int left_size, right_size;
      int *left_ans = diffWaysToCompute(left, &left_size);
      int *right_ans = diffWaysToCompute(right, &right_size);
      for (int l = 0; l < left_size; l++)
        for (int r = 0; r < right_size; r++) {
          if (*returnSize >= capacity) {
            capacity *= 2;
            ans = grow_array(ans, capacity / 2, capacity);
          }
          ans[*returnSize] = compute(left_ans[l], right_ans[r], e);
          (*returnSize)++;
        }
      free(left_ans), free(right_ans);
    }
  }
  return ans;
}

int main() {
  char *e1 = "2-1-1", *e2 = "2*3-4*5";
  int rs1, rs2;
  int *dwtc1 = diffWaysToCompute(e1, &rs1),
      *dwtc2 = diffWaysToCompute(e2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", dwtc1[i]); // expect: 0 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", dwtc2[i]); // expect: -34 -14 -10 -10 10
  printf("\n");
  free(dwtc1), free(dwtc2);
}
