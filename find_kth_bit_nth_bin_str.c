// 1545. Find Kth Bit in Nth Binary String
#include "leetcode.h"

/*
 * given two positive integers 'n' and 'k', the binary string 's_n' is formed as
 * follows: 's_1 = 0', 's_i = s_i - 1 + "1" + reverse(invert(s_i - 1))' for 'i >
 * 1'. where '+' denotes the concatenation operation, 'reverse(x)' returns the
 * reversed string 'x', and 'invert(x)' inverts all teh bits in 'x'. return the
 * k'th bit in 's_n'. it is guaranteed that 'k' is valid for the given 'n'.
 */

int max_bit(int n) {
  while ((n & (n - 1)))
    n &= n - 1;
  return n;
}

char findKthBit(int n, int k) {
  int inv = 0;
  while (k & (k - 1)) {
    k = -k & (max_bit(k) - 1);
    inv ^= 1;
  }
  return ((k > 1) ^ inv) + '0';
}

int main() {
  printf("%c\n", findKthBit(3, 1));  // expect: 0
  printf("%c\n", findKthBit(4, 11)); // expect: 1
}
