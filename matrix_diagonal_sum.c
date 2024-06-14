// 1572. Matrix Diagonal Sum
#include <stdio.h>

/*
 * given a square matrix 'mat', return the sum of the matrix
 * diagonals. only include the sum of all the elements on the
 * primary diagonal and all the elements on the secondary
 * diagonal that are not part of the primary
 */

int diagonalSum(int **mat, int mat_size, int *mat_col_size) {
  int i = 0, j = mat_size - 1, sum = 0;
  while (i < mat_size) {
    sum += mat[i][i];
    i++;
  }
  i = 0;
  while (i < mat_size) {
    if (i != j)
      sum += mat[i][j];
    i++, j--;
  }
  return sum;
}

int main() {
  int m1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, ms1 = 3, mcs1[] = {};
  int m2[][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}},
      ms2 = 4, mcs2[] = {};
  int m3[][1] = {{5}}, ms3 = 1, mcs3[] = {};
  printf("%d\n", diagonalSum(m1, ms1, mcs1)); // expect: 25
  printf("%d\n", diagonalSum(m2, ms2, mcs2)); // expect: 8
  printf("%d\n", diagonalSum(m3, ms3, mcs3)); // expect: 5
}
