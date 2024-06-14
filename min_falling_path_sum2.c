// 1289. Minimum Falling Path Sum II
#include "leetcode.h"

/*
 * given a 'n * n' integer matrix 'grid' return the minimum sum of a falling
 * path with non zero shifts. a falling path with non zero shifts is a choice of
 * exactly one element from each row of 'grid' such that no two elements chosen
 * in adjacent rows are in the same column
 */

int min(int **grid, int gridSize, int *gridColSize, int curr) {
  int min = INT_MAX;
  for (int i = 0; i < curr; i++)
    if (min > grid[gridSize][i])
      min = grid[gridSize][i];
  for (int i = curr + 1; i < *gridColSize; i++)
    if (min > grid[gridSize][i])
      min = grid[gridSize][i];
  return min;
}

int minFallingPathSum(int **grid, int gridSize, int *gridColSize) {
  int **list = (int **)malloc(sizeof(int *) * 2);
  list[0] = malloc(sizeof(int) * *gridColSize);
  list[1] = malloc(sizeof(int) * *gridColSize);
  gridSize--;
  int k = gridSize % 2;
  for (int i = 0; i < *gridColSize; i++)
    list[k][i] = grid[gridSize][i];
  gridSize--;
  int other = k;
  while (gridSize >= 0) {
    k = gridSize % 2;
    for (int i = 0; i < *gridColSize; i++)
      list[k][i] = min(list, other, gridColSize, i) + grid[gridSize][i];
    other = k;
    gridSize--;
  }
  int ans = min(list, 0, gridColSize, *gridColSize);
  free(list[0]), free(list[1]), free(list);
  return ans;
}
