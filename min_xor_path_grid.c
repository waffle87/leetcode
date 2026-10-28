// 3882. Minimum XOR Path in a Grid
#include "leetcode.h"

/*
 * you are given a 2d integer array 'grid' of size 'm x n'. you start at the
 * top-left cell '(0, 0)' and want to reach the bottom-right cell '(m - 1, n -
 * 1)'. at each step, you may move either right or down. the cost of a path is
 * defined as the bitwise xor of all the values in the cells along that path,
 * including the start and end cells. return the minimum possible xor value
 * among all valid paths from '(0, 0)' to '(m - 1, n - 1)'.
 */

int minCost(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0];
  bool (*dp)[1024] = calloc(n, sizeof(*dp));
  bool next[1024] = {false};
  dp[0][grid[0][0]] = true;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!i && !j)
        continue;
      int val = grid[i][j];
      memset(next, false, sizeof(next));
      for (int k = 0; k < 1024; k++)
        if (dp[j][k] || (j > 0 && dp[j - 1][k]))
          next[k ^ val] = true;
      memcpy(dp[j], next, sizeof(next));
    }
  }
  int ans = -1;
  for (int i = 0; i < 1024; i++)
    if (dp[n - 1][i]) {
      ans = i;
      break;
    }
  free(dp);
  return ans;
}

int main() {
  int g1i[2][2] = {{1, 2}, {3, 4}};
  int g2i[2][2] = {{6, 7}, {5, 8}};
  int g3i[1][3] = {{2, 7, 5}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1 = minCost(g1->arr, g1->row_size, g1->col_size);
  int r2 = minCost(g2->arr, g2->row_size, g2->col_size);
  int r3 = minCost(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 9);
  printf("%d\n", r3);
  assert(r3 == 0);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
