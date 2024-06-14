// 712. Minimum ASCII Delete Sum for Two Strings
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 's1' and 's2', return the lowest ascii sum of the deleted
 * characters to make two strings equal
 */

int minimumDeleteSum(char *s1, char *s2) {
  int n = strlen(s1), m = strlen(s2), i, j;
  int **dp = (int **)malloc((n + 1) * sizeof(int *));
  for (int i = 0; i <= n; i++)
    dp[i] = (int *)malloc((m + 1) * sizeof(int));
  dp[0][0] = 0;
  for (i = 1; i <= m; i++)
    dp[0][i] = dp[0][i - 1] + s2[i - 1];
  for (i = 1; i <= n; i++)
    dp[i][0] = dp[i - 1][0] + s1[i - 1];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = fmin(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
    }
  int ans = dp[n][m];
  for (i = 0; i <= n; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  char s11[] = {"sea"}, s21[] = {"eat"};
  char s12[] = {"delete"}, s22[] = {"leet"};
  printf("%d\n", minimumDeleteSum(s11, s21)); // expect: 231
  printf("%d\n", minimumDeleteSum(s12, s22)); // expect: 403
}
