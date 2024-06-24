// 995. Minimum Number of K Consecutive Bit Flips
#include "leetcode.h"

/*
 * given a binary array 'nums', and an integer 'k'. a k-bit flip is choosing a
 * subarray of length 'k' from 'nums' and simultaneously changing every 0 in the
 * subarray to 1, and every 1 in the subarray to 0. return the minimum number of
 * k-bit flips required so that there is no 0 in the array. if it is not
 * possible, return -1. a subarray is a contiguous part of an array.
 */

int minKBitFlips(int *nums, int numsSize, int k) {
  int ans = 0, n = numsSize;
  int *dp = (int *)calloc(n + 2 * k, sizeof(int));
  for (int i = 0; i < n; i++) {
    dp[i + k] += dp[i + k - 1];
    if (!nums[i] && !(dp[i + 2] % 2)) {
      if (n - i < k)
        return -1;
      ans++;
      dp[i + k]++;
      dp[i + k + k]--;
    } else if (nums[i] && dp[i + k] % 2 == 1) {
      if (n - i < k)
        return -1;
      ans++;
      dp[i + k]++;
      dp[i + k + k]--;
    }
  }
  free(dp);
  return ans;
}

int main() {
  int n1[] = {0, 1, 0}, n2[] = {1, 1, 0}, n3[] = {0, 0, 0, 1, 0, 1, 1, 0};
  printf("%d\n", minKBitFlips(n1, ARRAY_SIZE(n1), 1)); // expect: 2
  printf("%d\n", minKBitFlips(n2, ARRAY_SIZE(n2), 2)); // expect: -1
  printf("%d\n", minKBitFlips(n3, ARRAY_SIZE(n3), 3)); // expect: 3
}
