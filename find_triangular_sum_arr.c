// 2221. Find Triangular Sum of an Array
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums', where 'nums[i]' is a digit
 * between 0 and 9 inclusive. the triangular sum of 'nums' is the value of the
 * only element present in 'nums' after the following process concludes: let
 * 'nums' comprise of 'n' elements. if 'n == 1', end the process. otherwise,
 * create a new 0-indexed integer array 'new_nums' of length 'n - 1'. for each
 * index 'i' where '0 <= i < n - 1', assign the value of 'new_nums[i]' as
 * '(nums[i] + nums[i + 1]) % 10'. replace the array 'nums' with 'new_nums', and
 * repeat the entire process starting again.
 */

int triangularSum(int *nums, int numsSize) {
  for (int i = numsSize - 1; i >= 1; i--)
    for (int j = 0; j < i; j++)
      nums[j] = (nums[j] + nums[j + 1]) % 10;
  return nums[0];
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, n2[] = {5};
  printf("%d\n", triangularSum(n1, ARRAY_SIZE(n1))); // expect: 8
  printf("%d\n", triangularSum(n2, ARRAY_SIZE(n2))); // expect: 5
}
