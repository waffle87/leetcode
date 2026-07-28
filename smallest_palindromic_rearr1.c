// 3517. Smallest Palindromic Rearrangement I
#include "leetcode.h"

/*
 * you are given a palindromic string 's'. return the lexicographically smallest
 * palindromic permutation of 's'.
 */

char *smallestPalindrome(char *s) {
  int n = strlen(s), j = 0;
  int freq[26] = {};
  for (int i = 0; i < n >> 1; i++)
    freq[(s[i] & 31) - 1]++;
  for (int i = 0; i < 26; i++)
    while (freq[i]--) {
      s[j] = i + 'a';
      s[n - 1 - j++] = i + 'a';
    }
  return s;
}

int main() {
  char *s1 = "z", *r1 = "z";
  char *s2 = "babab", *r2 = "abbba";
  char *s3 = "daccad", *r3 = "acddca";
  char *sp1 = smallestPalindrome(s1);
  char *sp2 = smallestPalindrome(s2);
  char *sp3 = smallestPalindrome(s3);
  printf("%s\n", sp1);
  assert(!strcmp(sp1, r1));
  printf("%s\n", sp2);
  assert(!strcmp(sp2, r2));
  printf("%s\n", sp3);
  assert(!strcmp(sp3, r3));
}
