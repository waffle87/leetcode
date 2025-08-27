// 3195. Find the Minimum Area to Cover All Ones I
#include "leetcode.h"

/*
 * you are given a 2d binary array 'grid'. find a rectangle with horizontal and
 * vertical lines with the smallest area, such that all the 1's in 'grid' lie
 * inside this rectangle. return the minimum possible area of the rectangle.
 */

int minimumArea(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0];
  int min_row = m, max_row = -1;
  int min_col = n, max_col = -1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j]) {
        if (i < min_row)
          min_row = i;
        if (i > max_row)
          max_row = i;
        if (j < min_col)
          min_col = j;
        if (j > max_col)
          max_col = j;
      }
  return (max_row - min_row + 1) * (max_col - min_col + 1);
}

int main() {
  int g1i[2][3] = {{0, 1, 0}, {1, 0, 1}}, g2i[2][2] = {{1, 0}, {0, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n", minimumArea(g1->arr, g1->row_size, g1->col_size)); // expect: 6
  printf("%d\n", minimumArea(g2->arr, g2->row_size, g2->col_size)); // expect: 1
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
