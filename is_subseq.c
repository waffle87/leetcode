// 392. Is Subsequence
#include <stdbool.h>
#include <stdio.h>

/*
 * given two strings 's' and 't', return 'true' if 's' is a subsequnce of 't' or
 * 'false' otherwise. a subsequnce of a string is a new string that is formed
 * from the original string by deleting some (can be none) of the characters
 * without disturbing the relative positions of the remaining characters (ie.
 * "ace" is a subsequnce of "abcde", while "aec" is not).
 */

bool isSubsequence(char *s, char *t) {
  int s_idx = 0, t_idx = 0;
  while (s[s_idx] != '\0') {
    while ((t[t_idx] != '\0') & (t[t_idx] != s[s_idx]))
      t_idx++;
    if (t[t_idx] == '\0')
      return false;
    t_idx++;
    s_idx++;
  }
  return true;
}

int main() {
  char s1[] = {"abc"}, s2[] = {"axc"};
  char t1[] = {"ahbgdc"}, t2[] = {"ahbgdc"};
  printf("%d\n", isSubsequence(s1, t1)); // expect: 1
  printf("%d\n", isSubsequence(s2, t2)); // expect: 0
}
