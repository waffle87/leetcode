// 807. Max Increase to Keep City Skyline
#include "leetcode.h"

/*
 * there is a city composed of 'n * n' blocks where each block contains a single
 * building shaped like a vertical square prism. you are given 0 idxed 'n * n'
 * integer matrix 'grid' where 'grid[r][c]' represents the height of the
 * building located in the block at row 'r' and column 'c'. a city's skiline is
 * the outer contour formed by all the building =hen viewing the side of the
 * city from a distance. the skyline from a distance. the skyline from each
 * cardinal direction, north, east, south, and west may be different. we are
 * allowed to increase the height of any number of buildings by any amount. the
 * height of a 0-height building can also be increased. however, increasing the
 * height of a building should not affect the city's skyline from any cardinal
 * direction. return the maximum total sum that the height of the buildings can
 * be increased by without changing the city's skyline from any cardinal
 * direction
 */

int max_row(int **grid, int size, int idx) {
  int max = INT_MIN;
  for (int i = 0; i < size; i++)
    if (grid[idx][i] > max)
      max = grid[idx][i];
  return max;
}

int max_col(int **grid, int size, int idx) {
  int max = INT_MIN;
  for (int i = 0; i < size; i++)
    if (grid[i][idx] > max)
      max = grid[i][idx];
  return max;
}

int maxIncreaseKeepingSkyline(int **grid, int gridSize, int *gridColSize) {
  int sum = 0;
  int row_idx, col_idx, row_max, col_max;
  for (row_idx = 0; row_idx < gridSize; row_idx++)
    for (col_idx = 0; col_idx < gridColSize[row_idx]; col_idx++) {
      row_max = max_row(grid, gridColSize[row_idx], row_idx);
      col_max = max_col(grid, gridSize, col_idx);
      sum += row_max > col_max ? col_max - grid[row_idx][col_idx]
                               : row_max - grid[row_idx][col_idx];
    }
  return sum;
}

int main() {
  int g1[4][4] = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}},
      g2[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, gcs1 = 4, gcs2 = 3;
  printf("%d\n", maxIncreaseKeepingSkyline((int **)g1, ARRAY_SIZE(g1),
                                           &gcs1)); // expect: 35
  printf("%d\n", maxIncreaseKeepingSkyline((int **)g2, ARRAY_SIZE(g2),
                                           &gcs2)); // expect: 0
}
