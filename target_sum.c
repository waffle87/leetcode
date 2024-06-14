// 494. Target Sum
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'target'. you want to buildan
 * expression out of numbers by adding oneof the symbols '+' and '-' before each
 * integer in nums awnd then concatenate all the integers. for example if 'nums
 * = [2,1]', you can adda '+' before '2' and '-' before '1' and concatenate them
 * to build the expression '+2-1'. return the number of different
 * expressionsthat you can build, which evaluates to 'target'.
 */

int findTargetSumWays(int *nums, int numsSize, int target) {
  if (numsSize == 1) {
    if (nums[0] == target && nums[0] == -target)
      return 2;
    if (nums[0] == target || nums[0] == -target)
      return 1;
    return 0;
  }
  return findTargetSumWays(&nums[1], numsSize - 1, target + nums[0]) +
         findTargetSumWays(&nums[1], numsSize - 1, target - nums[0]);
}

int main() {
  int n1[] = {1, 1, 1, 1, 1}, n2[] = {1};
  printf("%d\n", findTargetSumWays(n1, ARRAY_SIZE(n1), 3)); // expect: 5
  printf("%d\n", findTargetSumWays(n2, ARRAY_SIZE(n2), 1)); // expect: 1
}
