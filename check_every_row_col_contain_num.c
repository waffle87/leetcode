// 2133. Check if Every Row and Column Contains All Numbers
#include "leetcode.h"

/*
 * an 'n x n' matrix is valid if every row and every column contains all the
 * integers from 1 to 'n'. given an 'n x n' matrix, return true if the matrix is
 * valid, otherwise return false.
 */

bool checkValid(int **matrix, int matrixSize, int *matrixColSize) {
  for (int i = 0; i < matrixSize; i++) {
    int row = 1, col = 1, mask = 1;
    for (int j = 0; j < matrixSize; j++) {
      row ^= 1 << matrix[i][j];
      col ^= 1 << matrix[j][i];
      mask |= 1 << (j + 1);
    }
    if (row ^ mask || col ^ mask)
      return false;
  }
  return true;
}

int main() {
  int m1i[3][3] = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}},
      m2i[3][3] = {{1, 1, 1}, {1, 2, 3}, {1, 2, 3}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  printf("%d\n", checkValid(m1->arr, m1->row_size, m1->col_size)); // expect: 1
  printf("%d\n", checkValid(m2->arr, m2->row_size, m2->col_size)); // expect: 0
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
