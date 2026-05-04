// 48. Rotate Image
#include "leetcode.h"

/*
 * you are given an 'n x n' 2d 'matrix' representing an image, rotate the image
 * by 90 degrees (clockwise). you have to rotate the image in place, meaning you
 * have to modify the input 2d matrix directly. do not allocate another 2d
 * matrix and do the rotation.
 */

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
  int n = matrixSize;
  for (int i = 0; i < n >> 1; i++)
    for (int j = i; j < n - 1 - i; j++) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[~j + n][i];
      matrix[~j + n][i] = matrix[~i + n][~j + n];
      matrix[~i + n][~j + n] = matrix[j][~i + n];
      matrix[j][~i + n] = tmp;
    }
}

int main() {
  int m1i[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int r1[3][3] = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  int m2i[4][4] = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  int r2[4][4] = {
      {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  rotate(m1->arr, m1->row_size, m1->col_size);
  rotate(m2->arr, m2->row_size, m2->col_size);
  for (int i = 0; i < m1->row_size; i++) {
    for (int j = 0; j < m1->col_size[i]; j++) {
      printf("%d ", m1->arr[i][j]);
      assert(m1->arr[i][j] == r1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < m2->row_size; i++) {
    for (int j = 0; j < m2->col_size[i]; j++) {
      printf("%d ", m2->arr[i][j]);
      assert(m2->arr[i][j] == r2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
