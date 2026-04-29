// 3225. Maximum Score From Grid Operations
#include "leetcode.h"

/*
 * you are given a 2d matrix 'grid' of size 'm x n'. initially, all cells of the
 * grid are coloured white. in one operation, you can select any cell of indices
 * '(i, j)', and colour black all the cells of the j'th column starting from the
 * top row down to the i'th row. the grid score is the sum of all 'grid[i][j]'
 * such that cell '(i, j)' is white and it has a horizontally adjacent black
 * cell. return the maximum score that can be achieved after some number of
 * operations.
 */

long long maximumScore(int **grid, int gridSize, int *gridColSize) {
  int n = gridColSize[0];
  if (n == 1)
    return 0;
  long long ***dp = (long long ***)malloc(n * sizeof(long long **));
  for (int i = 0; i < n; i++) {
    dp[i] = (long long **)malloc((n + 1) * sizeof(long long *));
    for (int j = 0; j <= n; j++)
      dp[i][j] = (long long *)calloc(n + 1, sizeof(long long));
  }
  long long **prev_max = (long long **)malloc((n + 1) * sizeof(long long *));
  for (int i = 0; i <= n; i++)
    prev_max[i] = (long long *)calloc(n + 1, sizeof(long long));
  long long **prev_suffix_max =
      (long long **)malloc((n + 1) * sizeof(long long *));
  for (int i = 0; i <= n; i++)
    prev_suffix_max[i] = (long long *)calloc(n + 1, sizeof(long long));
  long long **col_sum = (long long **)malloc(n * sizeof(long long *));
  for (int c = 0; c < n; c++) {
    col_sum[c] = (long long *)calloc(n + 1, sizeof(long long));
    for (int r = 1; r <= n; r++)
      col_sum[c][r] = col_sum[c][r - 1] + grid[r - 1][c];
  }
  for (int i = 1; i < n; i++) {
    for (int curr_h = 0; curr_h <= n; curr_h++)
      for (int prev_h = 0; prev_h <= n; prev_h++) {
        if (curr_h <= prev_h) {
          long long extra_score = col_sum[i][prev_h] - col_sum[i][curr_h];
          dp[i][curr_h][prev_h] = fmax(
              dp[i][curr_h][prev_h], prev_suffix_max[prev_h][0] + extra_score);
        } else {
          long long extra_score =
              col_sum[i - 1][curr_h] - col_sum[i - 1][prev_h];
          dp[i][curr_h][prev_h] =
              fmax(dp[i][curr_h][prev_h],
                   fmax(prev_suffix_max[prev_h][curr_h],
                        prev_max[prev_h][curr_h] + extra_score));
        }
      }
    for (int curr_h = 0; curr_h <= n; curr_h++) {
      prev_max[curr_h][0] = dp[i][curr_h][0];
      for (int prev_h = 1; prev_h <= n; prev_h++) {
        long long penalty =
            (prev_h > curr_h) ? (col_sum[i][prev_h] - col_sum[i][curr_h]) : 0;
        prev_max[curr_h][prev_h] =
            fmax(prev_max[curr_h][prev_h - 1], dp[i][curr_h][prev_h] - penalty);
      }
      prev_suffix_max[curr_h][n] = dp[i][curr_h][n];
      for (int prev_h = n - 1; prev_h >= 0; prev_h--)
        prev_suffix_max[curr_h][prev_h] =
            fmax(prev_suffix_max[curr_h][prev_h + 1], dp[i][curr_h][prev_h]);
    }
  }
  long long ans = 0;
  for (int k = 0; k <= n; k++)
    ans = fmax(ans, fmax(dp[n - 1][n][k], dp[n - 1][0][k]));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++)
      free(dp[i][j]);
    free(dp[i]);
  }
  free(dp);
  for (int i = 0; i <= n; i++) {
    free(prev_max[i]);
    free(prev_suffix_max[i]);
  }
  free(prev_max);
  free(prev_suffix_max);
  for (int i = 0; i < n; i++)
    free(col_sum[i]);
  free(col_sum);
  return ans;
}

int main() {
  int g1i[5][5] = {{0, 0, 0, 0, 0},
                   {0, 0, 3, 0, 0},
                   {0, 1, 0, 0, 0},
                   {5, 0, 0, 3, 0},
                   {0, 0, 0, 0, 2}};
  int g2i[5][5] = {{10, 9, 0, 0, 15},
                   {7, 1, 0, 8, 0},
                   {5, 20, 0, 11, 0},
                   {0, 0, 0, 1, 2},
                   {8, 12, 1, 10, 3}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  long long r1 = maximumScore(g1->arr, g1->row_size, g1->col_size);
  long long r2 = maximumScore(g2->arr, g2->row_size, g2->col_size);
  printf("%lld\n", r1);
  assert(r1 == 11);
  printf("%lld\n", r2);
  assert(r2 == 94);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
