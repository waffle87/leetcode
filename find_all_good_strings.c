// 1397. Find All Good Strings
#include "leetcode.h"

/*
 * given the strings 's1' and 's2' of size 'n' and the string 'evil', return the
 * number of good strings. a good string has size 'n', it is alphabetically
 * greater than or equal to 's1', it is alphabetically smaller or less than
 * 's2', and it does not contain the string 'evil' as a substring. since the
 * answer can be a huge number, return this modulo 10^9+7.
 */

static int mod = 1e9 + 7;

int count_good_strings(char *s, int n, char *evil, int m, long long *dp) {
  int sum = 0, i, k;
  for (i = 0; i <= n - m; ++i) {
    for (k = 0; k < m && s[i + k] == evil[k]; ++k)
      ;
    if (k == m) {
      for (int j = i + k - 1; j >= i; --j) {
        sum += (s[j] - 'a') * dp[n - j - 1];
        sum %= mod;
      }
      return sum - 1;
    }
    if (s[i + k] < evil[k])
      sum += (s[i] - 'a') * dp[n - i - 1];
    else
      sum += dp[n - i] - ('z' + 1 - s[i]) * dp[n - i - 1];
    sum %= mod;
  }
  for (; i < n; ++i) {
    sum += (s[i] - 'a') * dp[n - i - 1];
    sum %= mod;
  }
  return sum;
}

int findGoodStrings(int n, char *s1, char *s2, char *evil) {
  int m = strlen(evil), k = 0, i = 1;
  long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
  memset(dp, 0, m * sizeof(long long));
  while (i < m) {
    if (evil[k] == evil[i])
      dp[i++] = ++k;
    else if (k > 0)
      k = dp[k - 1];
    else
      ++i;
  }
  k = m - dp[m - 1];
  dp[0] = 1LL;
  for (i = 1; i < m; ++i)
    dp[i] = (dp[i - 1] * 26LL) % mod;
  for (; i <= n; ++i) {
    if (k == m) {
      dp[i] = (dp[i - 1] * 26LL) % mod;
      dp[i] -= dp[i - m];
    } else {
      dp[i] = ((dp[i - 1] + dp[i - k - 1]) * 26LL) % mod;
      dp[i] -= dp[i - m] + dp[i - k];
    }
  }
  int ans = count_good_strings(s2, n, evil, m, dp) -
            count_good_strings(s1, n, evil, m, dp);
  if (!strstr(s1, evil))
    ans++;
  if (ans < 0)
    ans += mod;
  return ans % mod;
}

int main() {
  char *s11 = "aa", *s21 = "da", *e1 = "b";
  char *s12 = "leetcode", *s22 = "leetgoes", *e2 = "leet";
  char *s13 = "gx", *s23 = "gz", *e3 = "x";
  printf("%d\n", findGoodStrings(2, s11, s21, e1)); // expect: 51
  printf("%d\n", findGoodStrings(8, s12, s22, e2)); // expect: 0
  printf("%d\n", findGoodStrings(2, s13, s23, e3)); // expect: 2
}
