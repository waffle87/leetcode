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
  uint16_t *t = (uint16_t *)(s);
  int cnt = 0, n = strlen(s);
  for (int i = 0; i < n / 2; i++)
    cnt += (1 & ((t[i] >> 8) ^ t[i]));
  return cnt;
}

int main() {
  char *s1 = "1001";
  char *s2 = "10";
  char *s3 = "0000";
  int r1 = minChanges(s1);
  int r2 = minChanges(s2);
  int r3 = minChanges(s3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 0);
}
