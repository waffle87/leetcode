// 994. Rotting Oranges
#include "leetcode.h"

/*
 * you are given an 'm x n' 'grid' where each cell can have one of three values:
 * 0 representing an empty cell, 1 representing a fresh orange, or 2
 * representing a rotten orange. every minute, any fresh orange that is
 * 4-directionall adjacent to a rotten orange becomes rotten. return the minimum
 * number of minutethat must elapse until no cell has a fresh oragne. if this is
 * impossible, return -1
 */

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
  int min_val = 0, **dp = (int **)malloc(gridSize * sizeof(int *));
  for (int i = 0; i < gridSize; i++)
    dp[i] = (int *)malloc((*gridColSize) * sizeof(int));
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, dir_row = 4;
  bool searching = true;
  while (searching) {
    bool transition = false, check = false;
    for (int i = 0; i < gridSize; i++) {
      for (int j = 0; j < (*gridColSize); j++) {
        if (dp[i][j] == min_val)
          continue;
        if (grid[i][j] == 2) {
          dp[i][j] = min_val;
          for (int k = 0; k < dir_row; k++) {
            int i_adj = i + dir[k][0], j_adj = j + dir[k][1];
            if (i_adj >= 0 && i_adj < gridSize && j_adj >= 0 &&
                j_adj < *gridColSize) {
              if (grid[i_adj][j_adj] == 1) {
                grid[i_adj][j_adj] = 2;
                dp[i_adj][j_adj] = min_val;
                transition = true;
              }
            }
          }
        } else if (grid[i][j] == 1) {
          check = true;
          bool connect = false;
          for (int k = 0; k < dir_row; k++) {
            int i_adj = i + dir[k][0], j_adj = j + dir[k][1];
            if (i_adj >= 0 && i_adj < gridSize && j_adj >= 0 &&
                j_adj < (*gridColSize)) {
              if (grid[i_adj][j_adj] == 1 || grid[i_adj][j_adj] == 2) {
                connect = true;
                break;
              }
            }
          }
          if (!connect)
            return -1;
        }
      }
    }
    if (check) {
      if (transition)
        searching = true;
      else
        return -1;
    } else
      searching = false;
    if (transition)
      min_val++;
  }
  for (int i = 0; i < gridSize; i++)
    free(dp[i]);
  free(dp);
  return min_val;
}

int main() {
  int g1i[3][3] = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}},
      g2i[3][3] = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, g3i[1][2] = {{0, 2}};
  struct two_d_arr g1, g2, g3;
  two_d_arr_init(&g1, 3, 3, g1i);
  two_d_arr_init(&g2, 3, 3, g2i);
  two_d_arr_init(&g3, 1, 2, g3i);
  printf("%d\n", orangesRotting(g1.arr, g1.row_size, g1.col_size)); // expect: 4
  printf("%d\n", orangesRotting(g2.arr, g2.row_size, g2.col_size)); // expect:
                                                                    // -1
  printf("%d\n", orangesRotting(g3.arr, g3.row_size, g3.col_size)); // expect: 0
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
  two_d_arr_free(&g3);
}
