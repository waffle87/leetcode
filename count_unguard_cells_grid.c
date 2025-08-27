// 2257. Count Unguarded Cells in the Grid
#include "leetcode.h"
#include <stdio.h>

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
  int unguarded = m * n;
  char *grid = (char *)calloc(unguarded, sizeof(char));
  for (int i = 0; i < guardsSize; i++) {
    grid[guards[i][0] * n + guards[i][1]] = 1;
    unguarded--;
  }
  for (int i = 0; i < wallsSize; i++) {
    grid[walls[i][0] * n + walls[i][1]] = 2;
    unguarded--;
  }
  for (int i = 0; i < guardsSize; i++) {
    int row = guards[i][0], col = guards[i][1];
    for (int c = col + 1; c < n; c++) {
      if (grid[row * n + c] == 1 || grid[row * n + c] == 2)
        break;
      if (!grid[row * n + c]) {
        grid[row * n + c] = 3;
        unguarded--;
      }
    }
    for (int c = col - 1; c >= 0; c--) {
      if (grid[row * n + c] == 1 || grid[row * n + c] == 2)
        break;
      if (!grid[row * n + c]) {
        grid[row * n + c] = 3;
        unguarded--;
      }
    }
    for (int r = row + 1; r < m; r++) {
      if (grid[r * n + col] == 1 || grid[r * n + col] == 2)
        break;
      if (!grid[r * n + col]) {
        grid[r * n + col] = 3;
        unguarded--;
      }
    }
    for (int r = row - 1; r >= 0; r--) {
      if (grid[r * n + col] == 1 || grid[r * n + col] == 2)
        break;
      if (!grid[r * n + col]) {
        grid[r * n + col] = 3;
        unguarded--;
      }
    }
  }
  free(grid);
  return unguarded;
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
