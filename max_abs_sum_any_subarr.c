// 1749. Maximum Absolute Sum of Any Subarray
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. the absolute sum of a subarray '[nums,
 * nums[i + 1], ..., nums[r]]' is 'abs(nums, nums[i], ..., nums[r])'. return the
 * maximum absolute sum of any (possibly empty) subarray of 'nums'. note that
 * 'abs(x)' is defined as follows: if 'x' is negative integer, then 'abs(x) =
 * -x'. if 'x' is a non negative integer, then 'abs(x) = x'
 */

int maxAbsoluteSum(int *nums, int numsSize) {
  int max_sum = INT_MIN, min_sum = INT_MAX, curr_sum = 0;
  for (int i = 0; i < numsSize; i++) {
    curr_sum += nums[i];
    max_sum = max_sum > curr_sum ? max_sum : curr_sum;
    if (curr_sum < 0)
      curr_sum = 0;
  }
  curr_sum = 0;
  for (int i = 0; i < numsSize; i++) {
    curr_sum += nums[i];
    min_sum = min_sum < curr_sum ? min_sum : curr_sum;
    if (curr_sum > 0)
      curr_sum = 0;
  }
  return abs(max_sum) > abs(min_sum) ? abs(max_sum) : abs(min_sum);
}

int main() {
  int n1[] = {1, -3, 2, 3, -4}, n2[] = {2, -5, 1, -4, 3, -2};
  printf("%d\n", maxAbsoluteSum(n1, ARRAY_SIZE(n1))); // expect: 5
  printf("%d\n", maxAbsoluteSum(n2, ARRAY_SIZE(n2))); // expect: 8
}
