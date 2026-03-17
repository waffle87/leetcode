// 1727. Largest Submatrix With Rearrangements
#include "leetcode.h"

/*
 * you are given a binary matrix of size 'm * n' and you are allowed to
 * rearrange the columns of the 'matrix' in any order. return the area of the
 * largest submatrix within 'matrix' where every element of the submatrix is 1
 * after reordering columns optimally
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int largestSubmatrix(int **matrix, int matrixSize, int *matrixColSize) {
  int m = matrixSize, n = matrixColSize[0];
  int **hist = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; ++i) {
    hist[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) {
      if (!i)
        hist[i][j] = matrix[i][j];
      else
        hist[i][j] = !matrix[i][j] ? 0 : hist[i - 1][j] + 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    qsort(hist[i], n, sizeof(int), cmp);
    for (int j = 0; j < n; ++j)
      ans = fmax(ans, hist[i][j] * (n - j));
  }
  for (int i = 0; i < m; ++i)
    free(hist[i]);
  free(hist);
  return ans;
}

int main() {
  int m1i[3][3] = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  int m2i[1][5] = {{1, 0, 1, 0, 1}};
  int m3i[2][3] = {{1, 1, 0}, {1, 0, 1}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  struct two_d_arr *m3 =
      two_d_arr_init(ARRAY_SIZE(m3i), ARRAY_SIZE(m3i[0]), m3i);
  int r1 = largestSubmatrix(m1->arr, m1->row_size, m1->col_size);
  int r2 = largestSubmatrix(m2->arr, m2->row_size, m2->col_size);
  int r3 = largestSubmatrix(m3->arr, m3->row_size, m3->col_size);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r3);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 2);
}
