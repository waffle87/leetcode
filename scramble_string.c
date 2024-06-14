// 87. Scramble String
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * string 's' can be scrambled to get string 't' using the following algorithm:
 * if length of string is 1, exit
 * if lenght of string is > 1:
 *   split string into two non-empty substrings at random index
 *   randomly decide to swap two substrings or to keep them in same order
 *   apply step 1 recursively
 * given two strings 's1' and 's2' of the same length, return true if 's2' is a
 * scrambled string of 's1', otherwise return false
 */

bool prune(char *s1, char *s2, int len) {
  int cnt[256] = {0};
  for (int i = 0; i < len; i++) {
    cnt[s1[i] - 'a']++;
    cnt[s2[i] - 'a']--;
  }
  for (int i = 1; i < len; i++)
    if (prune(s1, s2, i) && prune(s1 + i, s2 + i, len - i) ||
        prune(s1, s2 + len - i, i) && prune(s1 + i, s2, len - i))
      return true;
  return false;
}

bool isScramble(char *s1, char *s2) {
  int len = strlen(s1);
  if (!strncmp(s1, s2, len))
    return false;
  return prune(s1, s2, len);
}

int main() {
  char s1_1[] = {"great"}, s2_1[] = {"rgeat"};
  char s1_2[] = {"abcde"}, s2_2[] = {"caebd"};
  char s1_3[] = {"a"}, s2_3[] = {"a"};
  printf("%d\n", isScramble(s1_1, s2_1)); // expect: 1
  printf("%d\n", isScramble(s1_2, s2_2)); // expect: 0
  printf("%d\n", isScramble(s1_3, s2_3)); // expect: 1
}
