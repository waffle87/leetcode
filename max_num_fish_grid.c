// 2658. Maximum Number of Fish in a Grid
#include "leetcode.h"

/*
 * you are given a 0-indexed 2d matrix 'grid' of size 'm x n' where '(r, c)'
 * represents a land cell if 'grid[r][c] = 0', or a water cell containing
 * 'grid[r][c]' fish, if 'grid[r][c] > 0'. afisher can start at any water cell
 * and can do the following operations any number of times: catch all the fish
 * at the current cell, or move to any adjacent water cell. return the maximum
 * number of fish the fisher can catch if he chooses his starting cell
 * optimally, or 0 if no water cells exist.
 */

void dfs(int **grid, int r, int c, int n, int m, int *cnt) {
  if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
    return;
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  (*cnt) += grid[r][c];
  grid[r][c] = 0;
  for (int i = 0; i < 4; i++) {
    int nr = r + dir[i][0];
    int nc = c + dir[i][1];
    dfs(grid, nr, nc, n, m, cnt);
  }
}

int findMaxFish(int **grid, int gridSize, int *gridColSize) {
  int ans = 0, cnt = 0;
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridColSize[i]; j++)
      if (grid[i][j]) {
        dfs(grid, i, j, gridSize, gridColSize[i], &cnt);
        ans = fmax(ans, cnt);
        cnt = 0;
      }
  return ans;
}

int main() {
  int g1i[4][4] = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}};
  int g2i[4][4] = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};
  struct two_d_arr g1, g2;
  two_d_arr_init(&g1, ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  two_d_arr_init(&g2, ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n", findMaxFish(g1.arr, g1.row_size, g1.col_size)); // expect: 7
  printf("%d\n", findMaxFish(g2.arr, g2.row_size, g2.col_size)); // expect: 1
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
}
