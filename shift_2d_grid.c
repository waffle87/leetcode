// 1260. Shift 2D Grid
#include "leetcode.h"

/*
 * given a 2d 'grid' of size 'm x n' and an integer 'k'. you need to shift the
 * 'grid' 'k' times. in one shift operation, element at 'grid[i][j]' moves to
 * 'grid[i][j + 1]', element at 'grid[i][n - 1]' moves to 'grid[i + 1][0]',
 * element at 'grid[m - 1][n - 1]' moves to 'grid[0][0]'. return the 2d grid
 * after applying shift operation 'k' times.
 */

int **shiftGrid(int **grid, int gridSize, int *gridColSize, int k,
                int *returnSize, int **returnColumnSizes) {
  int m = gridSize, n = gridColSize[0], total = m * n, shift = k % total;
  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;
  if (!shift)
    return grid;
  int *dp = (int *)malloc(2 * total * sizeof(int)), idx = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      dp[idx] = grid[i][j];
      dp[idx + total] = grid[i][j];
      idx++;
    }
  idx = total - shift;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      grid[i][j] = dp[idx];
      idx++;
    }
  free(dp);
  return grid;
}

int main() {
  int g1i[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int g2i[4][4] = {
      {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
  int g3i[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1[3][3] = {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}}, rs1, *rcs1;
  int r2[4][4] = {{12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}},
      rs2, *rcs2;
  int r3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, rs3, *rcs3;
  int **sg1 = shiftGrid(g1->arr, g1->row_size, g1->col_size, 1, &rs1, &rcs1);
  int **sg2 = shiftGrid(g2->arr, g2->row_size, g2->col_size, 4, &rs2, &rcs2);
  int **sg3 = shiftGrid(g3->arr, g3->row_size, g3->col_size, 9, &rs3, &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++) {
      printf("%d ", sg1[i][j]);
      assert(sg1[i][j] == r1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++) {
      printf("%d ", sg2[i][j]);
      assert(sg2[i][j] == r2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++) {
      printf("%d ", sg3[i][j]);
      assert(sg3[i][j] == r3[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
