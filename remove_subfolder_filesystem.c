// 1233. Remove Sub-Folders from the Filesystem
#include "leetcode.h"

/*
 * given a list of folders 'folder', return the folders after removing all the
 * sub-folders in those folders. you may return the answer in any order. if a
 * 'folder[i]' is located within another 'folder[j]', it is called a sub-folder
 * of it. a sub-folder of 'folder[j]' must start with 'folder[j]', followed by
 * '/'. the format of a path is one ormore concatenated strings of the form: '/'
 * followed by one or more lowercase english letters.
 */

int cmp(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

char **removeSubfolders(char **folder, int folderSize, int *returnSize) {
  qsort(folder, folderSize, sizeof(char *), cmp);
  char **ans = (char **)malloc(folderSize * sizeof(char *));
  int curr = strlen(folder[0]);
  ans[0] = folder[0];
  *returnSize = 1;
  for (int i = 1; i < folderSize; i++) {
    int new = strlen(folder[i]);
    if (new <= curr || folder[i][curr] != '/' ||
        strncmp(ans[*returnSize - 1], folder[i], curr)) {
      curr = new;
      ans[*returnSize] = folder[i];
      (*returnSize)++;
    }
  }
  return ans;
}

int main() {
  char *f1[] = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  char *f2[] = {"/a", "/a/b/c", "/a/b/d"};
  char *f3[] = {"/a/b/c", "/a/b/ca", "/a/b/d"};
  int rs1, rs2, rs3;
  char **rsf1 = removeSubfolders(f1, ARRAY_SIZE(f1), &rs1);
  char **rsf2 = removeSubfolders(f2, ARRAY_SIZE(f2), &rs2);
  char **rsf3 = removeSubfolders(f3, ARRAY_SIZE(f3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%s ", rsf1[i]); // expect: ["/a","/c/d","/c/f"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", rsf2[i]); // expect: ["/a"]
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%s ", rsf3[i]); // expect: ["/a/b/c","/a/b/ca","/a/b/d"]
  printf("\n");
  free(rsf1);
  free(rsf2);
  free(rsf3);
}
