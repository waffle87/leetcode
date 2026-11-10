// 3693. Climbing Stairs II
#include "leetcode.h"

/*
 * you are climbing a staircase with 'n + 1' steps numbered from 0 to 'n'. you
 * are also given a 1-indexed integer array 'costs' of length 'n' where
 * 'costs[i]' is the cost step 'i'. from step 'i', you can jump only to step 'i
 * + 1', 'i + 2', or 'i + 3'. the cost of jumping from step 'i' to 'j' is
 * defined as 'cost[j] + (j - i)^2'. you start from step 0 with cost 0. return
 * the minimum total cost to reach step 'n'.
 */

int climbStairs(int n, int *costs, int costsSize) {
  int *dp = (int *)malloc((n + 1) * sizeof(int));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int min = INT_MAX;
    for (int j = i - 1; j >= 0 && j >= i - 3; j--)
      min = fmin(min, dp[j] + (i - j) * (i - j));
    dp[i] = min + costs[i - 1];
  }
  int ans = dp[n];
  free(dp);
  return ans;
}

int main() {
  int c1[] = {1, 2, 3, 4};
  int c2[] = {5, 1, 6, 2};
  int c3[] = {9, 8, 3};
  int r1 = climbStairs(4, c1, ARRAY_SIZE(c1));
  int r2 = climbStairs(4, c2, ARRAY_SIZE(c2));
  int r3 = climbStairs(3, c3, ARRAY_SIZE(c3));
  printf("%d\n", r1);
  assert(r1 == 13);
  printf("%d\n", r2);
  assert(r2 == 11);
  printf("%d\n", r2);
  assert(r2 == 12);
}
