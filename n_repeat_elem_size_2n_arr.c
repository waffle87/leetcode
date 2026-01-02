// 961. N-Repeated Element in Size 2N Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums' with the following properties:
 * 'nums.length == 2 * n', 'nums' contains 'n + 1' unique elements, and exactly
 * one element of 'nums' is repeated 'n' times. return the element that is
 * repeated 'n' times.
 */

int repeatedNTimes(int *nums, int numsSize) {
  bool hash[10001] = {false};
  for (int i = 0; i < numsSize; ++i) {
    if (hash[nums[i]])
      return nums[i];
    else
      hash[nums[i]] = true;
  }
  return -1;
}

int main() {
  int n1[] = {1, 2, 3, 3}, n2[] = {2, 1, 2, 5, 3, 2},
      n3[] = {5, 1, 5, 2, 5, 3, 5, 4};
  printf("%d\n", repeatedNTimes(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", repeatedNTimes(n2, ARRAY_SIZE(n2))); // expect: 2
  printf("%d\n", repeatedNTimes(n3, ARRAY_SIZE(n3))); // expect: 5
}
