// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
#include "leetcode.h"

/*
 * you are given a binary array 'nums'. you can do the following operation on
 * the array any number of times (possibly zero): choose any three consecutive
 * elements from the array and flip all of them. flipping an element means
 * changing its value from 0 to 1, and from 1 to 0. return the minimum number of
 * operations required needed to make all elements in 'nums' equal to 1. if it
 * is impossible, return -1.
 */

int minOperations(int *nums, int numsSize) {
  int cnt = 0;
  for (int i = 0; i < numsSize - 2; i++)
    if (!nums[i]) {
      nums[i] ^= 1;
      nums[i + 1] ^= 1;
      nums[i + 2] ^= 1;
      cnt++;
    }
  return nums[numsSize - 2] && nums[numsSize - 1] ? cnt : -1;
}

int main() {
  int n1[] = {0, 1, 1, 1, 0, 0}, n2[] = {0, 1, 1, 1};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2))); // expect: -1
}
