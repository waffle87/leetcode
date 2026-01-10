// 712. Minimum ASCII Delete Sum for Two Strings
#include "leetcode.h"

/*
 * given two strings 's1' and 's2', return the lowest ascii sum of the deleted
 * characters to make two strings equal
 */

int minimumDeleteSum(char *s1, char *s2) {
  int n = strlen(s1), m = strlen(s2);
  int *dp = (int *)malloc((m + 1) * sizeof(int));
  for (int i = 1; i <= m; i++)
    dp[i] = dp[i - 1] + s2[i - 1];
  for (int i = 1; i <= n; i++) {
    int t1 = dp[0];
    dp[0] += s1[i - 1];
    for (int j = 1; j <= n; j++) {
      int t2 = dp[j];
      if (s1[i - 1] == s2[j - 1])
        dp[j] = t1;
      else
        dp[j] = fmin(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
      t1 = t2;
    }
  }
  int ans = dp[m];
  free(dp);
  return ans;
}

int main() {
  char *s11 = "sea", *s21 = "eat";
  char *s12 = "delete", *s22 = "leet";
  printf("%d\n", minimumDeleteSum(s11, s21)); // expect: 231
  printf("%d\n", minimumDeleteSum(s12, s22)); // expect: 403
}
