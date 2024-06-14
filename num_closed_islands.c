// 1254. Number of Closed Islands
#include <stdbool.h>
#include <stdio.h>

/*
 * given 2d 'grid' consists of 0's (land) and 1's (water). an island is a
 * maximal four directionally connected group of 0's and a closed island is an
 * island totally (all left, top, right, bottom) surrouned by 1's. return the
 * number of closed islands.
 */

bool dfs(int **grid, int i, int j, int row, int col) {
  if (i < 0 || i >= row || j < 0 || j >= col)
    return false;
  if (grid[i][j])
    return true;
  grid[i][j] = 1;
  bool up = dfs(grid, i - 1, j, row, col);
  bool down = dfs(grid, i + 1, j, row, col);
  bool left = dfs(grid, i, j - 1, row, col);
  bool right = dfs(grid, i, j + 1, row, col);
  return up && down && left && right;
}

int closedIslands(int **grid, int grid_size, int *grid_col_size) {
  int row = grid_size, col = grid_col_size[0], ans = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (!grid[i][j] && dfs(grid, i, j, row, col))
        ans++;
  return ans;
}

int main() {
  int g1[4][8] = {{1, 1, 1, 1, 1, 1, 1, 0},
                  {1, 0, 0, 0, 0, 1, 1, 0},
                  {1, 0, 0, 0, 0, 1, 0, 1},
                  {1, 1, 1, 1, 1, 1, 1, 0}},
      gcs1[] = {8, 8, 8, 8}, gs1 = 4;
  int g2[2][5] = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}}, gcs2[] = {5, 5}, gs2 = 2;
  int g3[7][7] = {{1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1},
                  {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1},
                  {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1},
                  {1, 1, 1, 1, 1, 1, 1}},
      gcs3[] = {7, 7, 7, 7, 7, 7, 7}, gs3 = 7;
  printf("%d\n", closedIslands(g1, gs1, gcs1)); // expect: 2
  printf("%d\n", closedIslands(g2, gs2, gcs2)); // expect: 1
  printf("%d\n", closedIslands(g3, gs3, gcs3)); // expect: 2
}
