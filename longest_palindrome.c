// 409. Longest Palindrome
#include "leetcode.h"

/*
 * given a sting 's' which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 * letters are case sensitive for example "Aa" is not considered a palindrome
 */

int longestPalindrome(char *s) {
  static int freq[128];
  int mirror = 0, centre = 0;
  memset(freq, 0, sizeof(freq));
  while (*s != '\0')
    ++freq[*s++];
  for (int i = 0; i < 128; ++i) {
    mirror += freq[i] / 2;
    centre |= freq[i] & 1;
  }
  return mirror * 2 + centre;
}

int main() {
  char *s1 = "abccccdd", *s2 = "a";
  printf("%d\n", longestPalindrome(s1)); // expect: 7
  printf("%d\n", longestPalindrome(s2)); // expect: 1
}
