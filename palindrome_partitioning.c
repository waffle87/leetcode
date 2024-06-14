// 131. Palindrome Partitioning
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given: string 's', parition 's' such that every substring of the parition
 * is a palindrome. return all possible palindrome paritioning of 's'.
 */

bool isPalindrome(char *s, int end) {
  if (end < 0)
    return false;
  int start = 0;
  while (end > start) {
    if (s[start] != s[end])
      return false;
    start++;
    end--;
  }
  return true;
}

void dfs(char *s, char ***ret, int **cols, int *retColSz, char **curr, int k) {
  if (*s == 0) {
    ret[*retColSz] = (char **)malloc(sizeof(char *) * k);
    for (int i = 0; i < k; i++) {
      ret[*retColSz][i] = (char *)malloc(strlen(curr[i]) + 1);
      strcpy(ret[*retColSz][i], curr[i]);
    }
    (*cols)[(*retColSz)++] = k;
    return;
  }
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (isPalindrome(s, i)) {
      strncpy(curr[k], s, i + 1);
      curr[k][i + 1] = '\0';
      dfs(s + i + 1, ret, cols, retColSz, curr, k + 1);
    }
  }
}

char ***partition(char *s, int **returnSize, int *returnColumnSizes) {
  *returnColumnSizes = 0;
  if (s == NULL || !strcmp(s, ""))
    return NULL;
  *returnSize = (int *)malloc(sizeof(int) * 500);
  char ***ans = (char ***)malloc(sizeof(char ***) * 500);
  int len = strlen(s) + 1;
  char **curr = (char **)malloc(sizeof(char *) * 500);
  for (int i = 0; i < 500; i++)
    curr[i] = (char *)malloc(len);
  dfs(s, ans, returnSize, returnColumnSizes, curr, 0);
}
