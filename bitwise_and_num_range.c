// 201. Bitwise AND of Numbers Range
#include "leetcode.h"

/*
 * given two integers 'm' and 'n' that represent the range '[m,
 * n]', return the bitwise and of all numbers in this range, inclusive.
 */

int rangeBitwiseAnd(int m, int n) {
  int k = 0;
  while (m != n) {
    m >>= 1;
    n >>= 1;
    ++k;
  }
  return n << k;
}

int main() {
  printf("%d\n", rangeBitwiseAnd(5, 7));          // expect: 4
  printf("%d\n", rangeBitwiseAnd(0, 0));          // expect: 0
  printf("%d\n", rangeBitwiseAnd(1, 2147483647)); // expect: 0
}
