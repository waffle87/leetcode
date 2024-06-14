// 967. Numbers With Same Consecutive Differences
#include "leetcode.h"

/*
 * given two integers 'n' and 'k' return an array of all the integers of length
 * 'n' where the difference between every two consecutive digits is 'k'. you may
 * return the answer in any order. note that the integers should not have
 * leading zeros. integers as 02 and 043 are not allowed.
 */

void dfs(int *res, int *idx, int val, int digit, int k) {
  if (!digit) {
    res[*idx] = val;
    (*idx)++;
    return;
  }
  if (val % 10 + k < 10)
    dfs(res, idx, val * 10 + (val % 10 + k), digit - 1, k);
  if ((val % 10) - k >= 0)
    dfs(res, idx, val * 10 + (val % 10 - k), digit - 1, k);
}

int *numsSameConsecDiff(int n, int k, int *returnSize) {
  if (!k) {
    int *ans = (int *)malloc(9 * sizeof(int));
    for (int i = 1; i <= 9; i++) {
      int val = i;
      for (int j = 0; j < n - 1; j++)
        val = val * 10 + i;
      ans[i - 1] = val;
    }
    *returnSize = 9;
    return ans;
  }
  int *ans = (int *)malloc(9 * pow(2, n) * sizeof(int)), idx = 0;
  for (int i = 1; i <= 9; i++)
    dfs(ans, &idx, i, n - 1, k);
  *returnSize = idx;
  return ans;
}

int main() {
  int rs1, rs2;
  int *nscd1 = numsSameConsecDiff(3, 7, &rs1);
  int *nscd2 = numsSameConsecDiff(2, 1, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", nscd1[i]); // expect: 181 292 707 818 929
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf(
        "%d ",
        nscd2[i]); // expect: 10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98
  printf("\n");
  free(nscd1), free(nscd2);
}
