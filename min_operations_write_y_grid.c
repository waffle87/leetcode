// 3071. Minimum Operations to Write the Letter Y on a Grid
#include "leetcode.h"

/*
 * you are given a 0-indexed 'n x n' grid where 'n' is odd, and 'grid[r][c]' is
 * 0, 1, or 2. we say that a cell belongs to the letter y if it belongs to one
 * of the following: the diagonal starting at the top-left cell and ending at
 * the center cell of the grid, the diagonal starting at the top-right cell nd
 * ending at the center cell of the grid, or the vertical line starting at the
 * center cell and ending at the bottom border of the grid. return the minimum
 * number of operations needed to write the letter y on the grid given that in
 * one operation you can change the value at cell to 0, 1, or 2.
 */

int minimumOperationsToWriteY(int **grid, int gridSize, int *gridColSize) {
  int hash_y[4], hash_all[4];
  memset(hash_y, 0, sizeof(hash_y));
  memset(hash_all, 0, sizeof(hash_all));
  int half_length = gridSize / 2;
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < *gridColSize; j++)
      hash_all[grid[i][j]]++;
  hash_all[3] = gridSize * (*gridColSize);
  hash_y[grid[half_length][half_length]]++;
  hash_y[3]++;
  for (int i = 0; i < half_length; i++) {
    hash_y[grid[i][i]]++;
    hash_y[grid[i][gridSize - i - 1]]++;
    hash_y[grid[half_length + i + 1][half_length]]++;
    hash_y[3] += 3;
  }
  for (int i = 0; i < 4; i++)
    hash_all[i] -= hash_y[i];
  int min_ops = INT_MAX, curr_ops;
  for (int i = 0; i < 3; i++) {
    curr_ops = hash_y[3] - hash_y[i] + hash_all[i];
    for (int j = 0; j < 3; j++)
      if (i != j)
        min_ops = fmin(min_ops, curr_ops);
  }
  return min_ops;
}

int main() {
  int g1i[3][3] = {{1, 2, 2}, {1, 1, 0}, {0, 1, 0}};
  int g2i[5][5] = {{0, 1, 0, 1, 0},
                   {2, 1, 0, 1, 2},
                   {2, 2, 2, 0, 1},
                   {2, 2, 2, 2, 2},
                   {2, 1, 2, 2, 2}};
  struct two_d_arr *g1 = two_d_arr_init(3, 3, g1i);
  struct two_d_arr *g2 = two_d_arr_init(5, 2, g2i);
  printf("%d\n", minimumOperationsToWriteY(g1->arr, g1->row_size,
                                           g1->col_size)); // expect: 3
  printf("%d\n", minimumOperationsToWriteY(g2->arr, g2->row_size,
                                           g2->col_size)); // expect: 12
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
