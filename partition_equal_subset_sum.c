// 416. Partition Equal Subset Sum
#include "leetcode.h"

/*
 * given an integer array 'nums', return true if you can partition the array
 * into two subsets such that the sum of the elements in both subsets is equal
 * or false otherwise
 */

bool memo(int *nums, int **dp, int sum, int idx, int n) {
  if (!sum)
    return true;
  if (idx >= n)
    return false;
  if (dp[idx][sum] != -1)
    return dp[idx][sum];
  bool pick = false, no_pick = false;
  if (nums[idx] <= sum)
    pick = memo(nums, dp, sum - nums[idx], idx + 1, n);
  no_pick = memo(nums, dp, sum, idx + 1, n);
  return dp[idx][sum] = (pick || no_pick);
}

bool canPartition(int *nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  if (sum & 1)
    return false;
  int **dp = (int **)malloc(numsSize * sizeof(int *));
  for (int i = 0; i < numsSize; i++) {
    dp[i] = (int *)malloc(((sum >> 1) + 1) * sizeof(int));
    for (int j = 0; j < ((sum >> 1) + 1); ++j)
      dp[i][j] = -1;
  }
  bool ans = memo(nums, dp, sum >> 1, 0, numsSize);
  for (int i = 0; i < numsSize; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int n1[] = {1, 5, 11, 5}, n2[] = {1, 2, 3, 5};
  printf("%d\n", canPartition(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", canPartition(n2, ARRAY_SIZE(n2))); // expect: 0
}
