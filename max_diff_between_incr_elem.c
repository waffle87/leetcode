// 2016. Maximum Difference Between Increasing Elements
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums' of size 'n', find the maximum
 * difference between 'nums[i]' and 'nums[j]' (ie. 'nums[j] - nums[i]') such
 * that '0 <= i < j < n' and 'nums[i] < nums[j]'. return the maximum difference.
 * if no such 'i' and 'j' exist, return -1
 */

int maximumDifference(int *nums, int numsSize) {
  int min = nums[0], ans = -1;
  for (int i = 1; i < numsSize; ++i) {
    ans = fmax(ans, nums[i] - min);
    min = fmin(min, nums[i]);
  }
  return ans;
}

int main() {
  int n1[] = {7, 1, 5, 4}, n2[] = {9, 4, 3, 2}, n3[] = {1, 5, 2, 10};
  printf("%d\n", maximumDifference(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", maximumDifference(n2, ARRAY_SIZE(n2))); // expect: -1
  printf("%d\n", maximumDifference(n3, ARRAY_SIZE(n3))); // expect: 9
}
