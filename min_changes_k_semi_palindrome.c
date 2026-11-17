// 2911. Minimum Changes to Make K Semi-palindromes
#include "leetcode.h"

int minimumChanges(char *s, int k) {
  int n = strlen(s);
  int **divisors = (int **)malloc((n + 1) * sizeof(int *));
  int *div_cnt = (int *)calloc(n + 1, sizeof(int));
  for (int d = 0; d <= n; d++)
    divisors[d] = (int *)malloc((n + 1) * sizeof(int));
  for (int d = 1; d <= n; d++)
    for (int v = 1; v < d; v++)
      if (!(d % v))
        divisors[d][div_cnt[d]++] = v;
  int **cost = (int **)malloc((n + 1) * sizeof(int *));
  for (int i = 0; i <= n; i++) {
    cost[i] = (int *)malloc((n + 1) * sizeof(int));
    for (int j = 0; j <= n; j++)
      cost[i][j] = INT_MAX;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int L = j - i + 1;
      int best = INT_MAX;
      for (int idx = 0; idx < div_cnt[L]; idx++) {
        int d = divisors[L][idx];
        int changes = 0;
        for (int start = i; start < i + d; start++) {
          int l = start;
          int r = start + ((j - start) / d) * d;
          while (l < r) {
            if (s[l] != s[r])
              changes++;
            l += d;
            r -= d;
          }
        }
        best = fmin(best, changes);
      }
      cost[i][j] = best;
    }
  }
  int **dp = (int **)malloc((k + 1) * sizeof(int *));
  for (int t = 0; t <= k; t++) {
    dp[t] = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
      dp[t][i] = INT_MAX;
  }
  dp[0][0] = 0;
  for (int t = 1; t <= k; t++)
    for (int i = t; i <= n; i++)
      for (int j = t - 1; j < i; j++)
        if (dp[t - 1][j] < INT_MAX && cost[j][i - 1] < INT_MAX) {
          int candidate = dp[t - 1][j] + cost[j][i - 1];
          dp[t][i] = fmin(dp[t][i], candidate);
        }
  int ans = dp[k][n];
  for (int d = 0; d <= n; d++)
    free(divisors[d]);
  free(divisors);
  free(div_cnt);
  for (int i = 0; i <= n; i++)
    free(cost[i]);
  free(cost);
  for (int t = 0; t <= k; t++)
    free(dp[t]);
  free(dp);
  return ans;
}

int main() {
  char *s1 = "abcac";
  char *s2 = "abcdef";
  char *s3 = "aabbaa";
  int r1 = minimumChanges(s1, 2);
  int r2 = minimumChanges(s2, 2);
  int r3 = minimumChanges(s3, 3);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 0);
}
