// 1092. Shortest Common Supersequence
#include "leetcode.h"

/*
 * given two strings 'str1' and 'str2', return the shortest string that has both
 * str1 and str2 as subsequences. if there are multiple valid strings, return
 * any of them. a string 's' is a supersequence if string 't' if deleting some
 * number of characters from 't' (possibly 0) results in string 's'.
 */

void reverse(char *s) {
  int n = strlen(s);
  for (int i = 0; i < n / 2; i++) {
    char tmp = s[i];
    s[i] = s[n - 1 - i];
    s[n - 1 - i] = tmp;
  }
}

char *shortestCommonSupersequence(char *s1, char *s2) {
  int m = strlen(s1), n = strlen(s2);
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++) {
      if (!i)
        dp[i][j] = j;
      else if (!j)
        dp[i][j] = i;
      else if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + fmin(dp[i - 1][j], dp[i][j - 1]);
    }
  char *ans = calloc(4000, sizeof(char));
  int idx = 0, i = m, j = n;
  while (i && j) {
    if (s1[i - 1] == s2[j - 1]) {
      ans[idx++] = s1[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      ans[idx++] = s2[j - 1];
      j--;
    } else {
      ans[idx++] = s1[i - 1];
      i--;
    }
  }
  while (i)
    ans[idx++] = s1[i - 1], i--;
  while (j)
    ans[idx++] = s2[j - 1], j--;
  reverse(ans);
  return ans;
}

int main() {
  char *s11 = "abac", *s21 = "cab", *s12 = "aaaaaaaa", *s22 = "aaaaaaaa";
  printf("%s\n", shortestCommonSupersequence(s11, s21)); // expect: cabac
  printf("%s\n", shortestCommonSupersequence(s12, s22)); // expect: aaaaaaaa
}
