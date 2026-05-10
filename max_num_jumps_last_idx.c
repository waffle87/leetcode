// 2770. Maximum Number of Jumps to Reach the Last Index
#include "leetcode.h"

/*
 * you are given an 0-indexed array 'nums' of 'n' integers and an integer
 * 'target'. you are initially positioned at index '0'. in one step, you can
 * jump from index 'i' to index 'j' such that '0 <= i < j < n' and '-target <=
 * nums[j] - nums[i] <= target'. return the maximum number of jumps you can make
 * to reach each index 'n - 1'. if there is no way to reach index 'n - 1',
 * return -1.
 */

int dfs(int i, int *nums, int n, int target, int *memo) {
  if (i == n - 1)
    return 0;
  if (memo[i] != INT_MIN)
    return memo[i];
  int res = INT_MIN;
  for (int j = i + 1; j < n; j++)
    if (abs(nums[i] - nums[j]) <= target)
      res = fmax(res, dfs(j, nums, n, target, memo) + 1);
  memo[i] = res;
  return res;
}

int maximumJumps(int *nums, int numsSize, int target) {
  int *memo = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++)
    memo[i] = INT_MIN;
  int ans = dfs(0, nums, numsSize, target, memo);
  free(memo);
  return ans < 0 ? -1 : ans;
}

int main() {
  int nums[] = {1, 3, 6, 4, 1, 2};
  int r1 = maximumJumps(nums, ARRAY_SIZE(nums), 2);
  int r2 = maximumJumps(nums, ARRAY_SIZE(nums), 3);
  int r3 = maximumJumps(nums, ARRAY_SIZE(nums), 0);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 5);
  printf("%d\n", r3);
  assert(r3 == -1);
}
