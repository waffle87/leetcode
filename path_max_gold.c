// 1219. Path with Maximum Gold
#include "leetcode.h"

/*
 * in a gold mine 'grid' of size 'm * n' each cell in this mine has an integer
 * representing the amount of gold in that cell, 0 if it is empty. return the
 * maximum amount of gold you can collect under the conditions: every time you
 * are located in a cell, you will collect all the gold in that cell. from your
 * position, you can walk one step to the left, right, up, or down. you cannot
 * visit thesame cell more than once. never visit a cell with 0 gold. you can
 * start and stop collecting gold from any position in the grid that has some
 * gold.
 */

void dfs(int **grid, int m, int n, int i, int j, int val, int *ans) {
  if (i < 0 || j < 0 || i == m || j == n || !grid[i][j]) {
    *ans = fmax(*ans, val);
    return;
  }
  int start_pos = grid[i][j];
  grid[i][j] = 0;
  dfs(grid, m, n, i + 1, j, val + start_pos, ans);
  dfs(grid, m, n, i - 1, j, val + start_pos, ans);
  dfs(grid, m, n, i, j + 1, val + start_pos, ans);
  dfs(grid, m, n, i, j - 1, val + start_pos, ans);
  grid[i][j] = start_pos;
}

int getMaximumGold(int **grid, int gridSize, int *gridColSize) {
  int ans = 0, m = gridSize, n = *gridColSize;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (!grid[i][j])
        continue;
      dfs(grid, m, n, i, j, 0, &ans);
    }
  return ans;
}
