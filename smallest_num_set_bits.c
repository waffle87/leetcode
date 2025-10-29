// 3370. Smallest Number With All Set Bits
#include "leetcode.h"

/*
 * you are given a positive number 'n'. return the smallest number 'x' greater
 * than or equal to 'n' such that the binary represeentation of 'x' contains
 * only set bits.
 */

int smallestNumber(int n) { return INT_MAX >> __builtin_clz(n) - 1; }

int main() {
  printf("%d\n", smallestNumber(5));  // expect: 7
  printf("%d\n", smallestNumber(10)); // expect: 15
}
