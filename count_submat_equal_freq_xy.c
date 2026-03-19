// 3212. Count Submatrices With Equal Frequency of X and Y
#include "leetcode.h"

/*
 * given a 2d character matrix 'grid' where 'grid[i][j]' is either "X", "Y", or
 * ".", return the number of submatrices that contain 'grid[0][0]', an equal
 * frequency of 'X' and 'Y', and at least one 'X'.
 */

int numberOfSubmatrices(char **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0], ans = 0;
  int **pre_x = (int **)malloc((m + 1) * sizeof(int *));
  int **pre_y = (int **)malloc((m + 1) * sizeof(int *));
  for (int i = 0; i < m + 1; i++) {
    pre_x[i] = (int *)calloc(n + 1, sizeof(int));
    pre_y[i] = (int *)calloc(n + 1, sizeof(int));
  }
  for (int i = 1; i < m + 1; i++)
    for (int j = 1; j < n + 1; j++) {
      pre_x[i][j] += (pre_x[i - 1][j] + pre_x[i][j - 1] - pre_x[i - 1][j - 1]);
      pre_y[i][j] += (pre_y[i - 1][j] + pre_y[i][j - 1] - pre_y[i - 1][j - 1]);
      if (grid[i - 1][j - 1] == 'X')
        pre_x[i][j]++;
      else if (grid[i - 1][j - 1] == 'Y')
        pre_y[i][j]++;
      if ((pre_x[i][j] != 0 && pre_y[i][j] != 0) &&
          (pre_x[i][j] == pre_y[i][j]))
        ans++;
    }
  for (int i = 0; i < m + 1; i++) {
    free(pre_x[i]);
    free(pre_y[i]);
  }
  free(pre_x);
  free(pre_y);
  return ans;
}

int main() {
  char *g1[2][3] = {{"X", "Y", "."}, {"Y", ".", "."}};
  char *g2[2][2] = {{"X", "X"}, {"X", "Y"}};
  char *g3[2][2] = {{".", "."}, {".", "."}};
  int r1 = numberOfSubmatrices((char **)g1, ARRAY_SIZE(g1),
                               (int *)ARRAY_SIZE(g1[0]));
  int r2 = numberOfSubmatrices((char **)g2, ARRAY_SIZE(g2),
                               (int *)ARRAY_SIZE(g2[0]));
  int r3 = numberOfSubmatrices((char **)g3, ARRAY_SIZE(g3),
                               (int *)ARRAY_SIZE(g3[0]));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 0);
}
