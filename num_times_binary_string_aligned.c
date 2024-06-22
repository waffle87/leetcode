// 1375. Number of Times Binary String Is Prefix-Aligned
#include "leetcode.h"

/*
 * you have a 1 indexed binary string of length 'n' where all the bits are 0
 * initially. we will flip all the bits of this binary string one by one. you
 * are given a 1 indexed integer array 'flips' where 'flips[i]' indicates that
 * the bit at index 'i' will be flipped in the i'th step. a binar y string is
 * prefix aligned if after the i'th step, all the bits in the inclusive range
 * '[1, i]' are ones and all the other bits are zeros. return the number of
 * times the binary string is prefix aligned during the flipping process.
 */

int numTimesAllBlue(int *flips, int flipsSize) {
  int max = -1, num = 0, ans = 0;
  for (int i = 0; i < flipsSize; i++) {
    num++;
    if (flips[i] > max)
      max = flips[i];
    if (max == num)
      ans++;
  }
  return ans;
}

int main() {
  int f1[] = {3, 2, 4, 1, 5}, f2[] = {4, 1, 2, 3};
  printf("%d\n", numTimesAllBlue(f1, ARRAY_SIZE(f1))); // expect: 2
  printf("%d\n", numTimesAllBlue(f2, ARRAY_SIZE(f2))); // expect: 1
}
