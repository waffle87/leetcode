// 3578. Count Partitions With Max-Min Difference at Most K
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. your task is to
 * partition 'nums' into one or more non-empty contiguous segments such that in
 * each segment, the difference between its maximum and minimum elements is at
 * most 'k'. return the total number of ways to partition 'nums' under this
 * condition. since the answer may be too large, return it modulo 10^9 + 7.
 */

int countPartitions(int *nums, int numsSize, int k) {
  static int mod = 1e9 + 7;
  long *dp = (long *)calloc(numsSize + 1, sizeof(long)), total = 0;
  dp[0] = 1;
  int *max = (int *)malloc(numsSize * sizeof(int));
  int *min = (int *)malloc(numsSize * sizeof(int));
  int max_l = 0, max_r = 0, min_l = 0, min_r = 0, l = 0;
  for (int r = 0; r < numsSize; r++) {
    while (max_l < max_r && nums[max[max_r - 1]] <= nums[r])
      max_r--;
    while (min_l < min_r && nums[min[min_r - 1]] >= nums[r])
      min_r--;
    max[max_r++] = r;
    min[min_r++] = r;
    while (nums[max[max_l]] - nums[min[min_l]] > k) {
      if (max[max_l] == l)
        max_l++;
      if (min[min_l] == l)
        min_l++;
      total = (total - dp[l] + mod) % mod;
      l++;
    }
    total = (total + dp[r]) % mod;
    dp[r + 1] = total;
  }
  int ans = dp[numsSize];
  free(dp);
  free(max);
  free(min);
  return ans;
}

int main() {
  int n1[] = {9, 4, 1, 3, 7}, n2[] = {3, 3, 4};
  printf("%d\n", countPartitions(n1, ARRAY_SIZE(n1), 4)); // expect: 6
  printf("%d\n", countPartitions(n2, ARRAY_SIZE(n2), 0)); // expect: 2
}
