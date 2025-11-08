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
  if (!n)
    return 0;
  int acc = 0, sign = 1;
  int highest = 31 - __builtin_clz(n);
  for (int i = highest; i >= 0; --i) {
    if ((n >> i) & 1) {
      acc += sign * ((1 << (i + 1)) - 1);
      sign = -sign;
    }
  }
  return acc;
}

int main() {
  printf("%d\n", minimumOneBitOperations(3)); // expect: 2
  printf("%d\n", minimumOneBitOperations(6)); // expect: 4
}
