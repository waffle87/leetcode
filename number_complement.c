// 476. Number Complement
#include "leetcode.h"

/*
 * the complement of an integer is the integer you get when you flip all the 0's
 * to 1's and all the 1's to 0's in its binary representation. for example, the
 * integer 5 is "101" in binary and its complement is "010", which is the
 * integer 2. given an integer 'num', return its complement
 */

int findComplement(int num) { return (uint)~0 >> __builtin_clz(num) ^ num; }

int main() {
  printf("%d\n", findComplement(5)); // expect: 2
  printf("%d\n", findComplement(1)); // expect: 0
}
