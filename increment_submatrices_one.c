// 2536. Increment Submatrices by One
#include "leetcode.h"

/*
 * you are given a positive integer 'n', indicating that we initially have an 'n
 * x n' 0-indexed integer matrix 'mat' filled with zeros. you are also given a
 * 2d integer array 'query'. for each 'query[i] = [row1_i, col1_i, row2_i,
 * col2_i]', you should do the following operation: add 1 to every element in
 * the submatrix with the top left corner '(row1_i, col1_i)' and the bottom
 * right corner '(row2_i, col2_i)'. that is, add 1 to 'mat[x][y]' for all
 * 'row1_i <= x <= row2_i' and 'col1_i <= y <= col2_i'. return the matrix 'mat'
 * after performing every query
 */

int **rangeAddQueries(int n, int **queries, int queriesSize,
                      int *queriesColSize, int *returnSize,
                      int **returnColumnSizes) {
  int **ans = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    ans[i] = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int r1 = queries[i][0];
    int c1 = queries[i][1];
    int r2 = queries[i][2];
    int c2 = queries[i][3];
    for (int j = r1; j <= r2; j++) {
      ans[j][c1]++;
      if (c2 < n - 1)
        ans[j][c2 + 1]--;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 1; j < n; j++)
      ans[i][j] += ans[i][j - 1];
  *returnSize = n;
  *returnColumnSizes = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    returnColumnSizes[0][i] = n;
  return ans;
}

int main() {
  int q1i[2][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}}, rs1, *rcs1;
  int q2i[1][4] = {{0, 0, 1, 1}}, rs2, *rcs2;
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int **raq1 =
      rangeAddQueries(3, q1->arr, q1->row_size, q1->col_size, &rs1, &rcs1);
  int **raq2 =
      rangeAddQueries(2, q2->arr, q2->row_size, q2->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", raq1[i][j]); // expect: [[1,1,0],[1,2,1],[0,1,1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", raq2[i][j]); // expect: [[1,1],[1,1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(raq1[i]);
  free(raq1);
  free(rcs1);
  two_d_arr_free(q1);
  for (int i = 0; i < rs2; i++)
    free(raq2[i]);
  free(raq2);
  free(rcs2);
  two_d_arr_free(q2);
}
