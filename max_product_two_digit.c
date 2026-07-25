// 3536. Maximum Product of Two Digits
#include "leetcode.h"

/*
 * you are given a positive integer 'n'. return the maximum product of any two
 * digits 'n'. note you may use the same digit twice if it appears more than
 * once in 'n'.
 */

unsigned int bit_width(unsigned int x) {
  if (!x)
    return 0;
  return (sizeof(unsigned int) * CHAR_BIT) - __builtin_clz(x);
}

int maxProduct(int n) {
  unsigned int a = 0, b = 0;
  for (; n; n /= 10) {
    b |= a & (1 << (n % 10));
    a |= 1 << (n % 10);
  }
  unsigned int x = bit_width(a) - 1;
  unsigned int y = bit_width((a ^ (1 << x)) | b) - 1;
  return x * y;
}

int main() {
  int r1 = maxProduct(31);
  int r2 = maxProduct(22);
  int r3 = maxProduct(124);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 4);
  printf("%d\n", r3);
  assert(r3 == 8);
}
