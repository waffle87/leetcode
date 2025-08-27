// 1277. Count Square Submatrices with All Ones
#include "leetcode.h"

/*
 * given an 'm * n' matrix of ones and zeros, return how many square submatrices
 * have all ones.
 */

int countSquares(int **matrix, int matrixSize, int *matrixColSize) {
  int ans = 0;
  for (int i = 0; i < matrixSize; ++i)
    for (int j = 0; j < matrixColSize[i]; ans += matrix[i][j++])
      if (matrix[i][j] && i && j)
        matrix[i][j] += fmin(matrix[i - 1][j - 1],
                             fmin(matrix[i - 1][j], matrix[i][j - 1]));
  return ans;
}

int main() {
  int m1i[3][4] = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}},
      m2i[3][3] = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
  struct two_d_arr *m1 = two_d_arr_init(4, 3, m1i);
  struct two_d_arr *m2 = two_d_arr_init(3, 3, m2i);
  printf("%d\n",
         countSquares(m1->arr, m1->row_size, m2->col_size)); // expect: 15
  printf("%d\n",
         countSquares(m2->arr, m2->row_size, m2->col_size)); // expect: 7
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
