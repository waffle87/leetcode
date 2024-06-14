// 2596. Check Knight Tour Configuration
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * there is a knight on an 'n * n' chessboard. in a valid config
 * the knight starts at the topl-left cell of the board and visits
 * every cell on the board exactly once. you are given an 'n * n'
 * integer matrix 'grid' consisting of distinct integers from the
 * range '[0, n * n - 1]' where 'grid[row][col]' indicates that
 * the cell '(row, col)' is the 'grid[row][col]'th cell that the
 * knight visited. the moves are 0-indexed. return true if grid
 * represents a valid configuration of the knight's movements or
 * false otherwise. note that a valid knight move consists of
 * moving two squares vertically and one square horizontally,
 * or two squares horizontally and one square vertically. the
 * figure illustrates all possible 8 moves of a knight from cell
 */

void check_path(int **grid, int r_len, int c_len, int r, int c, int next,
                int *check_cnt) {
  if (r < 0 || c < 0 || r >= r_len || c >= c_len || grid[r][c] == -1 ||
      grid[r][c] != next)
    return;
  grid[r][c] = -1;
  (*check_cnt)++;
  check_path(grid, r_len, c_len, r + 2, c + 1, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r + 1, c + 2, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r - 1, c + 2, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r - 2, c + 1, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r - 2, c - 1, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r - 1, c - 2, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r + 1, c - 2, next + 1, check_cnt);
  check_path(grid, r_len, c_len, r + 2, c - 1, next + 1, check_cnt);
}

bool checkValidGrid(int **grid, int grid_size, int *grid_col_size) {
  int check_cnt = 0;
  check_path(grid, grid_size, *grid_col_size, 0, 0, 0, &check_cnt);
  return check_cnt != grid_size * *grid_col_size ? false : true;
}

int main() {
  int g1[5][5] = {{0, 11, 16, 5, 20},
                  {17, 4, 19, 10, 15},
                  {12, 1, 8, 21, 6},
                  {3, 18, 23, 14, 9},
                  {24, 13, 2, 7, 22}};
  int g2[3][3] = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
  int gs1 = 5, gs2 = 3;
  int gcs1[] = {5, 5, 5, 5, 5}, gcs2[] = {3, 3, 3};
  printf("%d\n", checkValidGrid(g1, gs1, gcs1)); // expect: 1
  printf("%d\n", checkValidGrid(g2, gs2, gcs2)); // expect: 0
}
