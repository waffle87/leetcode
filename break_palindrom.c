// 1328. Break a Palindrome
#include "leetcode.h"

/*
 * given a palindrome string of lowercase english letters 'palindrome' replace
 * exactly one character with any lowercase english letter so that the resulting
 * string is not a palindrome and that it is the lexicographically smallest one
 * possible. return the resulting string. if there is no way to replace a
 * character to make it not a palindrome, return an empty string.
 */

char *breakPalindrome(char *palindrome) {
  int n = strlen(palindrome);
  for (int i = 0; i < n / 2; ++i)
    if (palindrome[i] != 'a') {
      palindrome[i] = 'a';
      return palindrome;
    }
  palindrome[n - 1] = 'b';
  return n < 2 ? "" : palindrome;
}

int main() {
  char p1[] = "abccba", p2[] = "a";
  printf("%s\n", breakPalindrome(p1)); // expect: aaccba
  printf("%s\n", breakPalindrome(p2)); // expect: null
}
