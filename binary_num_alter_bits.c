// 693. Binary Number with Alternating Bits
#include "leetcode.h"
#include <cassert>
#include <stdio.h>

/*
 * given a positive integer, check whether it has alternating bits: namely if
 * two adjacent bits will always have different values
 */

bool hasAlternatingBits(int n) {
  n ^= (n >> 1);
  return !(n & n + 1);
}

int main() {
  bool r1 = hasAlternatingBits(5);
  bool r2 = hasAlternatingBits(7);
  bool r3 = hasAlternatingBits(11);
  printf("%d\n", r1); // expect: 1
  assert(r1 == true);
  printf("%d\n", r2); // expect: 0
  assert(r2 == false);
  printf("%d\n", r3); // expect: 0
  assert(r3 == true);
}
