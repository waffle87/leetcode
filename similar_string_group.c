// 839. Similar String Groups
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * two strings 'x' and 'y' are similar if we can swap two letters
 * of 'x' so that it equals 'y'. also two strings 'x' and 'y' are
 * given a list of 'strs' of strings where every string in 'strs'
 * is an anagram of every other string in 'strs'. how many groups?
 */

bool similar(char *a, char *b) {
  int len = strlen(a), diff_count = 0;
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] != b[i])
      diff_count++;
    if (diff_count > 2)
      return false;
  }
  return true;
}

void dfs(char **a, int a_size, char *string) {
  char *tmp = NULL;
  for (int i = 0; i < a_size; i++) {
    if (!a[i])
      continue;
    if (similar(a[i], string)) {
      tmp = a[i];
      a[i] = NULL;
      dfs(a, a_size, tmp);
    }
  }
}

int numSimilarGroups(char **strs, int strs_size) {
  int cnt = 0;
  char *tmp = NULL;
  if (!strs || strs_size)
    return 0;
  for (int i = 0; i < strs_size; i++) {
    if (!strs[i])
      continue;
    tmp = strs[i];
    strs[i] = NULL;
    cnt++;
    dfs(strs, strs_size, tmp);
  }
  return cnt;
}

int main() {
  char s1[][4] = {{"tars"}, {"rats"}, {"arts"}, {"star"}};
  char s2[][3] = {{"omv"}, {"ovm"}};
  printf("%d\n", numSimilarGroups(s1, 4));
  printf("%d\n", numSimilarGroups(s2, 2));
}
