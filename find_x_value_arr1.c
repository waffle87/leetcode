// 3524. Find X Value of Array I
#include "leetcode.h"

/*
 * you are given an array of positive integers 'nums', and a positive integer
 * 'k'. you are allowed to perform an operation once on 'nums' where in each
 * operation you can remove any non-overlapping prefix and suffix from 'nums'
 * such that 'nums' remains non-empty. you need to find the x-value of 'nums'
 * which is the nmber of ways to perform this operation so that the product of
 * the remaining elements leaves a remainder of 'x' when divided by 'k'.
 */

long long *resultArray(int *nums, int numsSize, int k, int *returnSize) {
  long long *ans = (long long *)calloc(k, sizeof(long long));
  *returnSize = k;
  long long **dp = (long long **)malloc(numsSize * sizeof(long long *));
  for (int i = 0; i < numsSize; i++)
    dp[i] = (long long *)calloc(k, sizeof(long long));
  for (int i = 0; i < numsSize; i++) {
    dp[i][nums[i] % k]++;
    if (i > 0) {
      for (int r = 0; r < k; r++) {
        int rem = ((long long)r * nums[i]) % k;
        dp[i][rem] += dp[i - 1][r];
      }
    }
  }
  for (int i = 0; i < numsSize; i++)
    for (int r = 0; r < k; r++)
      ans[r] += dp[i][r];
  for (int i = 0; i < numsSize; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, r1[] = {9, 2, 4}, rs1;
  int n2[] = {1, 2, 4, 8, 16, 32}, r2[] = {18, 1, 2, 0}, rs2;
  int n3[] = {1, 1, 2, 1, 1}, r3[] = {9, 6}, rs3;
  long long *ra1 = resultArray(n1, ARRAY_SIZE(n1), 3, &rs1);
  long long *ra2 = resultArray(n2, ARRAY_SIZE(n2), 4, &rs2);
  long long *ra3 = resultArray(n3, ARRAY_SIZE(n3), 2, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%lld ", ra1[i]);
    assert(ra1[i] == (long long)r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%lld ", ra2[i]);
    assert(ra2[i] == (long long)r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%lld ", ra3[i]);
    assert(ra3[i] == (long long)r3[i]);
  }
  printf("\n");
  free(ra1);
  free(ra2);
  free(ra3);
}
