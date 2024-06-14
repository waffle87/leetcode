// 64. Minimum Path Sum
#include <math.h>

// given 'm x n grid' filled with non-negative numbers, find a path from top
// left to bottom right, which minimises the sum of all numbers along its path

int minPathSum(int **grid, int grid_size, int *grid_col_size) {
  int i, j;
  for (i = 0; i < grid_size; i++) {
    for (j = 0; j < (*grid_col_size); j++) {
      if (i - 1 >= 0 && j - 1 >= 0)
        grid[i][j] += fmin(grid[i - 1][j], grid[i][j - 1]);
      else if (i - 1 >= 0)
        grid[i][j] += grid[i - 1][j];
      else if (j - 1 >= 0)
        grid[i][j] += grid[i][j - 1];
    }
  }
  return grid[i - 1][j - 1];
}
