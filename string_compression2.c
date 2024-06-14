// 1531. String Compression II
#include "leetcode.h"

/*
 * run-length encoding is a string compression method that works by replacing
 * consecutive identical characters (repeated 2 or more times) with the
 * concatenation of the characters and the number marking the count of the
 * characters (length of run). for example tocompress the string "aabccc", we
 * replace "aa" by "a2" and replace "ccc" by "c3". thus the compressed string
 * becomes "a2bc3". notice that in this problem we are not adding '1' after
 * single characters. given a string 's' and an integer 'k'. you needed to
 * delete at most 'k' characters from 's' such that the run-length encoded
 * version of 's' has minimum length. find the minimum length of the run-length
 * encoded version of 's' after deleting at most 'k' characters
 */

int dp[101][101];
int dfs(char *s, int left, int k) {
  int j = k;
  if (strlen(s) - left <= j)
    return 0;
  if (dp[left][j] >= 0)
    return dp[left][j];
  int res = j ? dfs(s, left + 1, k - 1) : 100, c = 1;
  for (int i = left + 1; i <= strlen(s); ++i) {
    res = fmin(res, dfs(s, i, j) + 1 +
                        (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 : 0))));
    if (i == strlen(s))
      break;
    if (s[i] == s[left])
      ++c;
    else if (--k < 0)
      break;
  }
  return dp[left][k] = res;
}

int getLengthOfOptimalCompression(char *s, int k) {
  memset(dp, -1, sizeof(dp));
  return dfs(s, 0, k);
}

int main() {
  char *s1 = "aaabcccd", *s2 = "aabbaa", *s3 = "aaaaaaaaaaa";
  printf("%d\n", getLengthOfOptimalCompression(s1, 2)); // expect: 4
  printf("%d\n", getLengthOfOptimalCompression(s2, 2)); // expect: 2
  printf("%d\n", getLengthOfOptimalCompression(s3, 0)); // expect: 0
}
