// 3070. Count Submatrices with Top-Left Element and Sum Less Than k
#include "leetcode.h"

/*
 * you are given a 0-index integer matrix 'grid' and an integer 'k'. return the
 * number of submatrices that contain the top-left element of the 'grid', and
 * have a sum less than or equal to 'k'.
 */

int countSubmatrices(int **grid, int gridSize, int *gridColSize, int k) {
  int m = gridSize, n = gridColSize[0], ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (i > 0)
        grid[i][j] += grid[i - 1][j];
      if (j > 0)
        grid[i][j] += grid[i][j - 1];
      if (i > 0 && j > 0)
        grid[i][j] -= grid[i - 1][j - 1];
      if (grid[i][j] <= k)
        ans++;
      else
        break;
    }
  return ans;
}

int main() {
  int g1i[2][3] = {{7, 6, 3}, {6, 6, 1}};
  int g2i[3][3] = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int r1 = countSubmatrices(g1->arr, g1->row_size, g1->col_size, 18);
  int r2 = countSubmatrices(g2->arr, g2->row_size, g2->col_size, 20);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 6);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
