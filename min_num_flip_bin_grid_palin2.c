// 3240. Minimum Number of Flips to Make Binary Grid Palindromic II
#include "leetcode.h"

/*
 * you are given an 'm x n' binary matrix 'grid'. a row or column is considered
 * palindromic if its values read the same forward as backward. you can flip any
 * number of cells in 'grid' from 0 to 1 or from 1 to 0. return the minimum
 * number of cells that need to be flipped to make all rows and columns
 * palindromic and the total number of 1s in 'grid' divisible by 4.
 */

int minFlips(int **grid, int gridSize, int *gridColSize) {
  int ans = 0, one = 0, diff = 0, m = gridSize, n = gridColSize[0];
  for (int i = 0; i < m / 2; ++i)
    for (int j = 0; j < n / 2; ++j) {
      int v = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] +
              grid[m - 1 - i][n - 1 - j];
      ans += fmin(v, 4 - v);
    }
  if (n % 2)
    for (int i = 0; i < m / 2; ++i) {
      diff += grid[i][n / 2] != grid[m - 1 - i][n / 2];
      one += grid[i][n / 2] + grid[m - 1 - i][n / 2];
    }
  if (m % 2)
    for (int j = 0; j < n / 2; ++j) {
      diff += grid[m / 2][j] != grid[m / 2][n - 1 - j];
      one += grid[m / 2][j] + grid[m / 2][n - 1 - j];
    }
  if (n % 2 && m % 2)
    ans += grid[m / 2][n / 2];
  if (!diff && one % 4)
    ans += 2;
  return ans + diff;
}

int main() {
  int g1i[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
      g2i[3][2] = {{0, 1}, {0, 1}, {0, 0}}, g3i[2][1] = {{1}, {1}};
  struct two_d_arr g1, g2, g3;
  two_d_arr_init(&g1, ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  two_d_arr_init(&g2, ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  two_d_arr_init(&g3, ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n", minFlips(g1.arr, g1.row_size, g1.col_size)); // expect: 3
  printf("%d\n", minFlips(g2.arr, g2.row_size, g2.col_size)); // expect: 2
  printf("%d\n", minFlips(g3.arr, g3.row_size, g3.col_size)); // expect: 2
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
  two_d_arr_free(&g3);
}
