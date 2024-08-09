// 840. Magic Squares In Grid
#include "leetcode.h"

/*
 * a 3 * 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
 * such that each row, column, and both diagonals all have the same sum. given a
 * row x col 'grid' of integers, how many 3 x 3 contiguous magic square subgrids
 * are there? note, while a magic square can only contain numbers from 1 to 9,
 * 'grid' may contain numbers up to 15.
 */

bool check(int **grid, int row, int col, int *map) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      map[grid[row + i][col + j]]++;
      if (map[grid[row + i][col + j]] > 1 || grid[row + i][col + j] > 9 ||
          grid[row + i][col + j] == 0)
        return false;
    }
  int a = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
  int b = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
  int c = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];
  if (a != 15 || b != 15 || c != 15)
    return false;
  int d = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
  int e = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
  int f = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];
  if (d != 15 || e != 15 || f != 15)
    return false;
  int g = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
  int h = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
  if (g != 15 || h != 15)
    return false;
  return true;
}

int numMagicSquaresInside(int **grid, int gridSize, int *gridColSize) {
  if (gridSize < 3 || gridColSize[0] < 3)
    return 0;
  int *map = (int *)calloc(16, sizeof(int)), cnt = 0;
  for (int i = 0; i + 2 < gridSize; i++)
    for (int j = 0; j + 2 < gridColSize[0]; j++) {
      if (check(grid, i, j, map))
        cnt++;
      memset(map, 0, 16 * sizeof(int));
    }
  free(map);
  return cnt;
}

int main() {
  int g1[3][4] = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}}, g2[1][1] = {{8}},
      gcs1 = 3, gcs2 = 1;
  printf("%d\n",
         numMagicSquaresInside((int **)g1, ARRAY_SIZE(g1), &gcs1)); // expect: 1
  printf("%d\n",
         numMagicSquaresInside((int **)g2, ARRAY_SIZE(g2), &gcs2)); // expect: 0
}
