// 1074. Number of Submatrices That Sum to Target
#include "leetcode.h"

/*
 * given a 'matrix' and 'target', return the number of non-empty submatrices
 * that sum to target. a submatrix 'x1, y1 x2, y2' is the set of all cells
 * 'matrix[x][y]' with 'x1 <= x <= x2' and 'y1 <= y <= y2'. two submatrices are
 * different if they have some coordinate that is different. for example if x1
 * != x1
 */

int numSubmatrixSumTarget(int **matrix, int matrix_size, int *matrix_col_size,
                          int target) {
  int r_size = matrix_col_size[0], dp[r_size], ans = 0, y = 0;
  while (y < matrix_size) {
    memset(dp, 0, sizeof(int) * r_size);
    for (int row = y; row < matrix_size; row++)
      for (int col = 0; col < r_size; col++)
        dp[col] += matrix[row][col];
    for (int col = 0; col < r_size; col++) {
      int sum = 0;
      for (int _col = col; _col < r_size; _col++) {
        sum += dp[_col];
        if (sum == target)
          ans++;
      }
    }
    y++;
  }
  return ans;
}
