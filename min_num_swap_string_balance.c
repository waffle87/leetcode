// 1963. Minimum Number of Swaps to Make the String Balanced
#include "leetcode.h"

/*
 * you are given a 0-indexed string 's' of even length 'n'. the string consists
 * of exactly 'n / 2' opening and closing square brackets. a string is called
 * balanced if and only if it is empty string, it can be written as 'AB' where
 * both 'A' and 'B' are balanced strings, or it can be written as '[C]' where
 * 'C' is a balanced string. you may swap the brackets at any two indices any
 * number of times. return the minimum number of swaps to make 's' balanced
 */

int minSwaps(char *s) {
  int bal = 0, ans = 0, i = 0;
  while (s[i]) {
    if (s[i] == '[')
      bal--;
    else if (s[i] == ']')
      bal++;
    if (bal > ans)
      ans = bal;
    ++i;
  }
  return (ans + 1) / 2;
}

int main() {
  char *s1 = "][][", *s2 = "]]][[[", *s3 = "[]";
  printf("%d\n", minSwaps(s1)); // expect: 1
  printf("%d\n", minSwaps(s2)); // expect: 2
  printf("%d\n", minSwaps(s3)); // expect: 0
}
