// 2509. Cycle Length Queries in a Tree
#include "leetcode.h"

/*
 * you are given an integer 'n'. there is a complete binary tree with '2^n - 1'
 * nodes. the root of that tree is the node with the value 1, and every node
 * with a value 'val' in the range '[1, 2^(n - 1) - 1]' has two children. you
 * are also given a 2d integer array 'queries' of length 'm' where 'queries[i] =
 * [a_i, b_i]'. for each query, add an edge between the nodes with values 'a_i'
 * and 'b_i', find the length of the cycle in the graph, and remove the added
 * edge between nodes with values 'a_i' and 'b_i'.
 */

int search(int a, int b) {
  int cnt = 0;
  while (a != b) {
    if (a < b)
      b /= 2;
    else
      a /= 2;
    cnt++;
  }
  return ++cnt;
}

int *cycleLengthQueries(int n, int **queries, int queriesSize,
                        int *queriesColSize, int *returnSize) {
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; i++)
    ans[i] = search(queries[i][0], queries[i][1]);
  return ans;
}

int main() {
  int q1i[3][2] = {{5, 3}, {4, 7}, {2, 3}}, rs1;
  int q2i[1][2] = {{1, 2}}, rs2;
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int *clq1 = cycleLengthQueries(3, q1->arr, q1->row_size, q1->col_size, &rs1);
  int *clq2 = cycleLengthQueries(2, q2->arr, q2->row_size, q2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", clq1[i]); // expect: 4 5 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", clq2[i]); // expect: 2
  printf("\n");
  free(clq1);
  free(clq2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
