// 1504. Count Submatrices With All Ones
#include "leetcode.h"

/*
 * given an 'm x n' binary matrix 'mat', return the number of submatrices that
 * have all ones.
 */

int numSubmat(int **mat, int matSize, int *matColSize) {
  int m = matColSize[0], ans = 0;
  int *dp = (int *)calloc(m, sizeof(int));
  for (int i = 0; i < matSize; i++) {
    for (int j = 0; j < m; j++)
      dp[j] = mat[i][j] ? dp[j] + 1 : 0;
    int *sum = (int *)calloc(m, sizeof(int));
    int *stack = (int *)malloc(m * sizeof(int)), top = -1;
    for (int j = 0; j < m; j++) {
      while (top >= 0 && dp[stack[top]] >= dp[j])
        top--;
      if (top >= 0) {
        int curr = stack[top];
        sum[j] = sum[curr] + dp[j] * (j - curr);
      } else
        sum[j] = dp[j] * (j + 1);
      stack[++top] = j;
      ans += sum[j];
    }
    free(sum), free(stack);
  }
  free(dp);
  return ans;
}

int main() {
  int m1i[3][3] = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}},
      m2i[3][4] = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
  struct two_d_arr m1, m2;
  two_d_arr_init(&m1, ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  two_d_arr_init(&m2, ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  printf("%d\n", numSubmat(m1.arr, m1.row_size, m1.col_size)); // expect: 13
  printf("%d\n", numSubmat(m2.arr, m2.row_size, m2.col_size)); // expect: 24
  two_d_arr_free(&m1);
  two_d_arr_free(&m2);
}
