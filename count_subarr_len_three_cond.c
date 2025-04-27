// 3392. Count Subarrays of Length Three With a Condition
#include "leetcode.h"

/*
 * given an integer array 'nums', return the number of subarrays of length 3
 * such that the sum of the first and third number equals exactly half of the
 * second number.
 */

int countSubarrays(int *nums, int numsSize) {
  int cnt = 0;
  for (int i = 1; i < numsSize - 1; ++i)
    if (2 * (nums[i - 1] + nums[i + 1]) == nums[i])
      cnt++;
  return cnt;
}

int main() {
  int n1[] = {1, 2, 1, 4, 1}, n2[] = {1, 1, 1};
  printf("%d\n", countSubarrays(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", countSubarrays(n2, ARRAY_SIZE(n2))); // expect: 0
}
