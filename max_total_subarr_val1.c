// 3689. Maximum Total Subarray Value I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and an integer 'k'. you
 * need to choose exactly 'k' non-empty subarrays 'nums[l ... r]' of 'nums'.
 * subarrays may overlap, and the exact same subarray can be chosen more than
 * once. the value of a subarray 'nums[l ... r]' is defined as 'max(nums[l ...
 * r]) - min(nums[l ... r])'. the total value is the sum of the values of all
 * chosen subarrays. return the maximum possible total value you can achieve.
 */

long long maxTotalValue(int *nums, int numsSize, int k) {
  int min = nums[0], max = nums[0];
  for (int i = 0; i < numsSize; i++) {
    min = fmin(min, nums[i]);
    max = fmax(max, nums[i]);
  }
  return (long long)(max - min) * k;
}

int main() {
  int n1[] = {1, 3, 2}, n2[] = {4, 2, 5, 1};
  long long r1 = maxTotalValue(n1, ARRAY_SIZE(n1), 2);
  long long r2 = maxTotalValue(n2, ARRAY_SIZE(n2), 3);
  printf("%lld\n", r1);
  assert(r1 == 4);
  printf("%lld\n", r2);
  assert(r2 == 12);
}
