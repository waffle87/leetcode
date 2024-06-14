// 74. Search a 2D Matrix
#include <stdbool.h>
#include <stdio.h>

/*
 * given an 'm x n' integer matrix 'matrxi' with the following two properties:
 * - each row is sorted in non-decreasing order.
 * - the first integer of each row is greater than the last integer of the
 * previous row. given an integer 'target', return true if 'target' is in
 * 'matrix', or false otherwise. you must write a solution in 'O(log(m * n))'
 * time complexity
 */

bool searchMatrix(int **matrix, int matrix_size, int *matrix_col_size,
                  int target) {
  int i = 0, j = *matrix_col_size * matrix_size - 1;
  while (i <= j) {
    int mid = (i + j) / 2;
    int row = mid / *matrix_col_size;
    int col = mid % *matrix_col_size;
    if (matrix[row][col] < target)
      i = mid + 1;
    else if (matrix[row][col] > target)
      j = mid - 1;
    else
      return true;
  }
  return false;
}

int main() {
  int matrix[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  printf("%d\n", searchMatrix(matrix, 4, NULL, 3));  // expect: 1
  printf("%d\n", searchMatrix(matrix, 4, NULL, 13)); // expect: 0
}
