// 1727. Largest Submatrix With Rearrangements
#include "leetcode.h"

/*
 * you are given a binary matrix of size 'm * n' and you are allowed to
 * rearrange the columns of the 'matrix' in any order. return the area of the
 * largest submatrix within 'matrix' where every element of the submatrix is 1
 * after reordering columns optimally
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int largestSubmatrix(int **matrix, int matrix_size, int *matrix_col_size) {
  int **heights = (int **)malloc(matrix_size * sizeof(int *)), max_area = 0;
  for (int i = 0; i < matrix_size; i++) {
    heights[i] = (int *)malloc(*matrix_col_size * sizeof(int));
    for (int j = 0; j < *matrix_col_size; j++) {
      if (!i)
        heights[i][j] = matrix[i][j];
      else
        heights[i][j] = (matrix[i][j] == 1) ? heights[i - 1][j] + 1 : 0;
    }
  }
  for (int i = 0; i < matrix_size; i++) {
    qsort(heights[i], *matrix_col_size, sizeof(int), cmp);
    for (int j = 0; j < *matrix_col_size; j++) {
      int width = *matrix_col_size - j, height = heights[i][j];
      max_area = fmax(max_area, width * height);
    }
  }
  for (int i = 0; i < matrix_size; i++)
    free(heights[i]);
  free(heights);
  return max_area;
}
