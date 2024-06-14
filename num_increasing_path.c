// 2328. Number of Increasing Paths in a Grid
#include <stdio.h>
#include <stdlib.h>

/*
 * given an 'm x n' integer matrix 'grid' where you can move from a cell to any
 * adjacent cell in all 4 directions. return th number of strictly increasing
 * paths in the grid such that you can start from any cell and end at any cell.
 * since the answer may be very large, return it modulo 10^9+7. two paths are
 * considered different if they do not have exactly the same sequence of visited
 * cells.
 */

const int MOD = 1e9 + 7;
int dfs(int **grid, int grid_size, int *grid_col_size, int row, int col,
        int prev, int *ans, int **seen) {
  if (row < 0 || row >= grid_size || col < 0 || col >= *grid_col_size ||
      grid[row][col] <= prev)
    return 0;

  if (seen[row][col])
    return seen[row][col];
  int tmp = 1;
  tmp += dfs(grid, grid_size, grid_col_size, row + 1, col, grid[row][col], ans,
             seen);
  tmp += dfs(grid, grid_size, grid_col_size, row - 1, col, grid[row][col], ans,
             seen);
  tmp += dfs(grid, grid_size, grid_col_size, row, col + 1, grid[row][col], ans,
             seen);
  tmp += dfs(grid, grid_size, grid_col_size, row, col - 1, grid[row][col], ans,
             seen);
  tmp %= MOD;
  seen[row][col] = tmp;
  return seen[row][col];
}
int countPaths(int **grid, int grid_size, int *grid_col_size) {
  int **seen = (int **)malloc(sizeof(int *) * grid_size), ans = 0;
  for (int i = 0; i < grid_size; i++)
    seen[i] = calloc(*grid_col_size, sizeof(int));
  for (int i = 0; i < grid_size; i++)
    for (int j = 0; j < *grid_col_size; j++) {

      if (seen[i][j] == 0)
        seen[i][j] = dfs(grid, grid_size, grid_col_size, i, j, -1, &ans, seen);

      ans = (ans + seen[i][j]) % MOD;
    }
  return ans;
}
