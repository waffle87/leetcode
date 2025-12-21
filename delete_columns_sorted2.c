// 955. Delete Columns to Make Sorted II
#include "leetcode.h"

/*
 * you are given an array of 'n' strings 'strs' all of the same length. we may
 * choose any deletion indices and we delete all the characters in those indices
 * for each string. for example, if we have 'strs = [abcdef, uvwxyz]' and
 * deletion indices '1, 2, 3', then the final array after deletions is '[bef,
 * vyz]'. suppose we chose a set of deletion indices 'answer' such that after
 * deletions, the final array has its elements in lexographic order. return the
 * minimum possible value of 'ans.len'.
 */

int minDeletionSize(char **strs, int strsSize) {
  int n = strsSize, m = strlen(strs[0]);
  int unresolved = n - 1, ans = 0;
  bool *resolved = (bool *)calloc(n - 1, sizeof(int));
  for (int i = 0; i < m && unresolved > 0; i++) {
    bool need = false;
    for (int j = 0; j < n - 1; j++)
      if (!resolved[j] && strs[j][i] > strs[j + 1][i]) {
        need = true;
        break;
      }
    if (need) {
      ans++;
      continue;
    }
    for (int j = 0; j < n - 1; j++)
      if (!resolved[j] && strs[j][i] < strs[j + 1][i]) {
        resolved[j] = true;
        unresolved--;
      }
  }
  free(resolved);
  return ans;
}

int main() {
  char *s1[] = {"ca", "bb", "ac"};
  char *s2[] = {"xc", "yb", "za"};
  char *s3[] = {"zyx", "wvu", "tsr"};
  printf("%d\n", minDeletionSize(s1, ARRAY_SIZE(s1))); // expect: 1
  printf("%d\n", minDeletionSize(s2, ARRAY_SIZE(s2))); // expect: 0
  printf("%d\n", minDeletionSize(s3, ARRAY_SIZE(s3))); // expect: 3
}
