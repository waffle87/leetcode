// 2864. Maximum Odd Binary Number
#include "leetcode.h"

/*
 * given a binary string 's' that contains at least one '1'. you have to
 * rearrange the bits in such a way that the resulting binary number is the
 * maximum odd binary number that can be created from this combination. return a
 * string representing the maximum odd binary number that can be created from
 * the given combination.
 */

char *maximumOddBinaryNumber(char *s) {
  int n = strlen(s), one = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == '1')
      one++;
  for (int i = 0; i < n - 1; ++i) {
    if (one > 1) {
      s[i] = '1';
      --one;
    } else
      s[i] = '0';
  }
  s[n - 1] = '1';
  return s;
}

int main() {
  char *s1 = "010", *s2 = "0101";
  printf("%s\n", maximumOddBinaryNumber(s1)); // expect: 001
  printf("%s\n", maximumOddBinaryNumber(s2)); // expect: 1001
}
