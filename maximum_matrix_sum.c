// 1975. Maximum Matrix Sum
#include "leetcode.h"

/*
 * you are given an 'n x n' integer 'matrix'. you can do the following operation
 * any number of times: choose any two adjacent elements of 'matrix' and
 * multiply each of them by -1. two elements are considered adjacent if and only
 * if they share a border. your goal is to maximise the summation of the
 * matrix's elements. return maximum sum of the matrix's elements using the
 * afforementioned operation.
 */

long long maxMatrixSum(int **matrix, int matrixSize, int *matrixColSize) {
  long long sum = 0;
  int neg_cnt = 0, min = INT_MAX;
  for (int i = 0; i < matrixSize; i++)
    for (int j = 0; j < matrixSize; j++) {
      if (matrix[i][j] < 0)
        neg_cnt++;
      if (abs(matrix[i][j]) < min)
        min = abs(matrix[i][j]);
      sum += abs(matrix[i][j]);
    }
  if (!(neg_cnt % 2))
    return sum;
  return sum - (2 * min);
}

int main() {
  int m1i[2][2] = {{1, -1}, {-1, 1}},
      m2i[3][3] = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
  struct two_d_arr m1, m2;
  two_d_arr_init(&m1, 2, 2, m1i);
  two_d_arr_init(&m2, 3, 3, m2i);
  printf("%lld\n", maxMatrixSum(m1.arr, m1.row_size, m1.col_size)); // expect: 4
  printf("%lld\n", maxMatrixSum(m2.arr, m2.row_size, m2.col_size)); // expect:
                                                                    // 16
  two_d_arr_free(&m1);
  two_d_arr_free(&m2);
}
