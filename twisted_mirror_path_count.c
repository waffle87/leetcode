// 3665. Twisted Mirror Path Count
#include "leetcode.h"

int uniquePaths(int **grid, int gridSize, int *gridColSize) {
  static int mod = 1e9 + 7;
  int m = gridSize, n = gridColSize[0];
  int64_t **f = (int64_t **)malloc(n * sizeof(int64_t *));
  for (int i = 0; i < n; i++)
    f[i] = (int64_t *)calloc(2, sizeof(int64_t));
  f[0][0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (i > 0) {
        if (!grid[i - 1][j])
          f[j][0] = (f[j][0] + f[j][1]) % mod;
        else
          f[j][0] = f[j][1];
      }
      if (j > 0) {
        if (!grid[i][j - 1])
          f[j][1] = (f[j - 1][0] + f[j - 1][1]) % mod;
        else
          f[j][1] = f[j - 1][0];
      }
    }
  int ans = (int)((f[n - 1][0] + f[n - 1][1]) % mod);
  for (int i = 0; i < n; i++)
    free(f[i]);
  free(f);
  return ans;
}

int main() {
  int g1i[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
  int g2i[2][2] = {{0, 0}, {0, 0}};
  int g3i[2][3] = {{0, 1, 1}, {1, 1, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1 = uniquePaths(g1->arr, g1->row_size, g1->col_size);
  int r2 = uniquePaths(g2->arr, g2->row_size, g2->col_size);
  int r3 = uniquePaths(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 1);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
