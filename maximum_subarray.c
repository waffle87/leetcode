// 53. Maximum Subarray
#include "leetcode.h"

/*
 * given an integer array 'nums', find the subarray with the largest sum, and
 * return its sum.
 */

int maxSubArray(int *nums, int numsSize) {
  int max_sum = nums[0], curr_sum = 0;
  for (int i = 0; i < numsSize; i++) {
    curr_sum += nums[i];
    if (max_sum < curr_sum)
      max_sum = curr_sum;
    if (curr_sum < 0)
      curr_sum = 0;
  }
  return max_sum;
}

int main() {
  int n1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}, n2[] = {1},
      n3[] = {5, 4, -1, 7, 8};
  printf("%d\n", maxSubArray(n1, ARRAY_SIZE(n1))); // expect: 6
  printf("%d\n", maxSubArray(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", maxSubArray(n3, ARRAY_SIZE(n3))); // expect: 23
}
