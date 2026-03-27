// 2946. Matrix Similarity After Cyclic Shifts
#include "leetcode.h"

/*
 * you are given an 'm x n' integer matrix 'mat' and an integer 'k'. the matrix
 * rows are 0-indexed. the following process happens 'k' times: even indexed
 * rows are cyclically shifted to the left. odd indexed rows are cyclically
 * shifted to the right. return true if the final modified matrix after 'k'
 * steps is identical to the original matrix and false otherwise.
 */

bool areSimilar(int **mat, int matSize, int *matColSize, int k) {
  int m = matSize, n = matColSize[0];
  k %= n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (mat[i][j] != mat[i][(j + k) % n])
        return false;
  return true;
}

int main() {
  int m1i[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int m2i[3][4] = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
  int m3i[2][2] = {{2, 2}, {2, 2}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  struct two_d_arr *m3 =
      two_d_arr_init(ARRAY_SIZE(m3i), ARRAY_SIZE(m3i[0]), m3i);
  bool r1 = areSimilar(m1->arr, m1->row_size, m1->col_size, 4);
  bool r2 = areSimilar(m2->arr, m2->row_size, m2->col_size, 2);
  bool r3 = areSimilar(m3->arr, m3->row_size, m3->col_size, 3);
  printf("%d\n", r1);
  assert(r1 == false);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == true);
  two_d_arr_free(m1);
  two_d_arr_free(m2);
  two_d_arr_free(m3);
}
