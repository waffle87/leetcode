// 1340. Jump Game V
#include "leetcode.h"

/*
 * given an array of integers 'arr' and an integer 'd'. in one step you can jump
 * from index 'i' to index 'i + x' where 'i + x < arr.length' and '0 < x <= d',
 * or 'i - x' where 'i - x >= 0' and '0 < x <= d'. in addition, you only jump
 * from index 'i' to index 'j' if 'arr[i] > arr[j]' and 'arr[i] > arr[k]' for
 * all indices 'k' between 'i' and 'j'. you can choose any index of the array
 * and start jumping. return the maximum number of indices you can visit.
 */

void dfs(int *arr, int id, int d, int n, int *f) {
  if (f[id] != -1)
    return;
  f[id] = 1;
  for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
    dfs(arr, i, d, n, f);
    if (f[i] + 1 > f[id])
      f[id] = f[i] + 1;
  }
  for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
    dfs(arr, i, d, n, f);
    if (f[i] + 1 > f[id])
      f[id] = f[i] + 1;
  }
}

int maxJumps(int *arr, int arrSize, int d) {
  int n = arrSize, *f = (int *)malloc(n * sizeof(int));
  memset(f, -1, n * sizeof(int));
  for (int i = 0; i < n; ++i)
    dfs(arr, i, d, n, f);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = fmax(ans, f[i]);
  free(f);
  return ans;
}

int main() {
  int a1[] = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
  int a2[] = {3, 3, 3, 3, 3};
  int a3[] = {7, 6, 5, 4, 3, 2, 1};
  int r1 = maxJumps(a1, ARRAY_SIZE(a1), 2);
  int r2 = maxJumps(a2, ARRAY_SIZE(a2), 3);
  int r3 = maxJumps(a3, ARRAY_SIZE(a3), 1);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 7);
}
