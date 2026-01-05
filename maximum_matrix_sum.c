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
  long long total = 0;
  int min_abs = INT_MAX, neg_cnt = 0;
  for (int i = 0; i < matrixSize; i++)
    for (int j = 0; j < matrixColSize[i]; j++) {
      int curr = matrix[i][j];
      total += abs(curr);
      if (curr < 0)
        neg_cnt++;
      min_abs = fmin(min_abs, abs(curr));
    }
  if (neg_cnt % 2)
    total -= 2 * min_abs;
  return total;
}

int main() {
  int m1i[2][2] = {{1, -1}, {-1, 1}},
      m2i[3][3] = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
  struct two_d_arr *m1 = two_d_arr_init(2, 2, m1i);
  struct two_d_arr *m2 = two_d_arr_init(3, 3, m2i);
  printf("%lld\n",
         maxMatrixSum(m1->arr, m1->row_size, m1->col_size)); // expect: 4
  printf("%lld\n",
         maxMatrixSum(m2->arr, m2->row_size, m2->col_size)); // expect: 16
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
