// 1800. Maximum Ascending Subarray Sum
#include "leetcode.h"

/*
 * given an array of positive integers 'nums', return the maximum possible sum
 * of an ascending subarray in 'nums'. a subarray is defined as a contiguous
 * sequence of numbers in an array.
 */

int maxAscendingSum(int *nums, int numsSize) {
  int ans = 0, sum = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] <= nums[i - 1]) {
      ans = fmax(ans, sum);
      sum = 0;
    }
    sum += nums[i];
  }
  return fmax(ans, sum);
}

int main() {
  int n1[] = {10, 20, 30, 5, 10, 50}, n2[] = {10, 20, 30, 40, 50},
      n3[] = {12, 17, 15, 13, 10, 11, 12};
  printf("%d\n", maxAscendingSum(n1, ARRAY_SIZE(n1))); // expect: 65
  printf("%d\n", maxAscendingSum(n2, ARRAY_SIZE(n2))); // expect: 150
  printf("%d\n", maxAscendingSum(n3, ARRAY_SIZE(n3))); // expect: 33
}
