// 405. Convert a Number to Hexadecimal
#include "leetcode.h"

/*
 * given a 32 bit integer 'num', return a string representing its hexadecimal
 * representation. for negative integers, two's complement method is used. all
 * the letters in the answer string should be lowercase characters, nd there not
 * be any leading zeros in the answer except for the zero itself. note: you are
 * not allowed to use any built-in library method to directly solve this
 * problem.
 */

char *toHex(int num) {
  char *ans = (char *)malloc(sizeof(char) * 10), step;
  uint x = num, i = 0;
  ans[9] = '\0';
  while (1) {
    step = x & 0xF;
    ans[8 - i] = step > 9 ? 'a' + step - 10 : '0' + step;
    x >>= 4;
    if (!x)
      break;
    i++;
  }
  return &ans[8 - i];
}

int main() {
  char *th1 = toHex(26);
  char *th2 = toHex(-1);
  printf("%s\n", th1); // expect: 1a
  printf("%s\n", th2); // expect: ffffffff
  free(th1);
  free(th2);
}
