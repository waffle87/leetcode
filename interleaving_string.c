// 97. Interleaving String
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given strings 's1', 's2', 's3', find whether 's3' is formed by an
 interleaving of 's1' and 's2'. an interleaving of two strings 's' and 't' isa
 configuration where 's' and 't' are divided into 'n' and 'm' substrings
 respectively, such that
    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
 t3 + s3 + ...
*/

bool isInterleave(char *s1, char *s2, char *s3) {
  int n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3);
  if (n1 + n2 != n3)
    return false;
  if (!n1) {
    if (!strcmp(s2, s3))
      return true;
    else
      return false;
  }
  if (!n2) {
    if (!strcmp(s1, s3))
      return true;
    else
      return false;
  }
  if (s3[n3 - 1] != s1[n1 - 1] && s3[n3 - 1] != s2[n2 - 1])
    return false;
  if (s3[0] != s1[0] && s3[0] != s2[0])
    return false;
  bool **dp = malloc((n1 + 1) * sizeof(bool *));
  for (int i = 0; i <= n1; i++)
    dp[i] = calloc(n2 + 1, sizeof(bool));
  dp[0][0] = true;
  for (int i = 1; i <= n1; i++)
    dp[i][0] = (dp[i - 1][0] == true && (s1[i - 1] == s3[i - 1]));
  for (int i = 1; i <= n2; i++)
    dp[0][i] = (dp[0][i - 1] == true && (s2[i - 1] == s3[i - 1]));
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j] == true)
        dp[i][j] = true;
      else if ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1] == true)
        dp[i][j] = true;
    }
  }
  return dp[n1][n2];
}

int main() {
  char s11[] = {"aabcc"}, s21[] = {"dbbca"}, s31[] = {"aadbbcbcac"};
  char s12[] = {"aabcc"}, s22[] = {"dbbca"}, s32[] = {"aadbbbaccc"};
  printf("%d\n", isInterleave(s11, s21, s31)); // expect: 1
  printf("%d\n", isInterleave(s12, s22, s32)); // expect: 0
}
