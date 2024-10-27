// 1277. Count Square Submatrices with All Ones
#include "leetcode.h"

/*
 * given an 'm * n' matrix of ones and zeros, return how many square submatrices
 * have all ones.
 */

int countSquares(int **matrix, int matrixSize, int *matrixColSize) {
  if (!matrix || !matrixSize || !matrixColSize || !*matrixColSize)
    return 0;
  int rows = matrixSize, cols = *matrixColSize;
  int dp[rows][cols];
  for (int i = 0; i < rows; i++)
    dp[i][0] = matrix[i][0];
  for (int i = 0; i < cols; i++)
    dp[0][i] = matrix[0][i];
  for (int i = 1; i < rows; i++)
    for (int j = 1; j < rows; j++)
      dp[i][j] = matrix[i][j] == 1
                     ? fmin(dp[i - 1][j], fmin(dp[i][j - 1], dp[i - 1][j - 1]))
                     : 0;
  int cnt = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cnt += dp[i][j];
  return cnt;
}

int main() {
  int m1i[3][4] = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}},
      m2i[3][3] = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
  struct two_d_arr m1, m2;
  two_d_arr_init(&m1, 4, 3, m1i);
  two_d_arr_init(&m2, 3, 3, m2i);
  printf("%d\n", countSquares(m1.arr, m1.row_size, m2.col_size)); // expect: 15
  printf("%d\n", countSquares(m2.arr, m2.row_size, m2.col_size)); // expect: 7
  two_d_arr_free(&m1);
  two_d_arr_free(&m2);
}
