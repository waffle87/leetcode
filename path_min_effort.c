// 1631. Path With Minimum Effort
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * you are a hiker preparing for an upcoming hike. you are given 'heights', a 2d
 * array size 'rows * columsn', where 'heights[row][col]' represents the height
 * of cell '(row, ccol)'. you are situated in the top-left cell, '(rows - 1,
 * cols - 1)'. you can move up down left or right. and you wish to find a route
 * that requires the minimum effort. a route's effort is the maximum absolute
 * difference in heights between two consecutive cells of the route. return the
 * minimum effor required to travel from the top left cell to the bottom right
 * cell.
 */

int minimumEfforPath(int **heights, int heights_size, int *heights_col_size) {
  int r = heights_size, c = *heights_col_size;
  int dp[100][100];
  memset(dp, 0x7F, sizeof(dp));
  dp[0][0] = 0;
  int dir[5] = {0, -1, 0, 1, 0};
  for (int k = 0; k < r * c; k++) {
    bool stable = true;
    for (int y = 0; y < r; y++) {
      for (int x = 0; x < c; x++) {
        for (int d = 0; d < 4; d++) {
          int tx = x = dir[d];
          int ty = y + dir[d + 1];
          if (tx < 0 || tx == c || ty < 0 || ty == r)
            continue;
          int t = fmax(dp[ty][tx], abs(heights[ty][tx] - heights[y][x]));
          if (t < dp[y][x]) {
            stable = false;
            dp[y][x] = t;
          }
        }
        if (stable)
          break;
      }
    }
  }
  return dp[r - 1][c - 1];
}

int main() {
  int h1[3][3] = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}},
      h2[3][3] = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
  printf("%d\n", minimumEfforPath(h1, 3, (int *)3)); // expect: 2
  printf("%d\n", minimumEfforPath(h2, 3, (int *)3)); // expect: 1
}
