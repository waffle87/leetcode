// 3310. Remove Methods From Project
#include "leetcode.h"

/*
 * you are maintaining a project that has 'n' methods numbered from 0 to 'n -
 * 1'. you are given two integers 'k' and 'n' and a 2d integer array
 * 'invocations' where 'invocations[i] = [a_i, b_i]' indicates that method 'a_i'
 * invokes method 'b_i'. there is a known bug in method 'k'. 'k' and any other
 * method invoked by it, either directly or indirectly are considered suspicious
 * and we aim to remove them. a group of methods can only be removed if no
 * method outside the group invokes any methods within it. return an array
 * containing all the remaining methods after removing the suspicious methods.
 */

int *remainingMethods(int n, int k, int **invocations, int invocationsSize,
                      int *invocationsColSize, int *returnSize) {
  int *out_degree = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < invocationsSize; i++) {
    int u = invocations[i][0];
    out_degree[u]++;
  }
  int **adj = (int **)malloc(n * sizeof(int *));
  int *idx = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++)
    adj[i] = (int *)malloc(out_degree[i] * sizeof(int));
  for (int i = 0; i < invocationsSize; i++) {
    int u = invocations[i][0], v = invocations[i][1];
    adj[u][idx[u]++] = v;
  }
  bool *suspicious = (bool *)calloc(n, sizeof(bool));
  suspicious[k] = true;
  int *queue = (int *)malloc(n * sizeof(int));
  int front = 0, back = 0;
  queue[back++] = k;
  while (front < back) {
    int u = queue[front++];
    for (int i = 0; i < out_degree[u]; i++) {
      int v = adj[u][i];
      if (!suspicious[v]) {
        suspicious[v] = true;
        queue[back++] = v;
      }
    }
  }
  for (int i = 0; i < invocationsSize; i++) {
    int u = invocations[i][0], v = invocations[i][1];
    if (!suspicious[u] && suspicious[v]) {
      int *ans = (int *)malloc(n * sizeof(int));
      *returnSize = n;
      for (int j = 0; j < n; j++)
        ans[j] = j;
      for (int j = 0; j < n; j++)
        free(adj[j]);
      free(adj);
      free(out_degree);
      free(idx);
      free(suspicious);
      free(queue);
      return ans;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (!suspicious[i])
      cnt++;
  int *ans = (int *)malloc(cnt * sizeof(int));
  int ans_idx = 0;
  *returnSize = cnt;
  for (int i = 0; i < n; i++)
    if (!suspicious[i])
      ans[ans_idx++] = i;
  for (int j = 0; j < n; j++)
    free(adj[j]);
  free(adj);
  free(out_degree);
  free(idx);
  free(suspicious);
  free(queue);
  return ans;
}

int main() {
  int i1i[3][2] = {{1, 2}, {0, 1}, {3, 2}};
  int i2i[4][2] = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
  int i3i[3][2] = {{1, 2}, {0, 1}, {2, 0}};
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  struct two_d_arr *i3 =
      two_d_arr_init(ARRAY_SIZE(i3i), ARRAY_SIZE(i3i[0]), i3i);
  int rs1, r1[] = {0, 1, 2, 3};
  int rs2, r2[] = {3, 4};
  int rs3, r3[] = {};
  int *rm1 = remainingMethods(4, 1, i1->arr, i1->row_size, i1->col_size, &rs1);
  int *rm2 = remainingMethods(5, 0, i2->arr, i2->row_size, i2->col_size, &rs2);
  int *rm3 = remainingMethods(3, 2, i3->arr, i3->row_size, i3->col_size, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", rm1[i]);
    assert(rm1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", rm2[i]);
    assert(rm2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", rm3[i]);
    assert(rm3[i] == r3[i]);
  }
  printf("\n");
  free(rm1);
  free(rm2);
  free(rm3);
  two_d_arr_free(i1);
  two_d_arr_free(i2);
  two_d_arr_free(i3);
}
