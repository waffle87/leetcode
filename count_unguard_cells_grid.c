// 2257. Count Unguarded Cells in the Grid
#include "leetcode.h"

/*
 * you are given two integers 'm' and 'n' representing a 0-indexed 'm x n' grid.
 * you are also given two 2d integer arrays 'guards' and 'walls' where
 * 'guards[i] = [row_i, col_i]' and 'walls[j] = [row_i, col_i]' represent the
 * positions of the i'th guard and j'th wall respectively. a guard can see every
 * cell in the four cardinal directions starting from their position unless
 * obstructed by a wall or another guard. a cell is guarded if there is at least
 * one guard that can see it. return the number of unoccupied cells that are not
 * guarded.
 */

int countUnguarded(int m, int n, int **guards, int guardsSize,
                   int *guardsColSize, int **walls, int wallsSize,
                   int *wallsColSize) {
  int **vis = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++)
    vis[i] = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < guardsSize; ++i) {
    int r = guards[i][0];
    int c = guards[i][1];
    vis[r][c] = 2;
  }
  for (int i = 0; i < wallsSize; ++i) {
    int r = walls[i][0];
    int c = walls[i][1];
    vis[r][c] = 3;
  }
  for (int i = 0; i < guardsSize; ++i) {
    int r = guards[i][0];
    int c = guards[i][1];
    int left = c - 1, right = c + 1;
    int up = r - 1, down = r + 1;
    while (left >= 0) {
      if (vis[r][left] == 3 || vis[r][left] == 2)
        break;
      vis[r][left] = 1;
      left--;
    }
    while (right < n) {
      if (vis[r][right] == 3 || vis[r][right] == 2)
        break;
      vis[r][right] = 1;
      right++;
    }
    while (up >= 0) {
      if (vis[up][c] == 3 || vis[up][c] == 2)
        break;
      vis[up][c] = 1;
      up--;
    }
    while (down < m) {
      if (vis[down][c] == 3 || vis[down][c] == 2)
        break;
      vis[down][c] = 1;
      down++;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; ++j)
      if (!vis[i][j])
        ans++;
  for (int i = 0; i < m; i++)
    free(vis[i]);
  free(vis);
  return ans;
}

int main() {
  int g1i[3][2] = {{0, 0}, {1, 1}, {2, 3}},
      w1i[3][2] = {{0, 1}, {2, 2}, {1, 4}};
  int g2i[1][2] = {{1, 1}}, w2i[4][2] = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
  struct two_d_arr *g1 = two_d_arr_init(3, 2, g1i);
  struct two_d_arr *w1 = two_d_arr_init(3, 2, g1i);
  struct two_d_arr *g2 = two_d_arr_init(1, 2, g1i);
  struct two_d_arr *w2 = two_d_arr_init(4, 2, g1i);
  printf("%d\n",
         countUnguarded(4, 6, g1->arr, g1->row_size, g1->col_size, w1->arr,
                        w1->row_size, w1->col_size)); // expect: 7
  printf("%d\n",
         countUnguarded(3, 3, g2->arr, g2->row_size, g2->col_size, w2->arr,
                        w2->row_size, w2->col_size)); // expect: 4
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(w1);
  two_d_arr_free(w2);
}
