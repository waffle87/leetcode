// 1611. Minimum One Bit Operations to Make Integers Zero
#include "leetcode.h"

/*
 * given an integer 'n', you must transform it into '0' using the following
 * operations: change the rightmost (LSB) bit in the binary representation of
 * 'n', or change the i'th bit in the binary representation of 'n' if the '(i -
 * 1)'th bit is set to 1 and the '(i - 2)'th through the 0th bits are set to 0.
 * return the minimum number of operations to transform 'n' into '0'.
 */

int minimumOneBitOperations(int n) {
  int tmp = n, sign = 1, cnt = 0, pos = 0;
  while (tmp) {
    if (tmp & (1 << pos)) {
      cnt += sign * ((1 << (pos + 1)) - 1);
      tmp &= ~(1 << pos);
      sign *= -1;
    }
    pos--;
  }
  return cnt;
}

int main() {
  printf("%d\n", minimumOneBitOperations(3));    // expect: 2
  printf("%d\n", minimumOneBitOperations(6));    // expect: 4
  printf("%d\n", minimumOneBitOperations(8174)); // expect: N/A
}
