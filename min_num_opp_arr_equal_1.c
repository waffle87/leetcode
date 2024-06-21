// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
#include "leetcode.h"

/*
 * given a 0-indexed array 'nums' consisting of positive integers. you can do
 * the following operation on the array any number of time: select an index 'i'
 * such that '0 <= i < n - 1' and replace either of 'nums[i]' or 'nums[i + 1]'
 * with their gcd values. return the minimum number of operations to make all
 * elements of 'nums' equal to 1. if this is impossible, return -1. the gcd of
 * two integers is the greatest common divisor of the two integers.
 */

int gcd(int a, int b) {
  int rem = a % b;
  if (!rem)
    return b;
  return gcd(b, rem);
}

int minOperations(int *nums, int numsSize) {
  int one_cnt = 0;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] == 1)
      one_cnt++;
  if (one_cnt >= 1)
    return numsSize - one_cnt;
  int min_subarr_len = numsSize + 1;
  for (int i = 0; i < numsSize; i++) {
    int curr = nums[i];
    for (int j = i + 1; j < numsSize; j++) {
      curr = gcd(curr, nums[j]);
      if (curr == 1) {
        int curr_n = (j + 1) - i;
        if (curr_n < min_subarr_len)
          min_subarr_len = curr_n;
      }
      break;
    }
  }
  return min_subarr_len <= numsSize ? (min_subarr_len - 1) + (numsSize - 1)
                                    : -1;
}

int main() {
  int n1[] = {2, 6, 3, 4}, n2[] = {2, 10, 6, 14};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2))); // expect: -1
}
