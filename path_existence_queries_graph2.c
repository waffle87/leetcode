// 3534. Path Existence Queries in a Graph II
#include "leetcode.h"

/*
 * you are given an integer 'n' representing the number of nodes in a graph,
 * labeled from 0 to 'n - 1'. you are also given an integer array 'nums' of
 * length 'n' and an integer 'maxDiff'. an undirected edge exists between nodes
 * 'i' and 'j' if the absolute difference between 'nums[i]' and 'nums[j]' is at
 * most 'maxDiff'. you are also given a 2d integer array 'queries'. for each
 * 'qeuries[i] = [u_i, v_i]', find the minimum distance between nodes 'u_i' and
 * 'v_i'. if no path exists between the two nodes, return -1 for that query.
 * return an array 'answer' where 'answer[i]' is the result of the i'th query.
 */

struct pair {
  int val;
  int idx;
};

int cmp(const void *a, const void *b) {
  struct pair *aa = (struct pair *)a;
  struct pair *bb = (struct pair *)b;
  if (aa->val != bb->val)
    return aa->val - bb->val;
  return aa->idx - bb->idx;
}

int *pathExistenceQueries(int n, int *nums, int numsSize, int maxDiff,
                          int **queries, int queriesSize, int *queriesColSize,
                          int *returnSize) {
  static int log = 18;
  struct pair *vec = (struct pair *)malloc(n * sizeof(struct pair));
  for (int i = 0; i < n; i++) {
    vec[i].val = nums[i];
    vec[i].idx = i;
  }
  qsort(vec, n, sizeof(struct pair), cmp);
  int *sorted_idx = (int *)malloc(n * sizeof(int));
  int **st = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    sorted_idx[vec[i].idx] = i;
    st[i] = (int *)calloc(log, sizeof(int));
  }
  int l = 0;
  for (int r = 0; r < n; r++)
    while (vec[r].val - vec[l].val > maxDiff)
      st[l++][0] = r - 1;
  while (l < n)
    st[l++][0] = n - 1;
  for (int j = 1; j < log; j++)
    for (int i = 0; i < n; i++)
      st[i][j] = st[st[i][j - 1]][j - 1];
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  memset(ans, -1, queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int a = sorted_idx[queries[i][0]];
    int b = sorted_idx[queries[i][1]];
    if (a > b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    if (a == b) {
      ans[i] = 0;
      continue;
    }
    int curr = a, step = 0;
    for (int j = log - 1; j >= 0; j--)
      if (st[curr][j] < b) {
        step += 1 << j;
        curr = st[curr][j];
      }
    if (st[curr][0] >= b)
      ans[i] = step + 1;
  }
  for (int i = 0; i < n; i++)
    free(st[i]);
  free(st);
  free(vec);
  free(sorted_idx);
  return ans;
}

int main() {
  int n1[] = {1, 8, 3, 4, 2}, q1i[2][2] = {{0, 3}, {2, 4}};
  int n2[] = {5, 3, 1, 9, 10}, q2i[4][2] = {{0, 1}, {0, 2}, {2, 3}, {4, 3}};
  int n3[] = {3, 6, 1}, q3i[3][2] = {{0, 0}, {0, 1}, {1, 2}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  struct two_d_arr *q3 =
      two_d_arr_init(ARRAY_SIZE(q3i), ARRAY_SIZE(q3i[0]), q3i);
  int r1[] = {1, 1}, rs1;
  int r2[] = {1, 2, -1, 1}, rs2;
  int r3[] = {0, -1, -1}, rs3;
  int *peq1 = pathExistenceQueries(5, n1, ARRAY_SIZE(n1), 3, q1->arr,
                                   q1->row_size, q1->col_size, &rs1);
  int *peq2 = pathExistenceQueries(5, n2, ARRAY_SIZE(n2), 2, q2->arr,
                                   q2->row_size, q2->col_size, &rs2);
  int *peq3 = pathExistenceQueries(3, n3, ARRAY_SIZE(n3), 1, q3->arr,
                                   q3->row_size, q3->col_size, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", peq1[i]);
    assert(peq1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", peq2[i]);
    assert(peq2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", peq3[i]);
    assert(peq3[i] == r3[i]);
  }
  printf("\n");
  free(peq1);
  free(peq2);
  free(peq3);
  two_d_arr_free(q2);
  two_d_arr_free(q1);
  two_d_arr_free(q3);
}
