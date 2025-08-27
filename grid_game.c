// 2017. Grid Game
#include "leetcode.h"

/*
 * you are given a 0-indexed 2d array 'grid' of size '2 x n' where 'grid[r][c]'
 * represents the number of points at position '[r, c]' on the matrix. two
 * robots are playing a game on this matrix. both robots initially starts at
 * '(0, 0)' and want to reach '(1, n - 1)'. each robot may only move to the
 * right or down. at the start of the game, the first robot moves from '(0, 0)'
 * to '(1, n - 1)', collecting all the points. first robot wants to minimise the
 * number of points collected by the second robot. in contrast, the second robot
 * wants to maximise the number of points it collects. return the number of
 * points collected by the second robot
 */

long long gridGame(int **grid, int gridSize, int *gridColSize) {
  long long down = 0, up = 0;
  for (int i = 0; i < gridColSize[0] - 1; i++)
    down += grid[1][i];
  long long ans = down;
  for (int i = gridColSize[0] - 1; i; i--) {
    int cnt = fmax(down, up);
    if (cnt < ans)
      ans = cnt;
    up += grid[0][i];
    down -= grid[1][i - 1];
  }
  return up < ans ? up : ans;
}

int main() {
  int g1i[2][3] = {{2, 5, 4}, {1, 5, 1}};
  int g2i[2][3] = {{3, 3, 1}, {8, 5, 2}};
  int g3i[2][4] = {{1, 3, 1, 15}, {1, 3, 3, 1}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%lld\n", gridGame(g1->arr, g1->row_size, g1->col_size)); // expect: 4
  printf("%lld\n", gridGame(g2->arr, g2->row_size, g2->col_size)); // expect: 4
  printf("%lld\n", gridGame(g3->arr, g3->row_size, g3->col_size)); // expect: 7
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
