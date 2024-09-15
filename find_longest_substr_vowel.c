// 1371. Find the Longest Substring Containing Vowels in Even Counts
#include "leetcode.h"

/*
 * given the string 's', return the size of the longest substring containing
 * each value an even number of times. that is 'a, e, i, o, u' must appear an
 * even number of times.
 */

#define FLIP(map, idx) ((map) ^ ((1) << (idx)))

int vowel_idx(char vowel) {
  switch (vowel) {
  case 'a':
    return 1;
  case 'e':
    return 2;
  case 'i':
    return 3;
  case 'o':
    return 4;
  case 'u':
    return 5;
  default:
    return 0;
  }
}

int findTheLongestSubstring(char *s) {
  int n = strlen(s), memo[64] = {[0 ... 63] = -1}, curr = 0, max = 0;
  unsigned char map = 0;
  for (int i = 0; i < n; i++) {
    map = FLIP(map, vowel_idx(*(s + i))) & -2;
    if (map && *(memo + map) < 0)
      *(memo + map) = i;
    curr = i - *(memo + map);
    max = curr >= max ? curr : max;
  }
  return max;
}

int main() {
  char *s1 = "eleetminicoworoep", *s2 = "leetcodeisgreate", *s3 = "bcbcbc";
  printf("%d\n", findTheLongestSubstring(s1)); // expect: 13
  printf("%d\n", findTheLongestSubstring(s2)); // expect: 5
  printf("%d\n", findTheLongestSubstring(s3)); // expect: 6
}
