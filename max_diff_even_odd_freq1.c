// 3442. Maximum Difference Between Even and Odd Frequency I
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters. your task
 * is to find the minimum difference 'diff = a1 - a2' between the frequency of
 * characters 'a1' and 'a2' in the string such that 'a1' has an odd frequency in
 * the string, and 'a2' has an even frequency in the string. return this maximum
 * difference.
 */

int maxDifference(char *s) {
  int *freq = (int *)calloc(26, sizeof(int)), n = strlen(s);
  for (int i = 0; i < n; i++)
    freq[s[i] - 'a']++;
  int max = INT_MIN, min = INT_MAX;
  for (int i = 0; i < 26; i++) {
    if (max < freq[i] && freq[i] % 2)
      max = freq[i];
    if (min > freq[i] && !(freq[i] % 2) && freq[i])
      min = freq[i];
  }
  free(freq);
  return max - min;
}

int main() {
  char *s1 = "aaaaabbc", *s2 = "abcabcab";
  printf("%d\n", maxDifference(s1)); // expect: 3
  printf("%d\n", maxDifference(s2)); // expect: 1
}
