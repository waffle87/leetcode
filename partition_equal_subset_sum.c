// 416. Partition Equal Subset Sum
#include "leetcode.h"

/*
 * given an integer array 'nums', return true if you can partition the array
 * into two subsets such that the sum of the elements in both subsets is equal
 * or false otherwise
 */

bool is_subset_sum(int *nums, int numsSize, int sum) {
  bool dp[numsSize + 1][numsSize + 1];
  for (int i = 0; i <= numsSize; i++)
    dp[i][0] = true;
  for (int i = 1; i <= sum; i++)
    dp[0][i] = false;
  for (int i = 1; i <= numsSize; i++)
    for (int j = 1; j <= sum; j++)
      dp[i][j] = nums[i - 1] <= j ? dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]
                                  : dp[i - 1][j];
  return dp[numsSize][sum];
}

bool canPartition(int *nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  if ((sum % 2))
    return false;
  return is_subset_sum(nums, numsSize, sum / 2);
}

int main() {
  int n1[] = {1, 5, 11, 5}, n2[] = {1, 2, 3, 5};
  printf("%d\n", canPartition(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", canPartition(n2, ARRAY_SIZE(n2))); // expect: 0
}
