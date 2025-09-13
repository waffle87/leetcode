// 3541. Find Most Frequent Vowel and Consonant
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters 'a' to
 * 'z'. your task is to find the vowel with the maximum frequency, and find the
 * consonant with the maximum frequency. return the sum of the two frequencies.
 * note if multiple vowels or consonants have the same maximum frequency, you
 * may choose any one of them. if there are no vowels or consonants in the
 * string, consider their frequency as 0.
 */

int maxFreqSum(char *s) {
  int freq[26] = {0}, n = strlen(s);
  for (int i = 0; i < n; i++)
    freq[s[i] - 'a']++;
  static const int mask = 1 + (1 << ('e' - 'a')) + (1 << ('i' - 'a')) +
                          (1 << ('o' - 'a')) + (1 << ('u' - 'a'));
  int max_v = 0, max_c = 0;
  for (int i = 0; i < 26; i++) {
    if (((1 << i) & mask))
      max_v = fmax(max_v, freq[i]);
    else
      max_c = fmax(max_c, freq[i]);
  }
  return max_v + max_c;
}

int main() {
  char *s1 = "successes", *s2 = "aeiaeia";
  printf("%d\n", maxFreqSum(s1)); // expect: 6
  printf("%d\n", maxFreqSum(s2)); // expect: 3
}
