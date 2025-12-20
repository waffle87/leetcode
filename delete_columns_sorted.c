// 944. Delete Columns to Make Sorted
#include "leetcode.h"

/*
 * you are given an array of 'n' strings 'strs', all of the same length. the
 * strings can be arranged such that there is one on each line, making a grid.
 * you want to delete the columns that are not sorted lexicographically. return
 * the number of columns that you will delete.
 */

int minDeletionSize(char **strs, int strsSize) {
  int ans = 0, n = strlen(strs[0]);
  for (int j = 0; j < n; j++)
    for (int i = 0; i < strsSize - 1; i++)
      if (strs[i][j] > strs[i + 1][j]) {
        ans++;
        break;
      }
  return ans;
}

int main() {
  char *s1[] = {"cba", "daf", "ghi"};
  char *s2[] = {"a", "b"};
  char *s3[] = {"zyx", "wvu", "tsr"};
  printf("%d\n", minDeletionSize(s1, ARRAY_SIZE(s1))); // expect: 1
  printf("%d\n", minDeletionSize(s2, ARRAY_SIZE(s2))); // expect: 0
  printf("%d\n", minDeletionSize(s3, ARRAY_SIZE(s3))); // expect: 3
}
