// 1536. Minimum Swaps to Arrange a Binary Grid
#include "leetcode.h"

/*
 * given an 'n x n' binary 'grid', in one step you can choose two adjacent rows
 * of the grid and swap them. a grid is said to be valid if all the cells above
 * the main diagonal are zeros. return the minimum number of steps needed to
 * make the grid valid, or -1 if the grid cannot be made valid. the main
 * diagonal of a grid is the diagonal that starts at cell '(1, 1)' and ends at
 * '(n, n)'.
 */

int minSwaps(int **grid, int gridSize, int *gridColSize) {
  int n = gridSize, ans = 0;
  int *pos = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    pos[i] = -1;
    for (int j = n - 1; j >= 0; --j)
      if (grid[i][j]) {
        pos[i] = j;
        break;
      }
  }
  for (int i = 0; i < n; ++i) {
    int k = -1;
    for (int j = i; j < n; ++j)
      if (pos[j] <= i) {
        ans += j - i;
        k = j;
        break;
      }
    if (k != -1)
      for (int j = k; j > i; --j) {
        int tmp = pos[j];
        pos[j] = pos[j - 1];
        pos[j - 1] = tmp;
      }
    else {
      free(pos);
      return -1;
    }
  }
  free(pos);
  return ans;
}

int main() {
  int g1i[3][3] = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
  int g2i[4][4] = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}};
  int g3i[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1 = minSwaps(g1->arr, g1->row_size, g1->col_size);
  int r2 = minSwaps(g2->arr, g2->row_size, g2->col_size);
  int r3 = minSwaps(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1); // expect: 3
  assert(r1 == 3);
  printf("%d\n", r2); // expect: -1
  assert(r2 == -1);
  printf("%d\n", r3); // expect: 0
  assert(r3 == 0);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
