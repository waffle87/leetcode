// 326. Power of Three
#include "leetcode.h"

/*
 * power of 3 | decimal |  bit
 * -----------|---------|------
 *    3^0     |    1    | 00001
 *    3^1     |    3    | 00011
 *    3^2     |    9    | 01001
 *    3^3     |   27    | 11011
 *
 * notice pattern in above bits:
 *   3^1: 0b0001 + 0b0010  = 0b0011  (3)
 *   3^2: 0b0011 + 0b0110  = 0b1001  (9)
 *   3^3: 0b1001 + 0b10010 = 0b11011 (27)
 *
 * we can keep shifting 'tmp' left by 1 until 'n' is reached. initialise 'tmp'
 * to 1 because the least power of 3 can be 0. if 'tmp' is exactly 'n', it is
 * divisible by 3. returns false automatically when 'n' is negative
 */

bool isPowerOfThree(int n) {
  long tmp = 1;
  while (tmp < n)
    tmp += tmp << 1;
  return tmp == n;
}

int main() {
  printf("%d\n", isPowerOfThree(27));   // expect: 1
  printf("%d\n", isPowerOfThree(0));    // expect: 0
  printf("%d\n", isPowerOfThree(-1));   // expect: 0
  printf("%d\n", isPowerOfThree(6561)); // expect: 1
}
