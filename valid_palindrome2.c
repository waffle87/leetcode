// 680. Valid Palindrome II
#include "leetcode.h"

/*
 * given a string 's', return 'true' if the 's' can be palindrome after deleting
 * at most one charater from it.
 */

bool check(char *s, int n) {
  if (n <= 1)
    return 1;
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - i - 1])
      return 0;
  return 1;
}

bool validPalindrome(char *s) {
  int n = strlen(s);
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - i - 1])
      return check(&s[i], n - 1 - 2 * i);
  return 1;
}

int main() {
  char *s1 = "aba", *s2 = "abca", *s3 = "abc";
  printf("%d\n", validPalindrome(s1)); // expect: 1
  printf("%d\n", validPalindrome(s2)); // expect: 1
  printf("%d\n", validPalindrome(s3)); // expect: 0
}
