// 3742. Maximum Path Score in a Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' grid where each cell contains one of the values 0,
 * 1, or 2. you are also given an integer 'k'. you start from the top left
 * corner and want to reach the bottom right corner by moving on right or down.
 * each cell contributes a specific score and incurs an associated cost. return
 * the maximum score achievable without exciting a total cost of 'k' or -1 if no
 * valid path exists. note if you reach the last cell but the total cost exceeds
 * 'k', the path is invalid.
 */

int maxPathScore(int **grid, int gridSize, int *gridColSize, int k) {
  int n = gridColSize[0], m = gridSize;
  int ***dp = (int ***)malloc(m * sizeof(int **));
  for (int i = 0; i < m; i++) {
    dp[i] = (int **)malloc(n * sizeof(int *));
    for (int j = 0; j < n; j++) {
      dp[i][j] = (int *)malloc((k + 1) * sizeof(int));
      for (int c = 0; c <= k; c++)
        dp[i][j][c] = INT_MIN;
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      for (int c = 0; c <= k; c++) {
        if (dp[i][j][c] == INT_MIN)
          continue;
        if (i + 1 < m) {
          int val = grid[i + 1][j];
          int cost = !val ? 0 : 1;
          if (c + cost <= k) {
            int *target = &dp[i + 1][j][c + cost];
            *target = fmax(*target, dp[i][j][c]);
          }
        }
        if (j + 1 < n) {
          int val = grid[i][j + 1];
          int cost = !val ? 0 : 1;
          if (c + cost <= k) {
            int *target = &dp[i][j + 1][c + cost];
            *target = fmax(*target, dp[i][j][c]);
          }
        }
      }
  int ans = INT_MIN;
  for (int i = 0; i <= k; i++)
    ans = fmax(ans, dp[m - 1][n - 1][i]);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      free(dp[i][j]);
    free(dp[i]);
  }
  free(dp);
  return ans < 0 ? -1 : ans;
}

int main() {
  int g1i[2][2] = {{0, 1}, {2, 0}};
  int g2i[2][2] = {{0, 1}, {1, 2}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int r1 = maxPathScore(g1->arr, g1->row_size, g1->col_size, 1);
  int r2 = maxPathScore(g2->arr, g2->row_size, g2->col_size, 1);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == -1);
}
