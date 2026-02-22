// 868. Binary Gap
#include "leetcode.h"

/*
 * given a positive integer 'n', find and return the longest distance between
 * any two adjacent 1's in the binary representation of 'n'. if there are no two
 * adjacent 1's, return 0. two 1's are adjacent if there are only 0's separating
 * them. the distance between two 1's is the absolute difference between their
 * bit positions.
 */

int binaryGap(int n) {
  if (__builtin_popcount(n) == 1)
    return 0;
  n >>= __builtin_ctz(n);
  int max_gap = 0, gap = 0;
  while (n) {
    if (n & 1) {
      max_gap = fmax(max_gap, gap);
      gap = 0;
    } else
      gap++;
    n >>= 1;
  }
  return max_gap + 1;
}

int main() {
  int r1 = binaryGap(22);
  int r2 = binaryGap(8);
  int r3 = binaryGap(5);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r2); // expect: 0
  assert(r2 == 0);
  printf("%d\n", r3); // expect: 2
  assert(r3 == 2);
}
