// 1680. Concatenation of Consecutive Binary Numbers
#include "leetcode.h"

/*
 * given an integer 'n', return the decimal value of the binary string formed by
 * concatenating the binary rerpesentations of 1 to 'n' in order, modulo 10^9
 * + 7.
 */

int concatenatedBinary(int n) {
  long ans = 0, mod = 1e9 + 7, len = 0;
  for (int i = 1; i <= n; ++i) {
    if (__builtin_popcount(i) == 1)
      ++len;
    ans = ((ans << len) % mod + i) % mod;
  }
  return ans;
}

int main() {
  int r1 = concatenatedBinary(1);
  int r2 = concatenatedBinary(3);
  int r3 = concatenatedBinary(12);
  printf("%d\n", r1); // expect: 1
  assert(r1 == 1);
  printf("%d\n", r2); // expect: 27
  assert(r2 == 27);
  printf("%d\n", r3); // expect: 505379714
  assert(r3 == 505379714);
}
