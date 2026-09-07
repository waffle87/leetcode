// 940. Distinct Subsequences II
#include "leetcode.h"

/*
 * given a string 's', return the number of distinct non-empty subsequences of
 * 's'. since the answer may be very large, return it modulo 10^9 + 7.
 */

int distinctSubseqII(char *s) {
  int ans = 0, add = 0, mod = 1e9 + 7;
  int n = strlen(s), end[26] = {0};
  for (int i = 0; i < n; i++) {
    add = (ans - end[s[i] - 'a'] + 1) % mod;
    ans = (ans + add) % mod;
    end[s[i] - 'a'] = (end[s[i] - 'a'] + add) % mod;
  }
  return (ans + mod) % mod;
}

int main() {
  char *s1 = "abc";
  char *s2 = "aba";
  char *s3 = "aaa";
  int r1 = distinctSubseqII(s1);
  int r2 = distinctSubseqII(s2);
  int r3 = distinctSubseqII(s3);
  printf("%d\n", r1);
  assert(r1 == 7);
  printf("%d\n", r2);
  assert(r2 == 6);
  printf("%d\n", r3);
  assert(r3 == 3);
}
