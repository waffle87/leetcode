// 1594. Maximum Non Negative Product in a Matrix
#include "leetcode.h"

/*
 * you are given an 'm x n' matrix 'grid'. initially, you are located at the top
 * left corner '(0, 0)' and in each step, you can only move right or down in the
 * matrix. among all possible paths starting from the top left corner and ending
 * in the bottom-right corner, find the path with the maximum non-negative
 * product. the product of a path is the product of all integers in the grid
 * cells visited along the path. return the maximum non-negative product. if the
 * maximum product is negative, return -1. notice that the modulo is performed
 * after getting the maximum product.
 */

int maxProductPath(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0], mod = 1e9 + 7;
  long long **min = (long long **)malloc(m * sizeof(long long *));
  long long **max = (long long **)malloc(m * sizeof(long long *));
  for (int i = 0; i < m; i++) {
    min[i] = (long long *)malloc(n * sizeof(long long));
    max[i] = (long long *)malloc(n * sizeof(long long));
    for (int j = 0; j < n; j++)
      min[i][j] = max[i][j] = LLONG_MAX;
  }
  min[0][0] = max[0][0] = grid[0][0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!i && !j)
        continue;
      long long mn = LLONG_MAX, mx = LLONG_MIN;
      if (i > 0) {
        long long a = min[i - 1][j] * grid[i][j];
        long long b = max[i - 1][j] * grid[i][j];
        mn = fmin(a, fmin(b, mn));
        mx = fmax(a, fmax(b, mx));
      }
      if (j > 0) {
        long long a = min[i][j - 1] * grid[i][j];
        long long b = max[i][j - 1] * grid[i][j];
        mn = fmin(a, fmin(b, mn));
        mx = fmax(a, fmax(b, mx));
      }
      min[i][j] = mn;
      max[i][j] = mx;
    }
  }
  long long ans = max[m - 1][n - 1];
  for (int i = 0; i < m; i++) {
    free(min[i]);
    free(max[i]);
  }
  free(min);
  free(max);
  return ans >= 0 ? ans % mod : -1;
}

int main() {
  int g1i[3][3] = {{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}};
  int g2i[3][3] = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
  int g3i[2][2] = {{1, 3}, {0, -4}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1 = maxProductPath(g1->arr, g1->row_size, g1->col_size);
  int r2 = maxProductPath(g2->arr, g2->row_size, g2->col_size);
  int r3 = maxProductPath(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1);
  assert(r1 == -1);
  printf("%d\n", r2);
  assert(r2 == 8);
  printf("%d\n", r3);
  assert(r3 == 0);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
