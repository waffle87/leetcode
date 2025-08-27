// 1072. Flip Columns For Maximum Number of Equal Rows
#include "leetcode.h"

/*
 * you are given an 'm x n' binary matrix 'matrix'. you choose any number of
 * columns in the matrix and flip every cell in that column (ie. change the
 * value of the cell from 0 to 1 or vice versa). return the maximum number of
 * rows that have all values equal after some number of flips.
 */

bool rows_equal(int *r1, int *r2, int n) {
  for (int i = 0; i < n; i++)
    if (r1[i] != r2[i])
      return false;
  return true;
}

void flip_row(int *row, int *flipped, int numCols) {
  for (int i = 0; i < numCols; i++)
    flipped[i] = 1 - row[i];
}

int maxEqualRowsAfterFlips(int **matrix, int matrixSize, int *matrixColSize) {
  int *flipped = (int *)malloc(matrixColSize[0] * sizeof(int)), ans = 0;
  for (int i = 0; i < matrixSize; i++) {
    int same_row_cnt = 0;
    flip_row(matrix[i], flipped, matrixColSize[0]);
    for (int j = 0; j < matrixSize; j++)
      if (rows_equal(matrix[i], matrix[j], matrixColSize[0]) ||
          rows_equal(flipped, matrix[j], matrixColSize[0]))
        same_row_cnt++;
    if (same_row_cnt > ans)
      ans = same_row_cnt;
  }
  free(flipped);
  return ans;
}

int main() {
  int m1i[2][2] = {{0, 1}, {1, 1}}, m2i[2][2] = {{0, 1}, {1, 0}},
      m3i[3][3] = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
  struct two_d_arr *m1 = two_d_arr_init(2, 2, m1i);
  struct two_d_arr *m2 = two_d_arr_init(2, 2, m2i);
  struct two_d_arr *m3 = two_d_arr_init(3, 3, m3i);
  printf("%d\n", maxEqualRowsAfterFlips(m1->arr, m1->row_size,
                                        m1->col_size)); // expect: 1
  printf("%d\n", maxEqualRowsAfterFlips(m2->arr, m2->row_size,
                                        m2->col_size)); // expect: 2
  printf("%d\n", maxEqualRowsAfterFlips(m3->arr, m3->row_size,
                                        m3->col_size)); // expect: 2
  two_d_arr_free(m1);
  two_d_arr_free(m2);
  two_d_arr_free(m3);
}
