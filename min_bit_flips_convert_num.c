// 2220. Minimum Bit Flips to Convert Number
#include "leetcode.h"

/*
 * a bit flip of a number 'x' is choosing a bit in the binary representation of
 * 'x' and flipping it from either 0 to 1 or 1 to 0. given two integers 'start'
 * and 'goal', return the minimum number of bit flips to convert 'start' to
 * 'goal'.
 */

int minBitFlips(int start, int goal) {
  return __builtin_popcount(start ^ goal);
}

int main() {
  printf("%d\n", minBitFlips(10, 7)); // expect: 3
  printf("%d\n", minBitFlips(3, 4));  // expect: 3
}
