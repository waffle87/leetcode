//463. Island Perimeter
#include "leetcode.h"

/*
 * given  a 'row * col' grid representing a map where 'grid[i][j] = 1'
 * represents land and 'grid[i][j] = 0' represents water. grid cells are
 * connected horizontally/vertically (not diagonally). the 'gird' is completely
 * surrounded by water, and there is exactly one island. the island does not
 * have lakes meaning the water inside is not connected to the water around the
 * island. one cell is a square with side length 1. the grid is rectangular
 * width and height don't exceed 100. determine the perimeter of the island.
 */

int edge_sum(int **grid, int row, int col, int grid_row_size,
             int grid_col_size) {
  int total = 0;
  if (row - 1 < 0 || !grid[row - 1][col])
    total++;
  if (row + 1 == grid_row_size || !grid[row + 1][col])
    total++;
  if (col - 1 < 0 || !grid[row][col - 1])
    total++;
  if (col + 1 == grid_col_size || !grid[row][col + 1])
    total++;
  return total;
}

int islandPerimeter(int **grid, int gridSize, int *gridColSize) {
  int ans = 0;
  for (int i = 0; i < gridSize; ++i)
    for (int j = 0; j < *gridColSize; ++j)
      if (grid[i][j])
        ans += edge_sum(grid, i, j, gridSize, *gridColSize);
  return ans;
}
