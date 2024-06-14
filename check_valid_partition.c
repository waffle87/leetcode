// 2369. Check if There is a Valid Partition For The Array
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed integer array 'nums', you have to partition the array into
 * one or more contiguous subarrays. we call a partition of the array valid if
 * each of the obtained subarrays satisfies one of the following conditions
 * - the subarray consists of exactly 2 equal elements. for example, the
 * subarray '[2,2]' is good.
 * - the subarray consists of exactly 3 equal elements. for example, the
 * subarray '[4,4,4]' is good.
 * - the subarray consists of exactly 3 consecutive increasing elements, that
 * is, the difference between adjacent elements is 1. for example, the subarray
 * '[3,4,5]' is good, but the subarray '[1,3,5]' is not. return true if the
 * array has at least one valid partition. otherwise, return false.
 */

bool validPartition(int *nums, int nums_size) {
  int n = nums_size, *dp = calloc(n + 1, sizeof(bool));
  dp[0] = true;
  if (nums[0] == nums[1])
    dp[2] = true;
  int consecutive_false = 0;
  for (int i = 3; i <= n; i++) {
    if (nums[i - 1] == nums[i - 2]) {
      dp[i] |= dp[i - 2];
      if (dp[i]) {
        consecutive_false = 0;
        continue;
      }
      if (nums[i - 2] == nums[i - 3]) {
        dp[i] |= dp[i - 3];
        if (dp[i]) {
          consecutive_false = 0;
          continue;
        }
      }
    } else {
      if ((nums[i - 1] == nums[i - 2] + 1) &&
          (nums[i - 2] == nums[i - 3] + 1)) {
        dp[i] |= dp[i - 3];
        if (dp[i]) {
          consecutive_false = 0;
          continue;
        }
      }
    }
    consecutive_false++;
    if (consecutive_false == 3)
      break;
  }
  return dp[n];
}

int main() {
  int n1[] = {4, 4, 4, 5, 6}, n2[] = {1, 1, 1, 2};
  printf("%d\n", validPartition(n1, 5)); // expect: 1
  printf("%d\n", validPartition(n2, 4)); // expect: 0
}
