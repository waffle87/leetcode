// 231. Power of Two
#include "leetcode.h"

/*
 * given an integer 'n', return true if it is a power of two. otherwise, return
 * false. an integer 'n' is a power of two if there exists an integer 'x' such
 * that 'n == 2^x'
 */

bool isPowerOfTwo(int n) { return n > 0 && __builtin_popcount(n) == 1; }

int main() {
  printf("%d\n", isPowerOfTwo(1));  // expect: 1
  printf("%d\n", isPowerOfTwo(16)); // expect: 1
  printf("%d\n", isPowerOfTwo(3));  // expect: 0
}
