// 115. Distinct Subsequences
#include "leetcode.h"

/*
 * given two strings 's' and 't', return the number of distinct subsequences of
 * 's' which equals 't'. the test cases are generated so that the answer fits in
 * a 32-bit signed integer.
 */

int numDistinct(char *s, char *t) {
  int m = strlen(s), n = strlen(t);
  unsigned long long *dp =
      (unsigned long long *)calloc(n + 1, sizeof(unsigned long long));
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    int end = i < n ? i : n;
    for (int j = end; j >= 1; j--)
      if (s[i - 1] == t[j - 1])
        dp[j] += dp[j - 1];
  }
  int ans = (int)dp[n];
  free(dp);
  return ans;
}

int main() {
  char *s1 = "rabbbit", *t1 = "rabbit";
  char *s2 = "babgbag", *t2 = "bag";
  int r1 = numDistinct(s1, t1);
  int r2 = numDistinct(s2, t2);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 5);
}
