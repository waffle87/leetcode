// 1844. Replace All Digits with Characters
#include "leetcode.h"

/*
 * given a 0-indexed string 's' that has lowercase english letters in its even
 * indices and digits in its odd indices. there is a function 'shift(x, c)'
 * where 'x' is a character and 'c' is an integer that returns the c'th
 * character after 'x'. for every odd index 'i', you want to replace the digit
 * 's[i]' with shift(s[i - 1], s[i]). return 's' after replacing all digits.
 */

char *replaceDigits(char *s) {
  int n = strlen(s);
  for (int i = 1; i < n; i++)
    s[i] += s[i - 1] - '0';
  return s;
}

int main() {
  char *s1 = "a1c1e1", *s2 = "a1b2c3d4e";
  printf("%s\n", replaceDigits(s1)); // expect: abcdef
  printf("%s\n", replaceDigits(s2)); // expect: abbdcfdhe
}
