// 1007. Minimum Domino Rotations For Equal Row
#include "leetcode.h"

/*
 * in a row of dominoes, 'tops[i]' and 'bottoms[i]' represents the top and
 * bottom halves of the i'th domino. we may rotate the i'th domino so that
 * 'tops[i]' and 'bottoms[i]' swap values. return the minimum number of
 * rotations so that all values in 'tops' are the same, or all values in
 * 'bottoms' are the same. if it cannot be done, return -1.
 */

int minDominoRotations(int *tops, int topsSize, int *bottoms, int bottomsSize) {
  int mask = 0x7E, num = -1, a = 0, b = 0;
  for (int i = 0; i < topsSize; i++) {
    mask &= ((1 << tops[i]) | (1 << bottoms[i]));
    if (!mask)
      return -1;
  }
  while (mask) {
    num++;
    mask >>= 1;
  }
  for (int i = 0; i < topsSize; i++) {
    if (tops[i] == num)
      a++;
    if (bottoms[i] == num)
      b++;
  }
  int max = a > b ? a : b;
  return topsSize - max;
}

int main() {
  int t1[] = {2, 1, 2, 4, 2, 2}, b1[] = {5, 2, 6, 2, 3, 2};
  int t2[] = {3, 5, 1, 2, 3}, b2[] = {3, 6, 3, 3, 4};
  printf("%d\n", minDominoRotations(t1, ARRAY_SIZE(t1), b1,
                                    ARRAY_SIZE(b1))); // expect: 2
  printf("%d\n", minDominoRotations(t2, ARRAY_SIZE(t2), b2,
                                    ARRAY_SIZE(b2))); // expect: -1
}
