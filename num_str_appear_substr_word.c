// 1967. Number of Strings That Appear as Substrings in Word
#include "leetcode.h"

/*
 * given an array of strings 'patterns' and a string 'word', return the number
 * of strings in 'patterns' that exist as a substring in 'word'. a substring is
 * a contiguous sequence of characters within a string.
 */

int numOfStrings(char **patterns, int patternsSize, char *word) {
  int ans = 0;
  for (int i = 0; i < patternsSize; i++)
    if (strstr(word, patterns[i]))
      ans++;
  return ans;
}

int main() {
  char *p1[] = {"a", "abc", "bc", "d"}, *w1 = "abc";
  char *p2[] = {"a", "b", "c"}, *w2 = "aaaaabbbbb";
  char *p3[] = {"a", "a", "a"}, *w3 = "ab";
  int r1 = numOfStrings(p1, ARRAY_SIZE(p1), w1);
  int r2 = numOfStrings(p2, ARRAY_SIZE(p2), w2);
  int r3 = numOfStrings(p3, ARRAY_SIZE(p3), w3);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 3);
}
