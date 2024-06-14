// 424. Longest Repeating Character Replacement
#include "leetcode.h"

/*
 * given a string 's' and an integer 'k'. you can choose any character of the
 * string and change it to any other uppercase english character. you can
 * perform this operation at most 'k' times. return the length of the longest
 * substring containing the same letter you can get after performing the above
 * operations.
 */

int characterReplacement(char *s, int k) {
  int n = strlen(s), left = 0, right = 0, max_cnt = 0;
  int *freq = calloc(26, sizeof(int));
  while (right < n) {
    freq[s[right] - 'A']++;
    max_cnt = fmax(max_cnt, freq[s[right] - 'A']);
    right++;
    if (right - left > max_cnt + k) {
      freq[s[left] - 'A']--;
      left++;
    }
  }
  free(freq);
  return right - left;
}

int main() {
  char s1[] = {"ABAB"}, s2[] = {"AABABBA"};
  printf("%d\n", characterReplacement(s1, 2)); // expect: 4
  printf("%d\n", characterReplacement(s2, 1)); // expect: 4
}
