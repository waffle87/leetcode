// 1780. Check if Number is a Sum of Powers of Three
#include "leetcode.h"

/*
 * given an integer 'n', return true if it is possible to represent 'n' as the
 * sum of distinct powers of three. otherwise, return false. an integer 'y' is a
 * power of three if there exists an integer 'x' such that 'y == 3^x'
 */

bool checkPowersOfThree(int n) {
  static int pow3[] = {4782969, 1594323, 531441, 177147, 59049,
                       19683,   6561,    2187,   729,    243,
                       81,      27,      9,      3,      1};
  for (int i = 0; i < 15; i++)
    if (n >= 2 * pow3[i])
      return false;
    else if (n >= pow3[i])
      n -= pow3[i];
  return true;
}

int main() {
  printf("%d\n", checkPowersOfThree(12)); // expect: 1
  printf("%d\n", checkPowersOfThree(91)); // expect: 1
  printf("%d\n", checkPowersOfThree(21)); // expect: 0
}
