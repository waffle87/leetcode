// 2352. Equal Row and Column Pairs
#include <stdio.h>

/*
 * given a 0-indexed n x n integer matrix 'grid', return the number of pairs
 * (ri, cj) such that row 'ri' and column 'ci' are equal. a row and column pair
 * is considered equal if they contain the same elements in the same order (ie.
 * an equal array)
 */

int equalPairs(int **grid, int grid_size, int *grid_col_size) {
  int ans = 0, r_len = grid_size, c_len = *grid_col_size;
  for (int i = 0; i < r_len; i++)
    for (int j = 0; j < c_len; j++)
      if (grid[i][0] == grid[0][j]) {
        ans++;
        for (int k = 0; k < r_len; k++)
          if (grid[i][k] != grid[k][j]) {
            ans--;
            break;
          }
      }
  return ans;
}

int main() {
  int g1[3][3] = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}}, gs1 = 3, *gcs1;
  int g2[4][4] = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}},
      gs2 = 4, *gcs2;
  printf("%d\n", equalPairs(g1, gs1, gcs1)); // expect: 1
  printf("%d\n", equalPairs(g2, gs2, gcs2)); // expect: 3
}
