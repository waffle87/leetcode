// 49. Group Anagrams
#include "leetcode.h"

/*
 * given an array of strings 'strs', group the anagrams together . you can
 * return the answer in any order. an anagram is a word or phrase formed by
 * rearranging the letters of a different word or phrase, typically using all
 * the original letters exactly once.
 */

int cmp_int(const void *a, const void *b) {
  int *arr1 = *(int **)a;
  int *arr2 = *(int **)b;
  if (arr1[2] == arr2[2])
    return arr1[1] - arr2[1];
  return arr1[2] - arr2[2];
}

int cmp_str(const void *a, const void *b) { return *(char *)a - *(char *)b; }

uint rshash(char *str) {
  uint a = 63689, b = 378551, hash = 0;
  while (*str) {
    hash = hash * a + (*str++);
    a *= b;
  }
  return hash & 0x7FFFFFFF;
}

int hash(char *s) {
  int n = strlen(s);
  char *tmp = malloc((n + 1) * sizeof(char));
  strcpy(tmp, s);
  qsort(tmp, n, sizeof(char), cmp_str);
  int res = rshash(tmp);
  free(tmp);
  return res;
}

char ***groupAnagrams(char **strs, int strs_size, int *return_size,
                      int **return_col_size) {
  int i, j;
  int **len_table = malloc(strs_size * sizeof(int *));
  for (i = 0; i < strs_size; i++) {
    len_table[i] = malloc(3 * sizeof(int));
    len_table[i][0] = i;
    len_table[i][1] = strlen(strs[i]);
    len_table[i][2] = hash(strs[i]);
  }
  qsort(len_table, strs_size, sizeof(int *), cmp_int);
  int l = len_table[0][1], cnt = 1, idx = 0;
  char ***ans = malloc(10000 * sizeof(char **));
  *return_col_size = malloc(10000 * sizeof(int));
  for (i = 1; i < strs_size; i++) {
    if (len_table[i][2] == len_table[i - 1][2])
      cnt++;
    else {
      l = len_table[i - 1][1];
      ans[idx] = malloc(cnt * sizeof(char *));
      return_col_size[0][idx] = cnt;
      for (int j = 0; j < cnt; j++) {
        ans[idx][j] = malloc((l + 1) * sizeof(char));
        strcpy(ans[idx][j], strs[len_table[i - 1 - j][0]]);
      }
      idx++;
      cnt = 1;
    }
  }
  ans[idx] = malloc(cnt * sizeof(char *));
  l = len_table[i - 1][1];
  return_col_size[0][idx] = cnt;
  for (int j = 0; j < cnt; j++) {
    ans[idx][j] = malloc((l + 1) * sizeof(char));
    strcpy(ans[idx][j], strs[len_table[i - 1 - j][0]]);
  }
  idx++;
  *return_size = idx;
  *return_col_size = realloc(*return_col_size, idx * sizeof(int));
  ans = realloc(ans, idx * sizeof(char **));
  return ans;
}
