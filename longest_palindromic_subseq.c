// 516. Longest Palindromic Subsequence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given string 's', find the longest palindromic susbsequences
 * of ngth in 's'. a subsequcnes is a sequence that can be derived
 * from another sequence by deleting some or no elements without
 * changing the order of the remaining elements
 */

#define MAX(a, b) (a > b ? a : b)

int longestPalindromeSubseq(char *s) {
  int i, j, n = strlen(s);
  if (n <= 1)
    return n;
  int **dp = (int **)malloc(sizeof(int *) * n);
  for (i = 0; i < n; i++) {
    dp[i] = (int *)calloc(sizeof(int), n);
    for (j = 0; j < n; j++)
      dp[i][i] = 1;
  }
  for (i = n - 1; i >= 0; i--) {
    for (j = i + 1; j < n; j++) {
      if (s[i] == s[j])
        dp[i][j] = dp[i + 1][j - 1] + 2;
      else
        dp[i][j] = MAX(dp[i + 1][j], dp[i][j - 1]);
    }
  }
  return dp[0][n - 1];
}

int main() {
  char s1[] = {"bbbab"}, s2[] = {"cbbd"};
  printf("%d\n", longestPalindromeSubseq(s1)); // expect: 4
  printf("%d\n", longestPalindromeSubseq(s2)); // expect: 2
}
