// 2981. Find Longest Special Substring That Occurs Thrice I
#include "leetcode.h"

/*
 * you are given a string 's' that consists of lowercase english letters. a
 * string is called special if it is made up of only a single character. for
 * example, the string 'abc' is not special, whereas the strongs 'ddd', 'zz',
 * and 'f' are special. return the length of the longest special substring of
 * 's' which occrs at least thrice, or -1 if no special substring occrs at least
 * thrice. a substring is a contiguous non-empty sequence of characters within a
 * string
 */

bool helper(char *s, int n, int x) {
  int cnt[26] = {0}, c = 0;
  for (int i = 0; i < n; i++) {
    while (s[c] != s[i])
      c++;
    if (i - c + 1 >= x)
      cnt[s[i] - 'a']++;
    if (cnt[s[i] - 'a'] > 2)
      return true;
  }
  return false;
}

int maximumLength(char *s) {
  int n = strlen(s), l = 1, r = n;
  if (!helper(s, n, l))
    return -1;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (helper(s, n, m))
      l = m;
    else
      r = m;
  }
  return l;
}

int main() {
  char *s1 = "aaaa", *s2 = "abcdef", *s3 = "abcaba";
  printf("%d\n", maximumLength(s1)); // expect: 2
  printf("%d\n", maximumLength(s2)); // expect: -1
  printf("%d\n", maximumLength(s3)); // expect: 1
}
