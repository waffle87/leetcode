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

// int dfs(int **dp, int **grid, int row_size, int *col_size, int row, int col,
//         int prev, int ith) {
int dfs(int **dp, int r, int c, int grid[r][c], int row_size, int *col_size,
        int row, int col, int prev, int ith) {
  if (row < 0 || row >= row_size || col < 0 || col > *col_size - 1 ||
      grid[row][col] <= prev)
    return ith;
  if (dp[row][col])
    return ith + dp[row][col] + 1;
  int tmp = dfs(dp, r, c, grid, row_size, col_size, row - 1, col + 1,
                grid[row][col], ith + 1);
  tmp = fmax(tmp, dfs(dp, r, c, grid, row_size, col_size, row, col + 1,
                      grid[row][col], ith + 1));
  tmp = fmax(tmp, dfs(dp, r, c, grid, row_size, col_size, row + 1, col,
                      grid[row][col], ith + 1));
  dp[row][col] = tmp - ith - 1;
  return tmp;
}

// int maxMoves(int **grid, int grid_size, int *grid_col_size) {
int maxMoves(int r, int c, int grid[r][c], int grid_size, int *grid_col_size) {
  int ans = 0;
  int **dp = malloc(sizeof(int *) * grid_size);
  for (int i = 0; i < grid_size; i++)
    dp[i] = calloc(*grid_col_size, sizeof(int));
  for (int i = 0; i < grid_size; i++)
    ans = fmax(ans, dfs(dp, r, c, grid, grid_size, grid_col_size, i, 0, 0, -1));
  return ans;
}

int main() {
  int g1[4][4] = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
  int g2[3][3] = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};
  int gcs1[] = {}, gcs2[] = {};
  printf("%d\n", maxMoves(4, 4, g1, 4, gcs1)); // expect: 3
  printf("%d\n", maxMoves(3, 3, g2, 3, gcs2)); // expect: 0
}
