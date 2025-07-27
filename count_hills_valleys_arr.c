// 2210. Count Hills and Valleys in an Array
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. an index 'i' is part of a
 * hill in 'nums' if the closest non-equal neighbours of 'i' are smaller than
 * 'nums[i]'. similarly, an index 'i' is part of a valley in 'nums' if the
 * closest non-equal neighbours of 'i' are larger than 'nums[i]'. adjacent
 * indices 'i' and 'j' are part of the same hill or valley if 'nums[i] ==
 * nums[j]'. note that for an index to be part of a hill or valley, it must have
 * a non-equal neighbour on both the left and right of the index. return the
 * number of hills and valleys in 'nums'.
 */

int countHillValley(int *nums, int numsSize) {
  int prev = 0, ans = 0;
  for (int i = 1; i < numsSize - 1; ++i) {
    if (nums[prev] == nums[i] || nums[i + 1] == nums[i])
      continue;
    if ((nums[prev] - nums[i] & INT_MIN) == (nums[i + 1] - nums[i] & INT_MIN))
      ans++;
    prev = i;
  }
  return ans;
}

int main() {
  int n1[] = {2, 4, 1, 1, 6, 5}, n2[] = {6, 6, 5, 5, 4, 1};
  printf("%d\n", countHillValley(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", countHillValley(n2, ARRAY_SIZE(n2))); // expect: 0
}
