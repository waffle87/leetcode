// 1254. Number of Closed Islands
#include "leetcode.h"

/*
 * given 2d 'grid' consists of 0's (land) and 1's (water). an island is a
 * maximal four directionally connected group of 0's and a closed island is an
 * island totally (all left, top, right, bottom) surrouned by 1's. return the
 * number of closed islands.
 */

void dfs(int **grid, int m, int n, int r, int c) {
  if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c])
    return;
  grid[r][c] = 1;
  dfs(grid, m, n, r + 1, c);
  dfs(grid, m, n, r - 1, c);
  dfs(grid, m, n, r, c + 1);
  dfs(grid, m, n, r, c - 1);
}

int closedIsland(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0];
  for (int i = 0; i < m; i++) {
    if (!grid[i][0])
      dfs(grid, m, n, i, 0);
    if (!grid[i][n - 1])
      dfs(grid, m, n, i, n - 1);
  }
  for (int i = 0; i < n; i++) {
    if (!grid[0][i])
      dfs(grid, m, n, 0, i);
    if (!grid[m - 1][i])
      dfs(grid, m, n, m - 1, i);
  }
  int cnt = 0;
  for (int i = 1; i < m - 1; i++)
    for (int j = 1; j < n - 1; j++)
      if (!grid[i][j]) {
        cnt++;
        dfs(grid, m, n, i, j);
      }
  return cnt;
}

int main() {
  int g1i[4][8] = {
      {1, 1, 1, 1, 1, 1, 1, 0},
      {1, 0, 0, 0, 0, 1, 1, 0},
      {1, 0, 0, 0, 0, 1, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 0},
  };
  int g2i[2][5] = {
      {0, 0, 1, 0, 0},
      {0, 1, 0, 1, 0},
  };
  int g3i[7][7] = {
      {1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1},
      {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1},
  };
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1 = closedIsland(g1->arr, g1->row_size, g1->col_size);
  int r2 = closedIsland(g2->arr, g2->row_size, g2->col_size);
  int r3 = closedIsland(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
