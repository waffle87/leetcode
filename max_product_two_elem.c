// 1464. Maximum Product of Two Elements in an Array
#include "leetcode.h"

/*
 * given the array of integers 'nums', you will choose two different indices 'i'
 * and 'j' of thatarray. return the maximum value of '(nums[i] - 1) * (nums[j] -
 * 1)'
 */

int maxProduct(int *nums, int nums_size) {
  if (nums_size == 2)
    return (nums[0] - 1) * (nums[1] - 1);
  int max = nums[1] > nums[0] ? nums[1] : nums[0];
  int min = nums[1] > nums[0] ? nums[0] : nums[1];
  for (int i = 2; i < nums_size; i++) {
    if (nums[i] > max) {
      min = max;
      max = nums[i];
    } else if (nums[i] <= max && nums[i] > min)
      min = nums[i];
  }
  return (max - 1) * (min - 1);
}

int main() {
  int n1[] = {3, 4, 5, 2}, n2[] = {1, 5, 4, 5}, n3[] = {3, 7};
  printf("%d\n", maxProduct(n1, ARRAY_SIZE(n1))); // expect: 12
  printf("%d\n", maxProduct(n2, ARRAY_SIZE(n2))); // expect: 16
  printf("%d\n", maxProduct(n3, ARRAY_SIZE(n3))); // expect: 12
}
