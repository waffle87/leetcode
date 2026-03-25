// 3546. Equal Sum Grid Partition I
#include "leetcode.h"

/*
 * you are given an 'm x n' matrix 'grid' of positive integers. your task is to
 * determine if it is possible to make either one horizontal or one vertical cut
 * on the grid such that each of the two resulting sections formed by the cut is
 * non-empty and the sum of the elements in both sections is equal. return
 * 'true' if such partition exists, otherwise return 'false'.
 */

bool canPartitionGrid(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0];
  long long total = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      total += grid[i][j];
  if (total % 2)
    return false;
  long long target = total / 2, sum = 0;
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n; j++)
      sum += grid[i][j];
    if (sum == target)
      return true;
  }
  sum = 0;
  for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < m; i++)
      sum += grid[i][j];
    if (sum == target)
      return true;
  }
  return false;
}

int main() {
  int g1i[2][2] = {{1, 4}, {2, 3}}, g2i[2][2] = {{1, 3}, {2, 4}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  bool r1 = canPartitionGrid(g1->arr, g1->row_size, g1->col_size);
  bool r2 = canPartitionGrid(g2->arr, g2->row_size, g2->col_size);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
