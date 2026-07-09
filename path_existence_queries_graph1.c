// 3532. Path Existence Queries in a Graph I
#include "leetcode.h"

/*
 * you are given an integer 'n' representing the number of nodes in a graph,
 * labeled from tp to 'n - 1'. you are also given an integer array 'nums' of
 * length 'n' sorted in non-decreasing order, and an integer 'maxDiff'. an
 * undirected edge exists between nodes 'i' and 'j' if the absolute difference
 * between 'nums[i]' and 'nums[j]' is at most 'maxDiff'. you are also given a 2d
 * integer array 'queries'. for each 'queries[i] = [u_i, v_i]', determine
 * whether there exists a path between nodes 'u_i' and 'v_i'. return a boolean
 * array 'answer' where 'answer[i]' is 'true' if there exists a path between
 * 'u_i' and 'v_i' in the i'th query and 'false' otherwise.
 */

bool *pathExistenceQueries(int n, int *nums, int numsSize, int maxDiff,
                           int **queries, int queriesSize, int *queriesColSize,
                           int *returnSize) {
  int *dp = (int *)calloc(n, sizeof(int)), cnt = 0;
  for (int i = 1; i < n; i++) {
    if (nums[i] - nums[i - 1] > maxDiff)
      cnt++;
    dp[i] = cnt;
  }
  bool *ans = (bool *)malloc(queriesSize * sizeof(bool));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; i++) {
    int u = queries[i][0], v = queries[i][1];
    ans[i] = dp[u] == dp[v];
  }
  free(dp);
  return ans;
}

int main() {
  int n1[] = {1, 3}, q1i[2][2] = {{0, 0}, {0, 1}}, rs1;
  int n2[] = {2, 5, 6, 8}, q2i[4][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, rs2;
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  bool r1[] = {true, false}, r2[] = {false, false, true, true};
  bool *peq1 = pathExistenceQueries(2, n1, ARRAY_SIZE(n1), 1, q1->arr,
                                    q1->row_size, q1->col_size, &rs1);
  bool *peq2 = pathExistenceQueries(4, n2, ARRAY_SIZE(n2), 2, q2->arr,
                                    q2->row_size, q2->col_size, &rs2);
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
  free(peq1);
  free(peq2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
