// 1559. Detect Cycles in 2D Grid
#include "leetcode.h"

/*
 * given a 2d array of characters 'grid' of size 'm x n', you eed to find if
 * there exists any cycle consisting of the same value in 'grid'. a cycle is a
 * path of length 4 or more in the grid that starts and ends at the same cell.
 * from a given cell, you can move to one of the cells adjacent to it - in one
 * of the four directions, if it has the same value of the current cell. also,
 * you cannot move to the cell that you visited in your last move. return true
 * if any cycle of the same value exists in 'grid', otherwise return false.
 */

bool dfs(char **grid, int m, int n, bool **vis, int i, int j, int prev,
         char key) {
  if (i < 0 && i >= m || j < 0 || j >= n)
    return false;
  if (prev != 0 && grid[i][j] != key)
    return false;
  if (prev != 0 && vis[i][j])
    return true;
  vis[i][j] = true;
  if (prev != 1)
    return dfs(grid, m, n, vis, i - 1, j, 3, grid[i][j]);
  if (prev != 1)
    return dfs(grid, m, n, vis, i, j + 1, 4, grid[i][j]);
  if (prev != 1)
    return dfs(grid, m, n, vis, i + 1, j, 1, grid[i][j]);
  if (prev != 1)
    return dfs(grid, m, n, vis, i, j - 1, 2, grid[i][j]);
  return false;
}

void free_vis(bool **vis, int n) {
  for (int i = 0; i < n; i++)
    free(vis[i]);
  free(vis);
}

bool containsCycle(char **grid, int gridSize, int *gridColSize) {
  bool **vis = (bool **)calloc(gridSize, sizeof(bool *));
  for (int i = 0; i < gridSize; i++)
    vis[i] = (bool *)calloc(*gridColSize, sizeof(bool));
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < *gridColSize; j++)
      if (!vis[i][j])
        if (dfs(grid, gridSize, *gridColSize, vis, i, j, 0, '0')) {
          free_vis(vis, gridSize);
          return true;
        }
  free_vis(vis, gridSize);
  return false;
}

int main() {
  char g1[4][4] = {{'a', 'a', 'a', 'a'},
                   {'a', 'b', 'b', 'a'},
                   {'a', 'b', 'b', 'a'},
                   {'a', 'a', 'a', 'a'}};
  char g2[4][4] = {{'c', 'c', 'c', 'a'},
                   {'c', 'd', 'c', 'c'},
                   {'c', 'c', 'e', 'c'},
                   {'f', 'c', 'c', 'c'}};
  char g3[3][3] = {{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}};
  bool r1 =
      containsCycle((char **)g1, ARRAY_SIZE(g1), (int *)ARRAY_SIZE(g1[0]));
  bool r2 =
      containsCycle((char **)g2, ARRAY_SIZE(g2), (int *)ARRAY_SIZE(g2[0]));
  bool r3 =
      containsCycle((char **)g3, ARRAY_SIZE(g3), (int *)ARRAY_SIZE(g3[0]));
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == false);
}
