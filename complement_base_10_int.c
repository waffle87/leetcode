// 1009. Complement of Base 10 Integer
#include "leetcode.h"

/*
 * the complement of an integer is the integer you get when you flip all the 0's
 * to 1's and all the 1's to 0's in its binary representation. given an integer
 * 'n', return its complement.
 */

int bitwiseComplement(int n) {
  if (!n)
    return 1;
  unsigned int mask = ~0;
  while (mask & n)
    mask <<= 1;
  return ~n ^ mask;
}

int main() {
  int r1 = bitwiseComplement(5);
  int r2 = bitwiseComplement(7);
  int r3 = bitwiseComplement(10);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r2); // expect: 0
  assert(r2 == 0);
  printf("%d\n", r3); // expect: 5
  assert(r3 == 5);
}
