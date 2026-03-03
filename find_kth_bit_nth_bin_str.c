// 1545. Find Kth Bit in Nth Binary String
#include "leetcode.h"

/*
 * given two positive integers 'n' and 'k', the binary string 's_n' is formed as
 * follows: 's_1 = 0', 's_i = s_i - 1 + "1" + reverse(invert(s_i - 1))' for 'i >
 * 1'. where '+' denotes the concatenation operation, 'reverse(x)' returns the
 * reversed string 'x', and 'invert(x)' inverts all teh bits in 'x'. return the
 * k'th bit in 's_n'. it is guaranteed that 'k' is valid for the given 'n'.
 */

char findKthBit(int n, int k) {
  if (k == 1)
    return '0';
  int m = 32 - __builtin_clz(k);
  int x = (1 << m) - k;
  if (x == k)
    return '1';
  return findKthBit(n, x) == '0' ? '1' : '0';
}

int main() {
  char r1 = findKthBit(3, 1);
  char r2 = findKthBit(4, 11);
  printf("%c\n", r1); // expect: 0
  assert(r1 == '0');
  printf("%c\n", r2); // expect: 1
  assert(r2 == '1');
}
