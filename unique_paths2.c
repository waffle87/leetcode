// 63. Unique Paths II
#include <stdlib.h>
#include <string.h>

/*
  You are given an m x n integer array grid. There is a robot initially located
  at the top-left corner (i.e., grid[0][0]). The robot tries to move to the
  bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
  down or right at any point in time.

  An obstacle and space are marked as 1 or 0 respectively in grid. A path that
  the robot takes cannot include any square that is an obstacle.

  Return the number of possible unique paths that the robot can take to reach
  the bottom-right corner.

  The testcases are generated so that the answer will be less than or equal to 2
  * 109.
 */

int uniquePathsWithObstacles(int **grid, int rSize, int cSize) {
  int **arrs = (int **)malloc(sizeof(int *) * rSize);
  for (int i = 0; i < rSize; i++) {
    arrs[i] = (int *)malloc(sizeof(int) * cSize);
    memset(arrs[i], 0, sizeof(int) * cSize);
  }
  for (int i = 0; i < rSize; i++)
    for (int j = 0; j < cSize; j++) {
      if (i == 0 && j == 0 && grid[i][j] == 0) {
        arrs[i][j] = 1;
        continue;
      }
      if (grid[i][j] == 1) {
        arrs[i][j] = 0;
        continue;
      }
      int count = 0;
      if (j - 1 > -1)
        count += arrs[i][j - 1];
      if (i - 1 > -1)
        count += arrs[i - 1][j];
      arrs[i][j] = count;
    }
  return arrs[rSize - 1][cSize - 1];
}
