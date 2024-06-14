// 1330. Reverse Subarray To Maximize Array Value
#include "leetcode.h"

/*
 * given an intger array 'nums'. the value of this array is defined as the sum
 * of '| nums[i] - nums[i + 1] |' for all '0 <= i < nums.len - 1'. you are
 * allowed to select any subarray of the given array and reverse it. you can
 * perform this operation only once. find maximum possible value of the final
 * array.
 */

int maxValueAfterReverse(int *nums, int numsSize) {
  int total = 0, sum = 0, min2 = 123456, max2 = -123456, n = numsSize;
  for (int i = 0; i < n - 1; ++i) {
    int a = nums[i], b = nums[i + 1];
    total += abs(a - b);
    sum = fmax(sum, abs(nums[0] - b) - abs(a - b));
    sum = fmax(sum, abs(nums[n - 1] - a) - abs(a - b));
    min2 = fmin(min2, fmax(a, b));
    max2 = fmax(max2, fmin(a, b));
  }
  return total + fmax(sum, (max2 - min2) * 2);
}

int main() {
  int n1[] = {2, 3, 1, 5, 4}, n2[] = {2, 4, 9, 24, 2, 1, 10};
  printf("%d\n", maxValueAfterReverse(n1, ARRAY_SIZE(n1))); // expect: 10
  printf("%d\n", maxValueAfterReverse(n2, ARRAY_SIZE(n2))); // expect: 68
}
