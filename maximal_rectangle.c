// 85. Maximal Rectangle
#include "leetcode.h"

/*
 * given a 'rows * cols' binary 'matrix' filled with 0's and 1's, find the
 * largest rectangle containing only 1's and return its area.
 */

int max_area(int *heights, int heights_size) {
  int *stack = (int *)malloc(heights_size * sizeof(int));
  int depth = 0, width = 0, res = 0, i = 0, tmp = 0;
  if (!heights || !heights_size)
    return 0;
  while (i < heights_size) {
    if (!depth || heights[i] >= heights[stack[depth - 1]]) {
      stack[depth] = i;
      depth++, i++;
    } else {
      while (depth && heights[stack[depth - 1]] > heights[i]) {
        width = depth > 1 ? i - stack[depth - 2] - 1 : i;
        tmp = heights[stack[depth - 1]] * width;
        if (res < tmp)
          res = tmp;
        depth--;
      }
    }
  }
  while (depth) {
    width = depth > 1 ? i - stack[depth - 2] - 1 : i;
    tmp = heights[stack[depth - 1]] * width;
    if (res < tmp)
      res = tmp;
    depth--;
  }
  free(stack);
  return res;
}

int maximalRectangle(char **matrix, int matrix_size, int *matrix_col_size) {
  int *heights = (int *)calloc(*matrix_col_size, sizeof(int));
  int ans = 0;
  if (!matrix || !matrix_size)
    return 0;
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < *matrix_col_size; j++)
      heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
    int tmp = max_area(heights, *matrix_col_size);
    if (ans < tmp)
      ans = tmp;
  }
  free(heights);
  return ans;
}

int main() {
  char *matrix[4][5] = {{"1", "0", "1", "0", "0"},
                        {"1", "0", "1", "1", "1"},
                        {"1", "1", "1", "1", "1"},
                        {"1", "0", "0", "1", "0"}};
  int matrix_col_size = 5;
  printf("%d\n", maximalRectangle((char **)matrix, 4, &matrix_col_size));
}
