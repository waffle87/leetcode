// 3090. Maximum Length Substring With Two Occurrences
#include "leetcode.h"

/*
 * given a string 's', return the maximum length of a substring such that it
 * contains at most two occurences of each character.
 */

int maximumLengthSubstring(char *s) {
  int ans = 0, n = strlen(s);
  uint64_t mask = 0;
  for (int l = 0, r = 0; r < n; r++) {
    int k = (s[r] & 31) << 1;
    mask += 1ULL << k;
    while (((mask >> k) & 3) == 3)
      mask -= 1ULL << ((s[l++] & 31) << 1);
    ans = fmax(ans, r - l + 1);
  }
  return ans;
}

int main() {
  char *s1 = "bcbbbcba", *s2 = "aaaa";
  int r1 = maximumLengthSubstring(s1);
  int r2 = maximumLengthSubstring(s2);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 2);
}
