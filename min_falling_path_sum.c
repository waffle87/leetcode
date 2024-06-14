// 931. Minimum Falling Path Sum
#include "leetcode.h"

/*
 * given an 'n * n' array of integers 'matrix', return the minimum sum of any
 * falling path through 'matrix'. a falling path starts at any element in the
 * first row and choose the element in the next row that is either directly
 * below or diagonally left/right. specifically, the next element from position
 * '(row, col)' will be '(row + 1, col - 1), (row + 1, col), or (row + 1, col +
 * 1)'.
 */

int minFallingPathSum(int **matrix, int matrix_size, int *matrix_col_size) {
  int **dp = (int **)malloc(sizeof(int *) * matrix_size);
  for (int i = 0; i < matrix_size; i++) {
    int *tmp = (int *)malloc(sizeof(int) * matrix_col_size[i]);
    memset(tmp, 0, matrix_col_size[i]);
    dp[i] = tmp;
  }
  for (int i = 0, n = matrix_col_size[0]; i < n; i++)
    dp[0][i] = matrix[0][i];
  for (int i = 1; i < matrix_size; i++) {
    for (int j = 0, n = matrix_col_size[i]; j < n; j++) {
      if (!j)
        dp[i][j] = matrix[i][j] + fmin(dp[i - 1][j], dp[i - 1][j + 1]);
      else if (j == n - 1)
        dp[i][j] = matrix[i][j] + fmin(dp[i - 1][j], dp[i - 1][j - 1]);
      else
        dp[i][j] = matrix[i][j] +
                   fmin(dp[i - 1][j - 1], fmin(dp[i - 1][j], dp[i - 1][j + 1]));
    }
  }
  int ans = INT_MAX;
  for (int i = 0, n = matrix_col_size[matrix_size - 1]; i < n; i++)
    ans = fmin(ans, dp[matrix_size - 1][i]);
  return ans;
}
