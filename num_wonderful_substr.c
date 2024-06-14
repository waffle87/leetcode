// 1915. Number of Wonderful Substrings
#include "leetcode.h"

/*
 * a wonderful string is a string where at most one letter appears an odd number
 * of times. for example "ccjjc" and "abab" are wonderful, but "ab" is not.
 * given a string 'word' that consists of the first ten lowercase letters ('a'
 * through 'j') return the number of wonderful non-empty substrings in 'word'.
 * if the same substring appears multiple times in 'word', then count each
 * occurence separately. a substring is a contiguous sequence of character in a
 * string.
 */

long long wonderfulSubstrings(char *word) {
  int n = strlen(word), state = 0;
  int *cnt = (int *)calloc(1 << 10, sizeof(int));
  cnt[0] = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int k = word[i] - 'a';
    state ^= (1 << k);
    ans += cnt[state];
    for (int j = 0; j < 10; j++) {
      int j_state = state ^ (1 << j);
      ans += cnt[j_state];
    }
    cnt[state]++;
  }
  free(cnt);
  return ans;
}

int main() {
  char *w1 = "aba", *w2 = "aabb", *w3 = "he";
  printf("%lld\n", wonderfulSubstrings(w1)); // expect: 4
  printf("%lld\n", wonderfulSubstrings(w2)); // expect: 9
  printf("%lld\n", wonderfulSubstrings(w3)); // expect: 2
}
