// 1463. Cherry Pickup II
#include "leetcode.h"

/*
 * given a row * cols matrix grid representing a field of cherries where
 * 'grid[i][j]' represents the number of cherries that you can collect from the
 * '(i, j)' cell. you have two robots that can collect cherries for you located
 * at corner (0, 0) and (cols - 1). return the maximum number of cherries
 * collection using both robots by following the rulew below.
 */

int dp[70][70][70];

int dfs(int **grid, int size, int col_size, int i, int l, int r) {
  if (i >= size || l == r)
    return 0;
  if (l < 0 || l >= col_size || r < 0 || r >= col_size)
    return 0;
  if (dp[i][l][r] >= 0)
    return dp[i][l][r];
  int res = 0, dir[3] = {-1, 0, 1};
  for (int x = 0; x < 3; x++)
    for (int y = 0; y < 3; y++) {
      int tmp = dfs(grid, size, col_size, i + 1, l + dir[x], r + dir[y]);
      res = res > grid[i][l] + grid[i][r] + tmp ? res
                                                : grid[i][l] + grid[i][r] + tmp;
    }
  return dp[i][l][r] = res;
}

int cherryPickup(int **grid, int grid_size, int *grid_col_size) {
  memset(dp, -1, sizeof(dp));
  return dfs(grid, grid_size, *grid_col_size, 0, 0, *grid_col_size - 1);
}

int main() {
  int grid[4][3] = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
  int grid_col_size[] = {};
  printf("%d\n", cherryPickup((int **)grid, 4, grid_col_size)); // expect: 24
}
