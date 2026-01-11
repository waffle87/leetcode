// 85. Maximal Rectangle
#include "leetcode.h"

/*
 * given a 'rows * cols' binary 'matrix' filled with 0's and 1's, find the
 * largest rectangle containing only 1's and return its area.
 */

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize) {
  if (!matrixSize || !*matrixColSize)
    return 0;
  int ans = 0;
  int *height = (int *)calloc(*matrixColSize, sizeof(int));
  int *left = (int *)calloc(*matrixColSize, sizeof(int));
  int *right = (int *)malloc(*matrixColSize * sizeof(int));
  for (int i = 0; i < *matrixColSize; i++)
    right[i] = *matrixColSize;
  for (int i = 0; i < matrixSize; i++) {
    int curr_l = 0, curr_r = *matrixColSize;
    for (int j = 0; j < *matrixColSize; j++) {
      if (matrix[i][j] == '1') {
        height[j]++;
        left[j] = left[j] > curr_l ? left[j] : curr_l;
      } else {
        height[j] = left[j] = 0;
        curr_l = j + 1;
      }
    }
    for (int j = *matrixColSize - 1; j >= 0; j--) {
      if (matrix[i][j] == '1')
        right[j] = right[j] < curr_r ? right[j] : curr_r;
      else {
        right[j] = *matrixColSize;
        curr_r = j;
      }
    }
    for (int j = 0; j < *matrixColSize; j++)
      ans = fmax(ans, (right[j] - left[j]) * height[j]);
  }
  free(height);
  free(left);
  free(right);
  return ans;
}

int main() {
  char *m1[4][5] = {{"1", "0", "1", "0", "0"},
                    {"1", "0", "1", "1", "1"},
                    {"1", "1", "1", "1", "1"},
                    {"1", "0", "0", "1", "0"}};
  char *m2[1][1] = {{"0"}}, *m3[1][1] = {{"1"}};
  printf("%d\n", maximalRectangle((char **)m1, ARRAY_SIZE(m1),
                                  ARRAY_SIZE(m1i[0]))); // expect: 6
  printf("%d\n", maximalRectangle((char **)m2, ARRAY_SIZE(m2),
                                  ARRAY_SIZE(m2i[0]))); // expect: 0
  printf("%d\n", maximalRectangle((char **)m3, ARRAY_SIZE(m3),
                                  ARRAY_SIZE(m3i[0]))); // expect: 1
}
