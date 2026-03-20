// 3567. Minimum Absolute Difference in Sliding Submatrix
#include "leetcode.h"

/*
 * you are given an 'm x n' integer matrix 'grid' and an integer 'k'. for every
 * two contiguous 'k x k' submatrix of 'grid', compute the minimum absolute
 * difference between any two distinct values within that submatrix. return a 2d
 * array 'ans' of size '(m - k + 1) x (n - k + 1)' where 'ans[i][j]' is the
 * minimum absolute difference in the submatrix whose top-left corner is '(i,
 * j)' in 'grid'. note: if all elements in the submatrix have the same value,
 * the answer will be 0. a submatrix '(x1, y1, x2, y2)' is a matrix that is
 * formed by choosing all cells 'matrix[x][y]' where 'x1 <= x <= x2' and 'y1 <=
 * y <= y2'.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int compute_diff(int *arr, int n) {
  if (n < 2)
    return 0;
  int min_diff = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    int diff = arr[i + 1] - arr[i];
    if (diff > 0 && diff < min_diff)
      min_diff = diff;
  }
  return min_diff == INT_MAX ? 0 : min_diff;
}

int **minAbsDiff(int **grid, int gridSize, int *gridColSize, int k,
                 int *returnSize, int **returnColumnSizes) {
  int m = gridSize, n = gridColSize[0];
  int rm = m - k + 1, rn = n - k + 1;
  int **ans = (int **)malloc(rm * sizeof(int *));
  *returnColumnSizes = (int *)malloc(rm * sizeof(int));
  for (int i = 0; i < rm; i++) {
    ans[i] = (int *)malloc(rn * sizeof(int));
    (*returnColumnSizes)[i] = rn;
  }
  int *dp = (int *)malloc(k * k * sizeof(int));
  for (int r = 0; r < rm; r++)
    for (int c = 0; c < rn; c++) {
      int idx = 0;
      for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
          dp[idx++] = grid[r + i][c + j];
      qsort(dp, k * k, sizeof(int), cmp);
      ans[r][c] = compute_diff(dp, k * k);
    }
  free(dp);
  *returnSize = rm;
  return ans;
}

int main() {
  int g1i[2][2] = {{1, 8}, {3, -2}}, rs1, *rcs1;
  int g2i[1][2] = {{3, -1}}, rs2, *rcs2;
  int g3i[2][3] = {{1, -2, 3}, {2, 3, 5}}, rs3, *rcs3;
  int r1[1][1] = {{2}}, r2[1][2] = {{0, 0}}, r3[1][2] = {{1, 2}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int **mad1 = minAbsDiff(g1->arr, g1->row_size, g1->col_size, 2, &rs1, &rcs1);
  int **mad2 = minAbsDiff(g2->arr, g2->row_size, g2->col_size, 1, &rs2, &rcs2);
  int **mad3 = minAbsDiff(g3->arr, g3->row_size, g3->col_size, 2, &rs3, &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++) {
      printf("%d ", mad1[i][j]);
      assert(mad1[i][j] == r1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++) {
      printf("%d ", mad2[i][j]);
      assert(mad2[i][j] == r2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++) {
      printf("%d ", mad3[i][j]);
      assert(mad3[i][j] == r3[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(mad1[i]);
  free(mad1);
  for (int i = 0; i < rs2; i++)
    free(mad2[i]);
  free(mad2);
  for (int i = 0; i < rs3; i++)
    free(mad3[i]);
  free(mad3);
  free(rcs1);
  free(rcs2);
  free(rcs3);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
