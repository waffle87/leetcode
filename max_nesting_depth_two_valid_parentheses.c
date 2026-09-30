// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
#include "leetcode.h"

int *maxDepthAfterSplit(char *seq, int *returnSize) {
  int n = strlen(seq), level = 0, idx = 0;
  int *ans = (int *)calloc(n, sizeof(int));
  *returnSize = n;
  while (idx < n) {
    if (seq[idx] == '(')
      ans[idx] = ++level % 2;
    else
      ans[idx] = level-- % 2;
    idx++;
  }
  return ans;
}

int main() {
  char *s1 = "(()())";
  char *s2 = "()(())()";
  int r1[] = {1, 0, 0, 0, 1}, rs1;
  int r2[] = {1, 1, 1, 0, 0, 1, 1, 1}, rs2;
  int *mdas1 = maxDepthAfterSplit(s1, &rs1);
  int *mdas2 = maxDepthAfterSplit(s2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", mdas1[i]);
    assert(mdas1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", mdas2[i]);
    assert(mdas2[i] == r2[i]);
  }
  printf("\n");
  free(mdas1);
  free(mdas2);
}
