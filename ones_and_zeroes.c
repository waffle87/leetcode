// 474. Ones and Zeroes
#include "leetcode.h"

/*
 * you are given an array of binary strings 'strs', and two integers 'm' and
 * 'n'. return the size of the largest subset of 'strs' such that there are at
 * most 'm' 0's and 'n' 1's in the subset. a set 'x' is a subset of a set 'y' if
 * all elements of 'x' are also elements of 'y'.
 */

int findMaxForm(char **strs, int strsSize, int m, int n) {
  int *dp = (int *)calloc((m + 1) * (n + 1), sizeof(int));
  for (int i = 0; i < strsSize; i++) {
    int zeroes = 0, ones = 0;
    for (int j = 0; strs[i][j]; ++j) {
      if (strs[i][j] == '0')
        zeroes++;
      else
        ones++;
    }
    for (int j = m; j >= zeroes; --j)
      for (int k = n; k >= ones; --k) {
        int idx = j * (n + 1) + k;
        int prev = (j - zeroes) * (n + 1) + (k - ones);
        if (dp[idx] < dp[prev] + 1)
          dp[idx] = dp[prev] + 1;
      }
  }
  int ans = dp[m * (n + 1) + n];
  free(dp);
  return ans;
}

int main() {
  char *s1[] = {"10", "0001", "111001", "1", "0"}, *s2[] = {"10", "0", "1"};
  printf("%d\n", findMaxForm(s1, ARRAY_SIZE(s1), 5, 3)); // expect: 4
  printf("%d\n", findMaxForm(s2, ARRAY_SIZE(s2), 1, 1)); // expect: 2
}
