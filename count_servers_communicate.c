// 1267. Count Servers that Communicate
#include "leetcode.h"

/*
 * you are given a map of a server centre, represented as a 'm x n' integer
 * matrix 'grid', where 1 means that on that cell there is a server and 0 means
 * that it is no server. two servers are said to communicate if they are on the
 * same row or the same column. return the number of servers that communicate
 * with any other server.
 */

int countServers(int **grid, int gridSize, int *gridColSize) {
  int rows[8] = {0}, rg2[8] = {0};
  int cols[8] = {0}, cg2[8] = {0};
  int ans = 0;
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridColSize[i]; j++)
      if (grid[i][j]) {
        if ((rows[i / 32] & (1 << (i % 32))) == (1 << (i % 32)))
          rg2[i / 32] |= 1 << (i % 32);
        else
          rows[i / 32] |= 1 << (i % 32);
        if ((cols[j / 32] & (1 << (j % 32))) == (1 << (j % 32)))
          cg2[j / 32] |= 1 << (j % 32);
        else
          cols[j / 32] |= 1 << (j % 32);
      }
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridColSize[i]; j++)
      if (grid[i][j] == 1 &&
          (((rg2[i / 32] & (1 << (i % 32))) == (1 << (i % 32))) ||
           ((cg2[j / 32] & (1 << (j % 32))) == (1 << (j % 32)))))
        ans++;
  return ans;
}

int main() {
  int g1i[2][2] = {{1, 0}, {0, 1}};
  int g2i[2][2] = {{1, 0}, {1, 1}};
  int g3i[4][4] = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  struct two_d_arr g1, g2, g3;
  two_d_arr_init(&g1, ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  two_d_arr_init(&g2, ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  two_d_arr_init(&g3, ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n", countServers(g1.arr, g1.row_size, g1.col_size)); // expect: 0
  printf("%d\n", countServers(g2.arr, g2.row_size, g2.col_size)); // expect: 3
  printf("%d\n", countServers(g3.arr, g3.row_size, g3.col_size)); // expect: 4
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
  two_d_arr_free(&g3);
}
