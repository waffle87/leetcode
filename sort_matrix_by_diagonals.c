// 3446. Sort Matrix by Diagonals
#include "leetcode.h"

/*
 * you are given an 'n x n' square matrix of integers 'grid'. return the matrix
 * such that the diagonals in the bottom left triangle including the middle are
 * sorted in non-increasing order. the diagonals in the top-right triangle are
 * sorted in non-decreasing order.
 */

int cmp1(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int cmp2(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int **sortMatrix(int **grid, int gridSize, int *gridColSize, int *returnSize,
                 int **returnColumnSizes) {
  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;
  int n = gridSize, m = gridColSize[0];
  int diag_cnt = n + m - 1;
  int *sizes = (int *)calloc(diag_cnt, sizeof(int));
  int **diags = (int **)malloc(diag_cnt * sizeof(int *));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      sizes[i - j + m - 1]++;
  for (int k = 0; k < diag_cnt; k++) {
    diags[k] = (int *)malloc(sizes[k] * sizeof(int));
    sizes[k] = 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      diags[i - j + m - 1][sizes[i - j + m - 1]++] = grid[i][j];
  for (int k = 0; k < diag_cnt; k++) {
    if (k < m - 1)
      qsort(diags[k], sizes[k], sizeof(int), cmp1);
    else
      qsort(diags[k], sizes[k], sizeof(int), cmp2);
    sizes[k] = 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      grid[i][j] = diags[i - j + m - 1][sizes[i - j + m - 1]++];
  for (int i = 0; i < diag_cnt; i++)
    free(diags[i]);
  free(diags);
  free(sizes);
  return grid;
}

int main() {
  int g1i[3][3] = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}}, rs1, *rcs1;
  int g2i[2][2] = {{0, 1}, {1, 2}}, rs2, *rcs2;
  int g3i[1][1] = {{1}}, rs3, *rcs3;
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int **sm1 = sortMatrix(g1->arr, g1->row_size, g1->col_size, &rs1, &rcs1);
  int **sm2 = sortMatrix(g2->arr, g2->row_size, g2->col_size, &rs2, &rcs2);
  int **sm3 = sortMatrix(g3->arr, g3->row_size, g3->col_size, &rs3, &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", sm1[i][j]); // expect: [[8,2,3],[9,6,7],[4,5,1]]
    printf("\n");
  }
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", sm2[i][j]); // expect: [[2,1],[1,0]]
    printf("\n");
  }
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++)
      printf("%d ", sm3[i][j]); // expect: [[1]]
    printf("\n");
  }
  for (int i = 0; i < rs1; i++)
    free(sm1[i]);
  free(sm1);
  for (int i = 0; i < rs2; i++)
    free(sm2[i]);
  free(sm2);
  for (int i = 0; i < rs3; i++)
    free(sm3[i]);
  free(sm3);
  free(rcs1);
  free(rcs2);
  free(rcs3);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
