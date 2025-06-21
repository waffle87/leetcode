// 3085. Minimum Deletions to Make String K-Special
#include "leetcode.h"

/*
 * you are given a string 'word' and an integer 'k'. we consider 'word' to be
 * k-special if '|freq(word[i]) - freq(word[j])| <= k' for all indices 'i' and
 * 'j' in the string. here, 'freq(x)' denotes the frequency of the character 'x'
 * in the 'word'. and '|y|' denotes the absolute value of 'y'. return the
 * minimum number of characters you need to delete to make 'word' k-special.
 */

int minimumDeletions(char *word, int k) {
  int freq[26] = {0}, n = strlen(word), ans = INT_MAX;
  for (int i = 0; i < n; i++)
    freq[word[i] - 'a']++;
  for (int i = 0; i < 26; i++) {
    int curr = 0;
    for (int j = 0; j < 26; j++)
      curr += (freq[j] < freq[i]) ? freq[j] : fmax(0, freq[j] - (freq[i] + k));
    ans = fmin(ans, curr);
  }
  return ans;
}

int main() {
  char *w1 = "aabcaba", *w2 = "dabdcbdcdcd", *w3 = "aaabaaa";
  printf("%d\n", minimumDeletions(w1, 0)); // expect: 3
  printf("%d\n", minimumDeletions(w2, 2)); // expect: 2
  printf("%d\n", minimumDeletions(w3, 2)); // expect: 1
}
