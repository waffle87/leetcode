// 198. House Robber
#include "leetcode.h"

/*
 * you are a professional robber planning to rob houses along a stree. each
 * house has a certain amount of money stashed, the only constraint topping you
 * from robbing each of them is that the adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night. given an integer array 'nums'
 * representing the amount of money each house has, return the maximum amount of
 * money you can rob without alerting the police.
 */

int rob(int *nums, int nums_size) {
  int *dp = malloc(sizeof(int) * nums_size);
  if (!nums_size)
    return 0;
  for (int i = 0; i < nums_size; i++) {
    switch (i) {
    case 0:
      dp[i] = nums[0];
      break;
    case 1:
      dp[i] = fmax(nums[i], dp[i - 1]);
      break;
    default:
      dp[i] = fmax(nums[i] + dp[i - 2], dp[i - 1]);
    }
  }
  return dp[nums_size - 1];
}

int main() {
  int n1[] = {1, 2, 3, 1}, n2[] = {2, 7, 9, 3, 1};
  printf("%d\n", rob(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", rob(n2, ARRAY_SIZE(n2))); // expect: 12
}
