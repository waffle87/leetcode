// 1312. Minimum Insertion Steps to Make a String Palindrome
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given string 's'. in one step you can insert any character at any index of
 * the string. return the minimum number of steps to make 's' palindrome. a
 * palindrome string is one that reads the same backward as well as forward.
 */

int minInsertions(char *s) {
  int n = strlen(s);
  int **dp = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    dp[i] = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++)
    dp[i][i] = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1])
      dp[i][i + 1] = 2;
    else
      dp[i][i + 1] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      if (s[i] == s[j])
        dp[i][j] = 2 + dp[i + 1][j - 1];
      else
        dp[i][j] = fmax(dp[i + 1][j], dp[i][j - 1]);
    }
  }
  int ans = n - dp[0][n - 1];
  for (int i = 0; i < n; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  char s1[] = {"zzazz"}, s2[] = {"mbadm"}, s3[] = {"leetcode"};
  printf("%d\n", minInsertions(s1)); // expect: 0;
  printf("%d\n", minInsertions(s2)); // expect: 2;
  printf("%d\n", minInsertions(s3)); // expect: 5;
}
