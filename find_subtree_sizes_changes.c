// 3331. Find Subtree Sizes After Changes
#include "leetcode.h"

int dfs(int node, char *s, int *head, int *next, int *ans, int *letters) {
  int c = s[node] - 'a';
  int above = letters[c];
  letters[c] = node;
  for (int child = head[node]; child != -1; child = next[child]) {
    int x = dfs(child, s, head, next, ans, letters);
    ans[node] += x;
  }
  letters[c] = above;
  if (above != -1) {
    ans[above] += ans[node];
    return 0;
  } else
    return ans[node];
}

int *findSubtreeSizes(int *parent, int parentSize, char *s, int *returnSize) {
  int n = parentSize, letters[26];
  memset(letters, -1, sizeof(letters));
  int *head = (int *)malloc(n * sizeof(int));
  int *next = (int *)malloc(n * sizeof(int));
  int *ans = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    ans[i] = 1;
    head[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    next[i] = head[parent[i]];
    head[parent[i]] = i;
  }
  dfs(0, s, head, next, ans, letters);
  free(head);
  free(next);
  *returnSize = n;
  return ans;
}

int main() {
  int p1[] = {-1, 0, 0, 1, 1, 1};
  int r1[] = {6, 3, 1, 1, 1, 1}, rs1;
  int p2[] = {-1, 0, 4, 0, 1};
  int r2[] = {5, 2, 1, 1, 1}, rs2;
  char *s1 = "abaabc";
  char *s2 = "abbba";
  int *fss1 = findSubtreeSizes(p1, ARRAY_SIZE(p1), s1, &rs1);
  int *fss2 = findSubtreeSizes(p2, ARRAY_SIZE(p2), s2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", fss1[i]);
    assert(fss1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", fss2[i]);
    assert(fss2[i] == r2[i]);
  }
  printf("\n");
  free(fss1);
  free(fss2);
}
