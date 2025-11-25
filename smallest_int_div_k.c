// 1015. Smallest Integer Divisible by K
#include "leetcode.h"

/*
 * given a positive integer 'k', you need to find the length of the smallest
 * positive intger 'n' such that 'n' is divisible by 'k' and 'n' only contains
 * the digit 1. return the length of 'n'. if there is no such 'n', return -1.
 * note 'n' may not fit in a 64-bit signed integer.
 */

int smallestRepunitDivByK(int k) {
  for (int i = 0, j = 1; j <= k; ++j)
    if (!(i = (i * 10 + 1) % k))
      return j;
  return -1;
}

int main() {
  printf("%d\n", smallestRepunitDivByK(1)); // expect: 1
  printf("%d\n", smallestRepunitDivByK(2)); // expect: -1
  printf("%d\n", smallestRepunitDivByK(3)); // expect: 3
}
