// 2370. Longest Ideal Subsequence
#include "leetcode.h"

/*
 * given a string 's' consisting of lowercase letters and an integer 'k', we
 * call a string 't' ideal if the following conditions are satisfied. 't' is a
 * subsequence of the string 's'. the absolute difference in the alphabet order
 * of every two adjacent letters in 't' is less than or equal to 'k'. return the
 * length of the longest ideal sting. a subsequence is a string that can be
 * derived from another string by deleting some or no characters without
 * changing the order of the remaining characters. note that the alphabet order
 * is not cyclic. for example, the absolute difference in the alphabet order of
 * 'a' and 'z' is 25, not 1.
 */

int longestIdealString(char *s, int k) {
  int n = strlen(s), ans = 0;
  int *dp = (int *)malloc(n * sizeof(int));
  int *prev = (int *)malloc(26 * sizeof(int));
  for (int i = 0; i < n; i++)
    dp[i] = 1;
  for (int i = 0; i < 26; i++)
    prev[i] = -1;
  for (int i = 0; i < n; i++) {
    for (int j = fmax(0, s[i] - 'a' - k); j <= fmin(25, s[i] - 'a' + k); j++)
      if (prev[j] != -1)
        dp[i] = fmax(dp[i], 1 + dp[prev[j]]);
    prev[s[i] - 'a'] = i;
    ans = fmax(ans, dp[i]);
  }
  return ans;
}

int main() {
  char *s1 = "acfgbd", *s2 = "abcd";
  printf("%d\n", longestIdealString(s1, 2)); // expect: 4
  printf("%d\n", longestIdealString(s2, 4)); // expect: 4
}
