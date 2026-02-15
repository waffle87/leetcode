// 1020. Number of Enclaves
#include "leetcode.h"

/*
 * given an 'm * n' binary matrix grid, where 0 represents a sea
 * cell and 1 represents a land cell. a move consists of walking
 * from one land cell to another adjacent (4-directionally) land
 * cell o walking off the boundary of the 'grid'. return number
 * of land cells in 'grid' for which we cannot walk off the
 * boundary of the grid in any number of moves.
 */

void dfs(int **grid, int r, int c, int n, int m) {
  if (r < 0 || c < 0 || r > n - 1 || c > m - 1 || !grid[r][c] ||
      grid[r][c] == -1)
    return;
  grid[r][c] = -1;
  dfs(grid, r + 1, c, n, m);
  dfs(grid, r - 1, c, n, m);
  dfs(grid, r, c + 1, n, m);
  dfs(grid, r, c - 1, n, m);
}

int numEnclaves(int **grid, int gridSize, int *gridColSize) {
  int n = gridSize, m = gridColSize[0], ans = 0;
  for (int c = 0; c < m; c++) {
    if (grid[0][c] == 1)
      dfs(grid, 0, c, n, m);
    if (grid[n - 1][c] == 1)
      dfs(grid, n - 1, c, n, m);
  }
  for (int r = 1; r < n - 1; r++) {
    if (grid[r][0] == 1)
      dfs(grid, r, 0, n, m);
    if (grid[r][m - 1] == 1)
      dfs(grid, r, m - 1, n, m);
  }
  for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
      if (grid[r][c] == 1)
        ans++;
  return ans;
}

int main() {
  int g1i[4][4] = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  int g2i[4][4] = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int r1 = numEnclaves(g1->arr, g1->row_size, g1->col_size);
  int r2 = numEnclaves(g2->arr, g2->row_size, g2->col_size);
  printf("%d\n", r1); // expect: 3
  assert(r1 == 3);
  printf("%d\n", r2); // expect: 0
  assert(r2 == 0);
}
