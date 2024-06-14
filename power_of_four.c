// 342. Power of Four
#include <stdbool.h>
#include <stdio.h>

/*
 * given an integer 'n', return 'true' if it is a power of four, otherwise,
 * return 'false'. an integer 'n' is a power of four if there exists an integer
 * 'x' such that 'n == 4^x'
 */

bool isPowerOfFour(int n) {
  int ans = 0, pos = 1, ones = 0;
  while (n) {
    if (n & 1) { // if 'n' is even...
      ans++;
      ones = pos;
    }
    n >>= 1; // 'n' / 2
    pos++;
  }
  return ans == 1 && ones & 1;
}

int main() {
  printf("%d\n", isPowerOfFour(16)); // expect: 1
  printf("%d\n", isPowerOfFour(5));  // expect: 0
  printf("%d\n", isPowerOfFour(1));  // expect: 1
}
