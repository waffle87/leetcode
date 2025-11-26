// 2435. Paths in Matrix Whose Sum Is Divisible by K
#include "leetcode.h"

/*
 * you are given a 0-indexed 'm x n' integer matrix 'grid' and an integer 'k'.
 * you are currently at position '(0, 0)' and you want to reach point '(m - 1, n
 * -1)' moving only down or right. return the number of paths where the sum of
 * the elements on the path is divisble by 'k'. since the answer may be very
 * large, return it modulo 10^9 + 7.
 */

int numberOfPaths(int **grid, int gridSize, int *gridColSize, int k) {
  const int mod = 1e9 + 7, m = gridSize, n = gridColSize[0];
  int **prev = (int **)malloc(n * sizeof(int *));
  int **curr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    prev[i] = (int *)calloc(k, sizeof(int));
    curr[i] = (int *)calloc(k, sizeof(int));
  }
  int sum = 0;
  for (int j = 0; j < n; j++) {
    sum = (sum + grid[0][j]) % k;
    prev[j][sum] = 1;
  }
  sum = grid[0][0] % k;
  for (int i = 1; i < m; i++) {
    sum = (sum + grid[i][0]) % k;
    memset(curr[0], 0, k * sizeof(int));
    curr[0][sum] = 1;
    for (int j = 1; j < n; j++) {
      memset(curr[j], 0, k * sizeof(int));
      int val = grid[i][j];
      for (int r = 0; r < k; r++) {
        int new = (r + val) % k;
        curr[j][new] = (prev[j][r] + curr[j - 1][r]) % mod;
      }
    }
    int **tmp = prev;
    prev = curr;
    curr = tmp;
  }
  int ans = prev[n - 1][0];
  for (int i = 0; i < n; i++) {
    free(prev[i]);
    free(curr[i]);
  }
  free(prev);
  free(curr);
  return ans;
}

int main() {
  int g1i[3][3] = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
  int g2i[1][2] = {{0, 0}};
  int g3i[3][4] = {{7, 3, 4, 9}, {2, 3, 6, 2}, {2, 3, 7, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n",
         numberOfPaths(g1->arr, g1->row_size, g1->col_size, 3)); // expect: 2
  printf("%d\n",
         numberOfPaths(g2->arr, g2->row_size, g2->col_size, 5)); // expect: 1
  printf("%d\n",
         numberOfPaths(g3->arr, g3->row_size, g3->col_size, 1)); // expect: 10
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
