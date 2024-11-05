// 2914. Minimum Number of Changes to Make Binary String Beautiful
#include "leetcode.h"

/*
 * you are given a 0-indexed binary string 's' having an even length. a string
 * is beautiful if it's possible to partition it into one or more substrings
 * such that each substring has an even length and each substring contains only
 * 1's or only 0's. you can change any character in 's' to a 0 or 1. return the
 * minimum number of changes required to make the string 's' beautiful.
 */

int minChanges(char *s) {
  int changes = 0;
  for (int i = 0; i < strlen(s); i += 2)
    if (s[i] != s[i + 1])
      changes++;
  return changes;
}

int main() {
  char *s1 = "1001", *s2 = "10", *s3 = "0000";
  printf("%d\n", minChanges(s1)); // expect: 2
  printf("%d\n", minChanges(s2)); // expect: 1
  printf("%d\n", minChanges(s3)); // expect: 0
}
