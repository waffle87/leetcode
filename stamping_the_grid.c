// 2132. Stamping the Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' binary matrix 'grid' where each cell is either 0 or
 * 1 (empty or occupied, respectively). you are then given stamps of size
 * 'stampHeight x stampWidth'. we want to fit the stamps such that they follow
 * the given restrictions and requirements: cover all the empty cells, do not
 * cover any of the occupied cells, we can put as many stamps as we want, stamps
 * can overlap with eachother, stamps are not allowed to be rotated, stampsmust
 * stay completely in the grid. return 'true' if it is possible to fit the
 * stamps while following the given restrictions, otherwise return 'false'.
 */

bool possibleToStamp(int **grid, int gridSize, int *gridColSize,
                     int stampHeight, int stampWidth) {
  int n = gridSize, m = m;
  int occupied[n][m];
  bool stamps[n][m];
  memset(occupied, 0, sizeof(occupied));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      occupied[i][j] = grid[i][j];
      if (i)
        occupied[i][j] += occupied[i - 1][j];
      if (j)
        occupied[i][j] += occupied[i][j - 1];
      if (i && j)
        occupied[i][j] -= occupied[i - 1][j - 1];
    }
  memset(stamps, false, sizeof(stamps));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!grid[i][j]) {
        const int x = i + stampHeight - 1, y = j + stampWidth - 1;
        if (x < n && y < m) {
          int ones = occupied[x][y];
          if (j)
            ones -= occupied[x][j - 1];
          if (i)
            ones -= occupied[i - 1][y];
          if (i && j)
            ones += occupied[i - 1][j - 1];
          if (!ones)
            stamps[i][j] = true;
        }
      }
  memset(occupied, 0, sizeof(occupied));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      occupied[i][j] = stamps[i][j] ? 1 : 0;
      if (i)
        occupied[i][j] += occupied[i - 1][j];
      if (j)
        occupied[i][j] += occupied[i][j - 1];
      if (i && j)
        occupied[i][j] -= occupied[i - 1][j - 1];
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!grid[i][j]) {
        const int x = i - stampHeight, y = j - stampWidth;
        int stamp_cnt = occupied[i][j];
        if (x >= 0)
          stamp_cnt -= occupied[x][j];
        if (y >= 0)
          stamp_cnt -= occupied[i][y];
        if (x >= 0 && y >= 0)
          stamp_cnt += occupied[x][y];
        if (!stamp_cnt)
          return false;
      }
  return true;
}

int main() {
  int g1i[6][4] = {
      {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  int g2i[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  struct two_d_arr g1, g2;
  two_d_arr_init(&g1, ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  two_d_arr_init(&g2, ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n",
         possibleToStamp(g1.arr, g1.row_size, g1.col_size, 4, 3)); // expect: 1
  printf("%d\n",
         possibleToStamp(g2.arr, g2.row_size, g2.col_size, 2, 2)); // expect: 0
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
}
