// 2684. Maximum Number of Moves in a Grid
#include "leetcode.h"

/*
 * given a 0-indexed array 'm * n' grid consisting of positive integers. you can
 * start at any cell in the first column of the matrix and traverse the grid in
 * the following way: from cell '(row, col)', you can move to any of the cells:
 * '(row - 1, col + 1), (row, col + 1), and (row + 1, col + 1)'. such that thhe
 * value of the cell you are moving to should be strictly bigger than the value
 * of the current cell. return the maximum number of moves that you can perform.
 */

int maxMoves(int **grid, int grid_size, int *grid_col_size) {
  int dp[grid_size][grid_col_size[0]], max = 0;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < grid_size; i++)
    dp[i][0] = 1;
  for (int j = 0; j < grid_col_size[0] - 1; j++)
    for (int i = 0; i < grid_size; i++) {
      if (!dp[i][j])
        continue;
      if (i && grid[i - 1][j + 1] > grid[i][j])
        dp[i - 1][j + 1] = fmax(dp[i][j] + 1, dp[i - 1][j + 1]);
      if (i + 1 < grid_size && grid[i + 1][j + 1] > grid[i][j])
        dp[i + 1][j + 1] = fmax(dp[i][j] + 1, dp[i + 1][j + 1]);
      if (grid[i][j + 1] > grid[i][j])
        dp[i][j + 1] = fmax(dp[i][j] + 1, dp[i][j + 1]);
    }
  for (int i = 0; i < grid_size; i++)
    for (int j = 0; j < grid_col_size[i]; j++)
      max = fmax(max, dp[i][j]);
  return max - 1;
}

int main() {
  int g1i[4][4] = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
  int g2i[3][3] = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};
  struct two_d_arr *g1 = two_d_arr_init(4, 4, g1i);
  struct two_d_arr *g2 = two_d_arr_init(3, 3, g2i);
  printf("%d\n", maxMoves(g1->arr, g1->row_size, g1->col_size)); // expect: 3
  printf("%d\n", maxMoves(g2->arr, g2->row_size, g2->col_size)); // expect: 0
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
