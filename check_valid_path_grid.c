// 1391. Check if There is a Valid Path in a Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' 'grid'. each cell of 'grid' represents a street. the
 * street of 'grid[i][j]' can be 1 .. 6, connecting to a left/upper/right cell
 * and the right/lower/upper cell. you will initially start at the street of the
 * upper left cell '(0, 0)'. a valid path in the grid is the path that starts
 * from the upper left cell '(0, 0)' and ends at the bottom right cell '(m - 1,
 * n - 1)'. the path should only follow the streets. notice that you are not
 * allowed to change any street. return true if there is a valid path in the
 * grid or 'false' otherwise.
 */

bool has_opening(int type, int dir) {
  if (type == 1)
    return dir == 0 || dir == 1;
  if (type == 2)
    return dir == 2 || dir == 3;
  if (type == 3)
    return dir == 0 || dir == 3;
  if (type == 4)
    return dir == 1 || dir == 3;
  if (type == 5)
    return dir == 0 || dir == 2;
  if (type == 6)
    return dir == 1 || dir == 2;
  return false;
}

bool hasValidPath(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0];
  if (m == 1 && n == 1)
    return true;
  static int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  static int next_step[7][4] = {{4, 4, 4, 4}, {1, 0, 4, 4}, {4, 4, 3, 2},
                                {3, 4, 4, 0}, {4, 3, 4, 1}, {2, 4, 0, 4},
                                {4, 2, 1, 4}};
  int start_type = grid[0][0];
  bool **vis = (bool **)calloc(m, sizeof(bool *));
  for (int i = 0; i < m; i++)
    vis[i] = (bool *)calloc(n, sizeof(bool));
  for (int d = 0; d < 4; d++) {
    if (!has_opening(start_type, d))
      continue;
    int r = 0, c = 0, out_dir = d;
    vis[0][0] = true;
    while (true) {
      int nr = r + dirs[out_dir][0];
      int nc = c + dirs[out_dir][1];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc])
        break;
      int in_dir = !(out_dir % 2) ? out_dir + 1 : out_dir - 1;
      int n_type = grid[nr][nc];
      if (!has_opening(n_type, in_dir))
        break;
      if (nr == m - 1 && nc == n - 1) {
        for (int i = 0; i < m; i++)
          free(vis[i]);
        free(vis);
        return true;
      }
      vis[nr][nc] = true;
      r = nr;
      c = nc;
      out_dir = next_step[n_type][in_dir];
      if (out_dir == 4)
        break;
    }
  }
  for (int i = 0; i < m; i++)
    free(vis[i]);
  free(vis);
  return false;
}

int main() {
  int g1i[2][3] = {{2, 4, 3}, {6, 5, 2}};
  int g2i[2][3] = {{1, 2, 1}, {1, 2, 1}};
  int g3i[1][3] = {{1, 1, 2}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  bool r1 = hasValidPath(g1->arr, g1->row_size, g1->col_size);
  bool r2 = hasValidPath(g2->arr, g2->row_size, g2->col_size);
  bool r3 = hasValidPath(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == false);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
