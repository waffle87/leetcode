// 3512. Minimum Operations to Make Array Sum Divisible by K
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. you can perform the
 * following operation any number of times: select an index 'i' and replace
 * 'nums[i]' with 'nums[i] - 1'. return the minimum number of operations to make
 * the sum of the array divisible by 'k'.
 */

int minOperations(int *nums, int numsSize, int k) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  return sum % k;
}

int main() {
  int n1[] = {3, 9, 7}, n2[] = {4, 1, 3}, n3[] = {3, 2};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1), 5)); // expect: 4
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2), 4)); // expect: 0
  printf("%d\n", minOperations(n3, ARRAY_SIZE(n3), 6)); // expect: 5
}
