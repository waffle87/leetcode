// 3643. Flip Square Submatrix Vertically
#include "leetcode.h"

/*
 * you are given an 'm x n' integer matrix 'grid', and three integers 'x', 'y',
 * and 'k'. the integers 'x' and 'y' represent the row and column indices of the
 * top elft corner of a square submatrix and the integer 'k' represents the size
 * (side length) of the square submatrix. your task is to flip the submatrix by
 * reversing the order of its rows vertically. return the updated matrix.
 */

int **reverseSubmatrix(int **grid, int gridSize, int *gridColSize, int x, int y,
                       int k, int *returnSize, int **returnColumnSizes) {
  int m = gridSize, n = gridColSize[0];
  *returnSize = m;
  *returnColumnSizes = (int *)malloc(m * sizeof(int));
  int **ans = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    (*returnColumnSizes)[i] = n;
    ans[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      ans[i][j] = grid[i][j];
  }
  for (int i = 0; i < k / 2; i++)
    for (int j = 0; j < k; j++) {
      int tmp = ans[x + i][y + j];
      ans[x + i][y + j] = ans[x + k - 1 - i][y + j];
      ans[x + k - 1 - i][y + j] = tmp;
    }
  return ans;
}

int main() {
  int g1i[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int g2i[2][4] = {{3, 4, 2, 3}, {2, 3, 4, 2}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int r1[4][4] = {
      {1, 2, 3, 4}, {13, 14, 15, 8}, {9, 10, 11, 12}, {5, 6, 7, 16}};
  int r2[2][4] = {{3, 4, 4, 2}, {2, 3, 2, 3}};
  int rs1, *rcs1, rs2, *rcs2;
  int **rvsm1 = reverseSubmatrix(g1->arr, g1->row_size, g1->col_size, 1, 0, 3,
                                 &rs1, &rcs1);
  int **rvsm2 = reverseSubmatrix(g2->arr, g2->row_size, g2->col_size, 0, 2, 2,
                                 &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++) {
      printf("%d ", rvsm1[i][j]);
      assert(rvsm1[i][j] == r1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++) {
      printf("%d ", rvsm2[i][j]);
      assert(rvsm2[i][j] == r2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(rvsm1[i]);
  free(rvsm1);
  free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(rvsm2[i]);
  free(rvsm2);
  free(rcs2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
