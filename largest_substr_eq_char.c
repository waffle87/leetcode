// 1624. Largest Substring Between Two Equal Characters
#include "leetcode.h"

/*
 * given a string 's', return the length of the longest substring between two
 * equal characters excluding the two characters if there is no such substring
 * return -1. a substring is a contiguous sequence of characters within a
 * string.
 */

int maxLengthBetweenEqualCharacters(char *s) {
  int n = strlen(s), max = -1;
  int *pre_alpha = calloc(26, sizeof(int));
  int *suff_alpha = calloc(26, sizeof(int));
  for (int i = 0; i < n; i++)
    if (!pre_alpha[s[i] - 'a'])
      pre_alpha[s[i] - 'a'] = i + 1;
  for (int i = n - 1; i >= 0; i--)
    if (!suff_alpha[s[i] - 'a'])
      suff_alpha[s[i] - 'a'] = i + 1;
  for (int i = 0; i < 26; i++)
    max = fmax(max, suff_alpha[i] - pre_alpha[i] - 1);
  free(pre_alpha), free(suff_alpha);
  return max;
}

int main() {
  char *s1 = "aa", *s2 = "abca", *s3 = "cbzxy";
  printf("%d\n", maxLengthBetweenEqualCharacters(s1)); // expect: 0
  printf("%d\n", maxLengthBetweenEqualCharacters(s2)); // expect: 2
  printf("%d\n", maxLengthBetweenEqualCharacters(s3)); // expect: -1
}
