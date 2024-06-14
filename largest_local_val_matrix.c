// 2373. Largest Local Values in a Matrix
#include "leetcode.h"

/*
 * given an 'n * n' integer matrix grid. generate an integer matrix 'max_local'
 * of size '(n - 2) * (n - 2)' such that 'max_local[i][j]' is equal to the
 * largest value of the 3 * 3 matrix in 'grid' centred around row 'i + 1' and
 * column 'j + 1'. in other words, we want to find the largest value in every
 * contiguous 3 * 3 matrix in 'grid'. return the generated matrix.
 */

int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize,
                   int **returnColumnSizes) {
  *returnSize = gridSize - 2;
  *returnColumnSizes = (int *)malloc((gridSize - 2) * sizeof(int));
  for (int i = 0; i < gridSize - 2; ++i)
    (*returnColumnSizes)[i] = gridSize - 2;
  int **ans = (int **)malloc((gridSize - 2) * sizeof(int *));
  for (int i = 0; i < gridSize - 2; ++i)
    ans[i] = (int *)malloc((gridSize - 2) * sizeof(int));
  for (int i = 0; i < gridSize - 2; ++i)
    for (int j = 0; j < gridSize - 2; ++j) {
      for (int row = 0; row <= 2; ++row) {
        int max = 0;
        for (int col = 0; col <= 2; ++col)
          if (grid[i + row][j + col] > max)
            max = grid[i + row][j + col];
        ans[i][j] = max;
        max = 0;
      }
    }
  return ans;
}

int main() {
  int g1[4][4], g2[5][5], gcs1[] = {4, 4, 4, 4}, gcs2[] = {5, 5, 5, 5, 5}, rs1,
                          rs2, *rcs1, *rcs2;
  g1[0][0] = 9, g1[0][1] = 9, g1[0][2] = 8, g1[0][3] = 1;
  g1[1][0] = 5, g1[1][1] = 6, g1[1][2] = 2, g1[1][3] = 6;
  g1[2][0] = 8, g1[2][1] = 2, g1[2][2] = 6, g1[2][3] = 4;
  g1[3][0] = 6, g1[3][1] = 2, g1[3][2] = 2, g1[3][3] = 2;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      g2[i][j] = 1;
  int **ll1 = largestLocal((int **)g1, 4, gcs1, &rs1, &rcs1);
  int **ll2 = largestLocal((int **)g2, 5, gcs2, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++)
    for (int j = 0; j < rs1; j++)
      printf("%d ", ll1[i][j]);
  printf("\n");
  for (int i = 0; i < rs2; i++)
    for (int j = 0; j < rs2; j++)
      printf("%d ", ll2[i][j]);
  printf("\n");
}
