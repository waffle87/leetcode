// 2486. Append Characters to String to Make Subsequence
#include "leetcode.h"

/*
 * given two strings 's' and 't' consisting of only lowercase english letters.
 * return the minimum number of characters that need to be appened to the end of
 * 's' so that 't' becomes a subsequence of 's'. a subsequence is a string that
 * can be derived from another string by deleting some or no characters without
 * changing the order of the remaining characters.
 */

int appendCharacters(char *s, char *t) {
  int ns = strlen(s), nt = strlen(t), p1 = 0, p2 = 0;
  while (p1 < ns && p2 < nt) {
    if (s[p1] == t[p2])
      p2++;
    p1++;
  }
  return nt - p2;
}

int main() {
  char *s1 = "coaching", *t1 = "coding", *s2 = "abcde", *t2 = "a", *s3 = "z",
       *t3 = "abcde";
  printf("%d\n", appendCharacters(s1, t1)); // expect: 4
  printf("%d\n", appendCharacters(s2, t2)); // expect: 0
  printf("%d\n", appendCharacters(s3, t3)); // expect: 5
}
