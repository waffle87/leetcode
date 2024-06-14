// 200. Number of Islands
#include "leetcode.h"

/*
 * given an 'm * n' 2d binary grid 'grid' which represents a map of '1's (land)
 * and '0's (water), return the number of islands present. an island
 * issurrounded by water and is formed by connected adjacent lands horizontally
 * or vertically. you may assume all four edges of the grid are all surrounded
 * by water.
 */

void visit(char **grid, int i, int j, int gridSize, int *gridColSize) {
  if (i < 0 || j < 0 || i >= gridSize)
    return;
  if (j >= gridColSize[i])
    return;
  if (grid[i][j] == '0')
    return;
  grid[i][j] = '0';
  visit(grid, i - 1, j, gridSize, gridColSize);
  visit(grid, i + 1, j, gridSize, gridColSize);
  visit(grid, i, j - 1, gridSize, gridColSize);
  visit(grid, i, j + 1, gridSize, gridColSize);
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
  int ans = 0;
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridColSize[i]; j++)
      if (grid[i][j] == '1') {
        visit(grid, i, j, gridSize, gridColSize);
        ans++;
      }
  return ans;
}
