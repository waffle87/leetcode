// 3713. Longest Balanced Substring I
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters. a
 * substring of 's' is called balanced if all distinct characters in the
 * substring appear the same number of times. return the length of the longest
 * balanced substring of 's'.
 */

int longestBalanced(char *s) {
  int n = strlen(s), ans = 0;
  for (int i = 0; i < n; i++) {
    int freq[26] = {0}, max = 0, cnt = 0;
    for (int j = i; j < n; j++) {
      int idx = s[j] - 'a';
      if (!freq[idx])
        cnt++;
      freq[idx]++;
      max = fmax(max, freq[idx]);
      int curr = j - i + 1;
      if (max * cnt == curr)
        ans = fmax(ans, curr);
    }
  }
  return ans;
}

int main() {
  char *s1 = "abbac", *s2 = "zzabccy", *s3 = "aba";
  int r1 = longestBalanced(s1);
  int r2 = longestBalanced(s2);
  int r3 = longestBalanced(s3);
  printf("%d\n", r1); // expect: 4
  assert(r1 == 4);
  printf("%d\n", r2); // expect: 4
  assert(r2 == 4);
  printf("%d\n", r3); // expect: 2
  assert(r3 == 2);
}
