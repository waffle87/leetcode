// 326. Power of Three
#include "leetcode.h"

/*
 * given an integer 'n', return true if it is a power of three. otherwise,
 * return false. an integer 'n' is a power of three, if there exists an integer
 * 'x' such that 'n == 3^x'
 */

bool isPowerOfThree(int n) { return n > 0 && !(1162261467 % n); }

int main() {
  printf("%d\n", isPowerOfThree(27)); // expect: 1
  printf("%d\n", isPowerOfThree(0));  // expect: 0
  printf("%d\n", isPowerOfThree(-1)); // expect: 0
}
