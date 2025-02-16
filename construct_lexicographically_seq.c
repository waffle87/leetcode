// 1718. Construct the Lexicographically Largest Valid Sequence
#include "leetcode.h"

/*
 * given an integer 'n', find a sequence that satisfies all of the following:
 * the integer '1' occurs once in the sequence, each integer between '2' and 'n'
 * occurs twice in the sequence, and for every integer 'i' between '2' and 'n',
 * the distance between the two occurence of 'i' is exactly 'i'. the distance
 * between two numbers on the sequence, 'a[i]' and 'a[j]' is the absolute
 * difference of their indices '|j - i|'.
 */

bool dfs(int *arr, int n, int idx, bool *vis, int max) {
  if (idx >= n)
    return true;
  int next;
  while (arr[idx])
    idx++;
  for (int i = max; i >= 1; i--) {
    next = max;
    if (i != 1 && idx + i >= n)
      return false;
    if (vis[i] || (i != 1 && arr[idx + i]))
      continue;
    vis[i] = true;
    arr[idx] = i;
    if (i != 1)
      arr[idx + i] = i;
    if (i == max)
      while (vis[--next])
        ;
    if (!next)
      return true;
    if (dfs(arr, n, idx + 1, vis, next))
      return true;
    vis[i] = false;
    arr[idx] = 0;
    if (i != 1)
      arr[idx + i] = 0;
  }
  return false;
}

int *constructDistancedSequence(int n, int *returnSize) {
  int m = 2 * n - 1;
  bool vis[24] = {0};
  int *ans = (int *)calloc(m, sizeof(int));
  dfs(ans, m, 0, vis, n);
  (*returnSize) = m;
  return ans;
}

int main() {
  int rs1, *cds1 = constructDistancedSequence(3, &rs1);
  int rs2, *cds2 = constructDistancedSequence(5, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", cds1[i]); // expect: 3 1 2 3 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", cds2[i]); // expect: 5 3 1 4 3 5 2 4 2
  printf("\n");
  free(cds1), free(cds2);
}
