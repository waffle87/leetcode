// 2033. Minimum Operations to Make a Uni-Value Grid
#include "leetcode.h"

/*
 * you are given a 2d integer 'grid' of size 'm x n' and an integer 'x'. in one
 * operation, you can add 'x' to or subtract 'x' from any element in the 'grid'.
 * a uni-value grid is a grid where all the elements of it are equal. return the
 * minimum number of operations to make the grid uni-valued. if it is not
 * possible, return -1.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minOperations(int **grid, int gridSize, int *gridColSize, int x) {
  int n = gridSize * (*gridColSize), idx = 0, mod = grid[0][0] % x;
  int *vals = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < gridSize; ++i)
    for (int j = 0; j < *gridColSize; ++j) {
      vals[idx] = grid[i][j];
      if (vals[idx++] % x != mod) {
        free(vals);
        return -1;
      }
    }
  qsort(vals, n, sizeof(int), cmp);
  int med = vals[n / 2], ans = 0;
  for (int i = 0; i < n; i++)
    ans += abs(med - vals[i]) / x;
  free(vals);
  return ans;
}

int main() {
  int g1i[2][2] = {{2, 4}, {6, 8}}, g2i[2][2] = {{1, 5}, {2, 3}},
      g3i[2][2] = {{1, 2}, {3, 4}};
  struct two_d_arr g1, g2, g3;
  two_d_arr_init(&g1, ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  two_d_arr_init(&g2, ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  two_d_arr_init(&g3, ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n",
         minOperations(g1.arr, g1.row_size, g1.col_size, 2)); // expect: 4
  printf("%d\n",
         minOperations(g2.arr, g2.row_size, g2.col_size, 1)); // expect: 5
  printf("%d\n",
         minOperations(g3.arr, g3.row_size, g3.col_size, 2)); // expect: -1
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
  two_d_arr_free(&g3);
}
