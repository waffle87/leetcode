// 1009. Complement of Base 10 Integer
#include "leetcode.h"

/*
 * the complement of an integer is the integer you get when you flip all the 0's
 * to 1's and all the 1's to 0's in its binary representation. given an integer
 * 'n', return its complement.
 */

int bitwiseComplement(int n) {
  int c = 1;
  while (c < n)
    c = (c << 1) + 1;
  return n ^ c;
}

int main() {
  printf("%d\n", bitwiseComplement(5));  // expect: 2
  printf("%d\n", bitwiseComplement(7));  // expect: 0
  printf("%d\n", bitwiseComplement(10)); // expect: 5
}
