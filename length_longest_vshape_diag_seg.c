// 3459. Length of Longest V-Shaped Diagonal Segment
#include "leetcode.h"

/*
 * you are given a 2d integer matrix 'grid' of size 'n x m', where each element
 * is either 0, 1, or 2. a v-shaped diagonal segment is defined as: the segment
 * starts with 1, the subsequent elements follow this infinite sequence '2, 0,
 * 2, 0, ...', the segment starts along a diagonal direction, the segment
 * continues the sequence in the same diagonal direction, and the segment makes
 * at most one clockwise 90-degree turn to another diagonal direction while
 * maintaining the sequence.
 */

const static int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, -1, 1};
int dp[501][501][4][2];

bool pos(int **grid, int gridSize, int *gridColSize, int x, int y, int nx,
         int ny) {
  return nx >= 0 && ny >= 0 && nx < gridSize && ny < gridColSize[0] &&
         abs(grid[x][y] - grid[nx][ny]) == 2;
}

int dfs(int **grid, int gridSize, int *gridColSize, int x, int y, int d,
        int changed) {
  if (dp[x][y][d][changed] != -1)
    return dp[x][y][d][changed];
  int res = 1;
  if (pos(grid, gridSize, gridColSize, x, y, x + dx[d], y + dy[d]))
    res = fmax(
        res,
        dfs(grid, gridSize, gridColSize, x + dx[d], y + dy[d], d, changed) + 1);
  if (!changed) {
    int nd = (d + 1) % 4;
    if (pos(grid, gridSize, gridColSize, x, y, x + dx[nd], y + dy[nd]))
      res = fmax(res, dfs(grid, gridSize, gridColSize, x + dx[nd], y + dy[nd],
                          nd, changed + 1) +
                          1);
  }
  return dp[x][y][d][changed] = res;
}

int lenOfVDiagonal(int **grid, int gridSize, int *gridColSize) {
  const int n = gridSize, m = gridColSize[0];
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < gridSize; ++i)
    for (int j = 0; j < gridColSize[0]; ++j)
      if (grid[i][j] == 1) {
        ans = fmax(ans, 1);
        for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k], ny = j + dy[k];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 2)
            continue;
          ans = fmax(ans, dfs(grid, gridSize, gridColSize, nx, ny, k, 0) + 1);
        }
      }
  return ans;
}

int main() {
  int g1i[5][5] = {{2, 2, 1, 2, 2},
                   {2, 0, 2, 2, 0},
                   {2, 0, 1, 1, 0},
                   {1, 0, 2, 2, 2},
                   {2, 0, 0, 2, 2}};
  int g2i[5][5] = {{2, 2, 2, 2, 2},
                   {2, 0, 2, 2, 0},
                   {2, 0, 1, 1, 0},
                   {1, 0, 2, 2, 2},
                   {2, 0, 0, 2, 2}};
  int g3i[5][5] = {{1, 2, 2, 2, 2},
                   {2, 2, 2, 2, 0},
                   {2, 0, 0, 0, 0},
                   {0, 0, 2, 2, 2},
                   {2, 0, 0, 2, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n",
         lenOfVDiagonal(g1->arr, g1->row_size, g1->col_size)); // expect: 5
  printf("%d\n",
         lenOfVDiagonal(g2->arr, g2->row_size, g2->col_size)); // expect: 4
  printf("%d\n",
         lenOfVDiagonal(g3->arr, g3->row_size, g3->col_size)); // expect: 5
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
