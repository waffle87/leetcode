// 304. Range Sum Query 2D - Immutable
#include "leetcode.h"

/*
 * given a 2d matrix 'matrix', handle multiple queries of the following type:
 * calculate the sum of the elements of 'matrix' inside the rectangle defined by
 * its upper left corner '(row1, col1)' and lower right corer '(row2, col2)'.
 * you must design an algorithm where 'sumRegion' works on 'O(1)' time
 * complexity.
 */

typedef struct {
  int **matrix;
  int matrixSize;
} NumMatrix;

NumMatrix *numMatrixCreate(int **matrix, int matrixSize, int *matrixColSize) {
  NumMatrix *obj = (NumMatrix *)malloc(matrixSize * sizeof(NumMatrix));
  obj->matrix = (int **)malloc((matrixSize + 1) * sizeof(NumMatrix));
  obj->matrixSize = matrixSize + 1;
  for (int i = 0; i <= matrixSize; i++)
    obj->matrix[i] = (int *)calloc(*matrixColSize + 1, sizeof(int));
  for (int i = 1; i <= matrixSize; i++)
    for (int j = 1; j <= *matrixColSize; j++)
      obj->matrix[i][j] = (obj->matrix[i - 1][j] + obj->matrix[i][j - 1] -
                           obj->matrix[i - 1][j - 1] + matrix[i - 1][j - 1]);
  return obj;
}

int numMatrixSumRegion(NumMatrix *obj, int row1, int col1, int row2, int col2) {
  return (obj->matrix[row2 + 1][col2 + 1] - obj->matrix[row2 + 1][col1] -
          obj->matrix[row1][col2 + 1] + obj->matrix[row1][col1]);
}

void numMatrixFree(NumMatrix *obj) {
  for (int i = 0; i < obj->matrixSize; i++)
    free(obj->matrix[i]);
  free(obj->matrix);
  free(obj);
}

int main() {
  int matrix_input[5][5] = {{3, 0, 1, 4, 2},
                            {5, 6, 3, 2, 1},
                            {1, 2, 0, 1, 5},
                            {4, 1, 0, 1, 7},
                            {1, 0, 3, 0, 5}};
  struct two_d_arr *matrix = two_d_arr_init(5, 5, matrix_input);
  NumMatrix *obj =
      numMatrixCreate(matrix->arr, matrix->row_size, matrix->col_size);
  printf("%d\n", numMatrixSumRegion(obj, 2, 1, 4, 3)); // expect: 8
  printf("%d\n", numMatrixSumRegion(obj, 1, 1, 2, 2)); // expect: 11
  printf("%d\n", numMatrixSumRegion(obj, 1, 2, 2, 4)); // expect: 12
  numMatrixFree(obj);
  two_d_arr_free(matrix);
}
