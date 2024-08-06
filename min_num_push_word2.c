// 3016. Minimum Number of Pushes to Type Word II
#include "leetcode.h"

/*
 * you are given a string 'word' containing lowercase english letters. telephone
 * keypads have keys mapped with distinct collections of lowercase english
 * letters, which can be used to form words by pushing them. for example, the
 * key 2 is mapped with [a, b, c], we need to push the key one time to type 'a',
 * two times to type 'b', and three times to type 'c'. it is allowed to remap
 * the keys numbered 2 to 9 to distinct collections of letters. the keys can be
 * remapped to any amount of letters, but each letter must be mapped to exactly
 * one key. you need to find the minimum number of times the keys will be pushed
 * to type the string 'word'. return the minimum number of pushes needed to type
 * 'word' after remapping the keys.
 */

int cmp(const int *const a, const int *const b) { return -(*a - *b); }

int minimumPushes(char *word) {
  int *lower_freq = (int *)calloc(26, sizeof(int));
  for (int i = 0; word[i] != '\0'; i++) {
    assert(word[i] >= 'a' && word[i] <= 'z');
    lower_freq[word[i] - 'a']++;
  }
  qsort(lower_freq, 26, sizeof(int), &cmp);
  int ans = 0;
  for (int i = 1; 1; i++) {
    const int base_idx = 8 * (i - 1);
    for (int j = 0; j < 8; j++) {
      const int curr_idx = base_idx + j;
      if (!(curr_idx < 26 && lower_freq[curr_idx]))
        return ans;
      ans += i * lower_freq[curr_idx];
    }
  }
  free(lower_freq);
  return ans;
}

int main() {
  char *w1 = "abcde", *w2 = "xyzxyzxyzxyz", *w3 = "aabbccddeeffgghhiiiiii";
  printf("%d\n", minimumPushes(w1)); // expect: 5
  printf("%d\n", minimumPushes(w2)); // expect: 12
  printf("%d\n", minimumPushes(w3)); // expect: 24
}
