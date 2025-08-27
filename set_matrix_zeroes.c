// 73. Set Matrix Zeroes
#include "leetcode.h"

/*
 * given an 'm x n' integer 'matrix', if an element is '0', set its entire row
 * and columns to '0's. you must do it in place
 */

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
  bool *r = (bool *)calloc(matrixSize, sizeof(bool));
  bool *c = (bool *)calloc(*matrixColSize, sizeof(bool));
  for (int i = 0; i < matrixSize; ++i)
    for (int j = 0; j < *matrixColSize; ++j)
      if (!matrix[i][j]) {
        r[i] = true;
        r[j] = true;
      }
  for (int i = 0; i < matrixSize; ++i)
    for (int j = 0; j < *matrixColSize; ++j)
      if (r[i] || c[j])
        matrix[i][j] = 0;
}

int main() {
  int m1i[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
      m2i[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  setZeroes(m1->arr, m1->row_size, m1->col_size);
  setZeroes(m2->arr, m2->row_size, m2->col_size);
  for (int i = 0; i < m1->row_size; i++) {
    for (int j = 0; j < m1->col_size[i]; j++)
      printf("%d ", m1i[i][j]); // expect: [[1,0,1],[0,0,0],[1,0,1]]
    printf("\n");
  }
  for (int i = 0; i < m2->row_size; i++) {
    for (int j = 0; j < m2->col_size[i]; j++)
      printf("%d ", m2i[i][j]); // expect: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
    printf("\n");
  }
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
