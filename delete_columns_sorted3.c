// 960. Delete Columns to Make Sorted III
#include "leetcode.h"

/*
 * you are given an array of 'n' strings 'strs', all of the same length. we may
 * choose any deletion indices and we delete all the characters in those indices
 * for each string. suppose we chose a set of deletion indices 'answer' such
 * that after deletions, the final array has every string (row) in lexicographic
 * order. return the minimum possible value of 'ans.length'.
 */

int minDeletionSize(char **strs, int strsSize) {
  int n = strlen(strs[0]), *dp = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    dp[i] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      bool valid = true;
      for (int k = 0; k < strsSize; k++)
        if (strs[k][j] > strs[k][i]) {
          valid = false;
          break;
        }
      if (valid && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    }
  }
  int max = 0;
  for (int i = 0; i < n; i++)
    max = fmax(max, dp[i]);
  free(dp);
  return n - max;
}

int main() {
  char *s1[] = {"babca", "bbazb"};
  char *s2[] = {"edcba"};
  char *s3[] = {"ghi", "def", "abc"};
  printf("%d\n", minDeletionSize(s1, ARRAY_SIZE(s1))); // expect: 3
  printf("%d\n", minDeletionSize(s2, ARRAY_SIZE(s2))); // expect: 4
  printf("%d\n", minDeletionSize(s3, ARRAY_SIZE(s3))); // expect: 0
}
