// 342. Power of Four
#include "leetcode.h"

/*
 * given an integer 'n', return 'true' if it is a power of four, otherwise,
 * return 'false'. an integer 'n' is a power of four if there exists an integer
 * 'x' such that 'n == 4^x'
 */

bool isPowerOfFour(int n) {
  return n > 0 && __builtin_popcount((unsigned)n) == 1 && !((n - 1) % 3);
}

int main() {
  printf("%d\n", isPowerOfFour(16)); // expect: 1
  printf("%d\n", isPowerOfFour(5));  // expect: 0
  printf("%d\n", isPowerOfFour(1));  // expect: 1
}
