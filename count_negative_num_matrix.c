// 1351. Count Negative Numbers in a Sorted Matrix
#include "leetcode.h"

// given an 'm x n' matrix 'grid' which is sorted in non-increasing order both
// row-wise and column-wise, return the number of negative numbers in 'grid'

int countNegatives(int **grid, int gridSize, int *gridColSize) {
  int r = gridSize - 1, c = 0, cnt = 0, n = gridColSize[0];
  while (r >= 0 && c < n) {
    if (grid[r][c] < 0)
      --r, cnt += n - c;
    else
      ++c;
  }
  return cnt;
}

int main() {
  int g1i[4][4] = {
      {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  int g2i[2][2] = {{3, 2}, {1, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n",
         countNegatives(g1->arr, g1->row_size, g1->col_size)); // expect: 8
  printf("%d\n",
         countNegatives(g2->arr, g2->row_size, g2->col_size)); // expect: 0
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
