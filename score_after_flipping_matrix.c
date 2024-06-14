// 861. Score After Flipping Matrix
#include "leetcode.h"

/*
 * given an 'm * n' binary matrix 'grid'. a move consists of choosing any row or
 * column and toggling each value in thatrow or column. every row of the matrix
 * is interpreted as a binary number, and the score of the matrix is the sum of
 * these numbers. return the highest possible score after making any number of
 * moves, including zero.
 */

int matrixScore(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = *gridColSize;
  // flip rows to obtain msb = 1
  for (int i = 0; i < m; ++i) {
    if (grid[i][0])
      continue;
    for (int j = 0; j < n; ++j)
      grid[i][j] = !grid[i][j];
  }
  // flip columns
  for (int i = 0; i < n; ++i) {
    int zeros = 0, ones = 0;
    for (int j = 0; j < m; ++j) {
      if (!grid[j][i])
        ++zeros;
      else
        ++ones;
    }
    if (ones >= zeros)
      continue;
    for (int j = 0; j < m; ++j)
      grid[j][i] = !grid[j][i];
  }
  int ans = 0;
  // form binary string and convert to integer
  char *bin_str = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < m; i++) {
    int k = 0;
    for (int j = 0; j < n; ++j) {
      bin_str[k] = grid[i][j] + '0';
      ++k;
    }
    k = 0;
    ans += strtol(bin_str, NULL, 2);
  }
  free(bin_str);
  return ans;
}
