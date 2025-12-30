// 840. Magic Squares In Grid
#include "leetcode.h"

/*
 * a 3 * 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
 * such that each row, column, and both diagonals all have the same sum. given a
 * row x col 'grid' of integers, how many 3 x 3 contiguous magic square subgrids
 * are there? note, while a magic square can only contain numbers from 1 to 9,
 * 'grid' may contain numbers up to 15.
 */

bool valid(int i, int j, int **grid) {
  int cnt[10] = {0};
  for (int x = 0; x < 3; ++x)
    for (int y = 0; y < 3; ++y) {
      int curr = grid[i + x][j + y];
      if (curr < 1 || curr > 9 || cnt[curr] > 0)
        return false;
      cnt[curr]++;
    }
  int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
  for (int x = 0; x < 3; ++x)
    if (sum != (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2]))
      return false;
  for (int y = 0; y < 3; ++y)
    if (sum != (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y]))
      return false;
  if (sum != (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]))
    return false;
  if (sum != (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2]))
    return false;
  return true;
}

int numMagicSquaresInside(int **grid, int gridSize, int *gridColSize) {
  int cnt = 0, n = gridSize, m = gridColSize[0];
  if (n < 3 || m < 3)
    return 0;
  for (int i = 0; i <= n - 3; ++i)
    for (int j = 0; j <= m - 3; ++j)
      if (valid(i, j, grid))
        cnt++;
  return cnt;
}

int main() {
  int g1i[3][4] = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  int g2i[1][1] = {{8}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n", numMagicSquaresInside(g1->arr, g1->row_size,
                                       g1->col_size)); // expect: 1
  printf("%d\n", numMagicSquaresInside(g2->arr, g2->row_size,
                                       g2->col_size)); // expect: 1
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
