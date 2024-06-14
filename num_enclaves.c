// 1020. Number of Enclaves
#include <stdbool.h>
#include <stdio.h>

/*
 * given an 'm * n' binary matrix grid, where 0 represents a sea
 * cell and 1 represents a land cell. a move consists of walking
 * from one land cell to another adjacent (4-directionally) land
 * cell o walking off the boundary of the 'grid'. return number
 * of land cells in 'grid' for which we cannot walk off the
 * boundary of the grid in any number of moves.
 */

int u_find(int *u, int val) {
  if (u[val] == val)
    return val;
  return u_find(u, u[val]);
}

bool u_set(int *u, int a, int b) {
  int find_a = u_find(u, a), find_b = u_find(u, b);
  if (find_a == find_b)
    return false;
  u[find_a] = u[find_b];
  return true;
}

void bfs(int **grid, int row, int col, int i, int j) {
  if (i < 0 || i >= row || j < 0 || j >= col)
    return;
  if (!grid[i][j])
    return;
  grid[i][j] = 0;
  bfs(grid, row, col, i - 1, j);
  bfs(grid, row, col, i + 1, j);
  bfs(grid, row, col, i, j - 1);
  bfs(grid, row, col, i, j + 1);
}

int numEnclaves(int **grid, int grid_size, int *grid_col_size) {
  int row = grid_size, col = *grid_col_size;
  for (int i = 0; i < col; i++)
    bfs(grid, row, col, 0, i);
  for (int i = 0; i < col; i++)
    bfs(grid, row, col, row - 1, i);
  for (int i = 0; i < row; i++)
    bfs(grid, row, col, i, 0);
  for (int i = 0; i < row; i++)
    bfs(grid, row, col, i, col - 1);
  int ans = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (grid[i][j])
        ans++;
  return ans;
}

int main() {
  int g1[4][4] = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  int g2[4][4] = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  int grid_size = 4;
  int grid_col_size[] = {4, 4, 4, 4};
  printf("%d\n", numEnclaves(g1, grid_size, grid_col_size)); // expect: 3
  printf("%d\n", numEnclaves(g2, grid_size, grid_col_size)); // expect: 3
}
