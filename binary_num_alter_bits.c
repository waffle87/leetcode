// 693. Binary Number with Alternating Bits
#include "leetcode.h"

/*
 * given a positive integer, check whether it has alternating bits: namely if
 * two adjacent bits will always have different values
 */

bool hasAlternatingBits(int n) {
  long long int x = n ^ (n >> 1);
  return !(x & (x + 1));
}

int main() {
  printf("%d\n", hasAlternatingBits(5));  // expect: 1
  printf("%d\n", hasAlternatingBits(7));  // expect: 0
  printf("%d\n", hasAlternatingBits(11)); // expect: 0
}
