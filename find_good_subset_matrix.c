// 2732. Find a Good Subset of the Matrix
#include "leetcode.h"

/*
 * you are given a 0-indexed 'm * n' binary matrix 'grid'. let us call a
 * non-empty subset of rows good if the sum of each column of the subset is at
 * most half of the length of the subset. more formally, if the length of the
 * chosen subset of rows is 'k', then the sum of each column should be at most
 * 'floor(k / 2)'. return an integer array that contains row indices of a good
 * subset sorted in ascending order. if there are multiple answers, you can
 * return any of them. if there are no good subsets, return an empty array. a
 * subset of rows of the matrix 'grid' is any matrix that can be obtained by
 * deleting some (possibly none) rows from 'grid'
 */

static uint encode(const int *row, int rowSize) {
  uint x = 0;
  for (int i = 0; i < rowSize; ++i) {
    if (!row[i])
      continue;
    x |= 1 << i;
  }
  return x;
}

int *goodSubsetofBinaryMatrix(int **grid, int gridSize, int *gridColSize,
                              int *returnSize) {
  const int n = 1 << *gridColSize;
  int *idx = (int *)malloc(n * sizeof(int));
  memset(idx, -1, n * sizeof(int));
  for (int i = gridSize - 1; i >= 0; --i)
    idx[encode(grid[i], gridSize)] = i;
  if (idx[0] != -1) {
    *returnSize = 1;
    int *ans = (int *)malloc(*returnSize * sizeof(int));
    ans[0] = idx[0];
    free(idx);
    return ans;
  }
  for (int a = 1; a < n; ++a) {
    if (idx[a] == -1)
      continue;
    for (int b = a + 1; b < n; ++b) {
      if (idx[b] == -1)
        continue;
      if (!(a & b)) {
        int row_a = idx[a];
        int row_b = idx[b];
        free(idx);
        *returnSize = 2;
        int *ans = (int *)malloc(*returnSize * sizeof(int));
        ans[0] = fmin(row_a, row_b);
        ans[1] = fmax(row_a, row_b);
        return ans;
      }
    }
  }
  *returnSize = 0;
  free(idx);
  return NULL;
}

int main() {
  int g1i[3][4] = {{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 1, 1}}, rs1;
  int g2i[1][1] = {{0}}, rs2;
  int g3i[2][3] = {{1, 1, 1}, {1, 1, 1}}, rs3;
  struct two_d_arr g1, g2, g3;
  two_d_arr_init(&g1, 3, 4, g1i);
  two_d_arr_init(&g2, 1, 1, g2i);
  two_d_arr_init(&g3, 2, 3, g3i);
  int *gsobm1 =
      goodSubsetofBinaryMatrix(g1.arr, g1.row_size, g1.col_size, &rs1);
  int *gsobm2 =
      goodSubsetofBinaryMatrix(g2.arr, g2.row_size, g2.col_size, &rs2);
  int *gsobm3 =
      goodSubsetofBinaryMatrix(g3.arr, g3.row_size, g3.col_size, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gsobm1[i]); // expect: 0 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gsobm2[i]); // expect: 0
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", gsobm3[i]); // expect: null
  printf("\n");
  free(gsobm1), two_d_arr_free(&g1);
  free(gsobm2), two_d_arr_free(&g2);
  free(gsobm3), two_d_arr_free(&g3);
}
