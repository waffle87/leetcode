// 1895. Largest Magic Square
#include "leetcode.h"
#include <math.h>

/*
 * a 'k x k' magic square is 'k x k' grid filled with integers such that every
 * row sum, every column sum, and both diagonal sums are all equal. the integers
 * in the magic square do not have to be distinct. every '1 x 1' grid is
 * trivally a magic square. given an 'm x n' integer 'grid', return the size
 * (ie. the side length 'k') of the largest magic square that can be found
 * within this grid.
 */

bool valid(int **grid, int i, int j, int k) {
  int sum = 0;
  for (int x = i; x < i + k; x++) {
    int s = 0;
    for (int y = j; y < j + k; y++)
      s += grid[x][y];
    if (x == i)
      sum = s;
    else if (sum != s)
      return false;
  }
  for (int y = j; y < j + k; y++) {
    int s = 0;
    for (int x = i; x < i + k; x++)
      s += grid[x][y];
    if (sum != s)
      return false;
  }
  int s = 0;
  for (int d = 0; d < k; d++)
    s += grid[i + d][j + d];
  if (sum != s)
    return false;
  s = 0;
  for (int d = 0; d < k; d++)
    s += grid[i + d][j + k - 1 - d];
  if (sum != s)
    return false;
  return true;
}

int largestMagicSquare(int **grid, int gridSize, int *gridColSize) {
  int ans = 1, n = gridSize, m = gridColSize[0];
  for (int k = 2; k <= fmin(n, m); k++)
    for (int i = 0; i + k <= n; i++)
      for (int j = 0; j + k <= m; j++)
        if (valid(grid, i, j, k))
          ans = k;
  return ans;
}

int main() {
  int g1i[4][5] = {
      {7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
  int g2i[3][4] = {{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n",
         largestMagicSquare(g1->arr, g1->row_size, g1->col_size)); // expect: 3
  printf("%d\n",
         largestMagicSquare(g2->arr, g2->row_size, g2->col_size)); // expect: 2
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
