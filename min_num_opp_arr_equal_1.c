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
  while (b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int minOperations(int *nums, int numsSize) {
  int n = 0, g = 0;
  for (int i = 0; i < numsSize; i++) {
    int curr = nums[i];
    if (curr == 1)
      n++;
    g = gcd(g, curr);
  }
  if (n > 0)
    return numsSize - n;
  if (g > 1)
    return -1;
  int min = numsSize;
  for (int i = 0; i < numsSize; i++) {
    int curr = 0;
    for (int j = i; j < numsSize; j++) {
      curr = gcd(curr, nums[j]);
      if (curr == 1) {
        if (j - i + 1 < min)
          min = j - i + 1;
        break;
      }
    }
  }
  return min + numsSize - 2;
}

int main() {
  int n1[] = {2, 6, 3, 4}, n2[] = {2, 10, 6, 14};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2))); // expect: -1
}
