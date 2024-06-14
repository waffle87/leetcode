// 2482. Difference Between Ones and Zeros in Row and Column
#include "leetcode.h"

/*
 * given a 0-indexed 'm * n' binary matrix 'grid', where the difference matrix
 * 'diff' is created with the following procedure: let the number of ones in
 * i'th row be 'ones_row[i]', let the number of ones in the j'th column be
 * 'ones_col[j]', let the number of zeros in the i'th row be 'zeros_row[i]', let
 * the number of zeros in the j'th column be 'zeros_col[j]'. 'diff[i][j] =
 * ones_row[i] + ones_col[j] - zeros_row[i] - zeros_col[j]'. return the
 * difference matrix 'diff'
 */

int **onesMinusZeros(int **grid, int grid_size, int *grid_col_size,
                     int *return_size, int **return_col_size) {
  int m = grid_size, n = *grid_col_size;
  int **ans = malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++)
    ans[i] = malloc(n * sizeof(int));
  int *row_one = calloc(m, sizeof(int));
  int *col_one = calloc(n, sizeof(int));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == 1)
        row_one[i]++, col_one[j]++;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      ans[i][j] = 2 * row_one[i] + 2 * col_one[j] - m - n;
  *return_size = m;
  *return_col_size = malloc(m * sizeof(int));
  for (int i = 0; i < m; i++)
    return_col_size[0][i] = n;
  free(row_one), free(col_one);
  return ans;
}
