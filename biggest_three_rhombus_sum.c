// 1878. Get Biggest Three Rhombus Sums in a Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' integer matrix 'grid'. a rhombus sum is the sum of
 * the elements that form the border of regular rhombus shape in 'grid'. the
 * rhombus must have the shape of a square rotated 45 degrees with each of the
 * corners centered in a grid cell.
 */

void add_val(int *top, int val) {
  if (val == top[0] || val == top[1] || val == top[2])
    return;
  if (val > top[0]) {
    top[2] = top[1];
    top[1] = top[0];
    top[0] = val;
  } else if (val > top[1]) {
    top[2] = top[1];
    top[1] = val;
  } else if (val > top[2])
    top[2] = val;
}

int *getBiggestThree(int **grid, int gridSize, int *gridColSize,
                     int *returnSize) {
  int m = gridSize, n = gridColSize[0];
  int top[3] = {-1, -1, -1};
  for (int r = 0; r < m; ++r)
    for (int c = 0; c < n; ++c) {
      add_val(top, grid[r][c]);
      int l = 1;
      while (r + 2 * l < m && c - l >= 0 && c + l < n) {
        int s = 0;
        for (int i = 0; i < l; i++)
          s += grid[r + i][c + i];
        for (int i = 0; i < l; i++)
          s += grid[r + l + i][c + l + i];
        for (int i = 0; i < l; i++)
          s += grid[r + 2 * l - i][c - i];
        for (int i = 0; i < l; i++)
          s += grid[r + l - i][c - l + i];
        add_val(top, s);
        l++;
      }
    }
  int cnt = 0;
  for (int i = 0; i < 3; i++)
    if (top[i] != -1)
      cnt++;
  *returnSize = cnt;
  int *ans = (int *)malloc(cnt * sizeof(int));
  memcpy(ans, top, cnt * sizeof(int));
  return ans;
}

int main() {
  int g1i[6][6] = {{3, 4, 5, 1, 3},
                   {3, 3, 4, 2, 3},
                   {20, 30, 200, 40, 10},
                   {1, 5, 5, 4, 1},
                   {4, 3, 2, 2, 5}};
  int g2i[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int g3i[1][3] = {{7, 7, 7}};
  int r1[] = {228, 219, 216}, rs1;
  int r2[] = {20, 9, 8}, rs2;
  int r3[] = {7}, rs3;
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int *gbt1 = getBiggestThree(g1->arr, g1->row_size, g1->col_size, &rs1);
  int *gbt2 = getBiggestThree(g2->arr, g2->row_size, g2->col_size, &rs2);
  int *gbt3 = getBiggestThree(g3->arr, g3->row_size, g3->col_size, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", gbt1[i]);
    assert(gbt1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", gbt2[i]);
    assert(gbt2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", gbt3[i]);
    assert(gbt3[i] == r3[i]);
  }
  printf("\n");
  free(gbt1);
  free(gbt2);
  free(gbt3);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
