// 1738. Find Kth Largest XOR Coordinate Value
#include "leetcode.h"

/*
 * you are given a 2d 'matrix' of size 'm x n' consisting of non-negative
 * integers. you are also given an integer 'k'. the value of coordinate '(a, b)'
 * of  the matrix is the xor of all 'matrix[i][j]' where '0 <= i <= a < m' and
 * '0 <= j <= b < n' (0-indexed). find the k'th largest value (1-indexed) of all
 * the coordinates of 'matrix'.
 */

int cmp(const void *a, const void *b) { return *(int *)a > *(int *)b; }

int kthLargestValue(int **matrix, int matrixSize, int *matrixColSize, int k) {
  int map[matrixSize * (*matrixColSize)], idx = 0;
  for (int i = 0; i < matrixSize; i++)
    for (int j = 0; j < *matrixColSize; j++) {
      if (j > 0)
        matrix[i][j] ^= matrix[i][j - 1];
      if (i > 0)
        matrix[i][j] ^= matrix[i - 1][j];
      if (i > 0 && j > 0)
        matrix[i][j] ^= matrix[i - 1][j - 1];
      map[idx++] = matrix[i][j];
    }
  qsort(map, idx, sizeof(int), cmp);
  return map[idx - k];
}

int main() {
  int matrix_input[2][2] = {{5, 2}, {1, 6}};
  struct two_d_arr *matrix = two_d_arr_init(
      ARRAY_SIZE(matrix_input), ARRAY_SIZE(matrix_input[0]), matrix_input);
  printf("%d\n",
         kthLargestValue(matrix->arr, matrix->row_size, matrix->col_size,
                         1)); // expect: 7
  printf("%d\n",
         kthLargestValue(matrix->arr, matrix->row_size, matrix->col_size,
                         2)); // expect: 5
  printf("%d\n",
         kthLargestValue(matrix->arr, matrix->row_size, matrix->col_size,
                         3)); // expect: 4
  two_d_arr_free(matrix);
}
