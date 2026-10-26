// 3619. Count Islands With Total Value Divisible by K
#include "leetcode.h"

/*
 * you are given an 'm x n' matrix 'grid' and a positive integer 'k'. an island
 * is a group of positive integers that are 4 directionally connected. the total
 * value of an island is the sum of the values of all cedlls in the island.
 * return the number of islands with a total value divisible by 'k'.
 */

long long dfs(int **grid, int n, int m, int r, int c, bool **vis) {
  if (r >= n || r < 0 || c >= m || c < 0 || vis[r][c] || !grid[r][c])
    return 0;
  vis[r][c] = true;
  long long sum = grid[r][c];
  sum += dfs(grid, n, m, r - 1, c, vis);
  sum += dfs(grid, n, m, r, c + 1, vis);
  sum += dfs(grid, n, m, r + 1, c, vis);
  sum += dfs(grid, n, m, r, c - 1, vis);
  return sum;
}

int countIslands(int **grid, int gridSize, int *gridColSize, int k) {
  int n = gridSize, m = gridColSize[0], cnt = 0;
  bool **vis = (bool **)malloc(n * sizeof(bool *));
  for (int i = 0; i < n; i++)
    vis[i] = (bool *)calloc(m, sizeof(bool));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!vis[i][j] && grid[i][j]) {
        long long val = dfs(grid, n, m, i, j, vis);
        if (!(val % k))
          cnt++;
      }
  for (int i = 0; i < n; i++)
    free(vis[i]);
  free(vis);
  return cnt;
}

int main() {
  int g1i[5][5] = {{0, 2, 1, 0, 0},
                   {0, 5, 0, 0, 5},
                   {0, 0, 1, 0, 0},
                   {0, 1, 4, 7, 0},
                   {0, 2, 0, 0, 8}};
  int g2i[3][4] = {
      {3, 0, 3, 0},
      {0, 3, 0, 3},
      {3, 0, 3, 0},
  };
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  int r1 = countIslands(g1->arr, g1->row_size, g1->col_size, 5);
  int r2 = countIslands(g2->arr, g2->row_size, g2->col_size, 3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
}
