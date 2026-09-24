// 3550. Smallest Index With Digit Sum Equal to Index
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. return the smallest index 'i' such
 * that the sum of the digits of 'nums[i]' is equal to 'i'. if no such index
 * exists, return -1.
 */

int smallestIndex(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    int x = nums[i], sum = 0;
    for (; x > 0; x /= 10)
      sum += x % 10;
    if (sum == i)
      return i;
  }
  return -1;
}

int main() {
  int n1[] = {1, 3, 2};
  int n2[] = {1, 10, 11};
  int n3[] = {1, 2, 3};
  int r1 = smallestIndex(n1, ARRAY_SIZE(n1));
  int r2 = smallestIndex(n2, ARRAY_SIZE(n2));
  int r3 = smallestIndex(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == -1);
}
