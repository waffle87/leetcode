// 934. Shortest Bridge
#include <stdio.h>
#include <stdlib.h>

/*
 * given an 'n x n' binary matrix grid where 1 represents land and 0 represents
 * water. an island is a 4 directionally connected group of 1's not connected to
 * any other 1's. there are exactly two islands in a 'grid'. you may change 0's
 * to 1's to connect the two islands to form one island. return the smallest
 * numbe of 0's you must flip to connect the two islands.
 */

typedef struct {
  int x;
  int y;
  int step;
} point_t;

point_t *bfs(int grid_size, int grid[grid_size][grid_size], int grid_col_size,
             point_t p, int *size) {
  point_t *ans = (point_t *)malloc(10000 * sizeof(point_t));
  *size = 1;
  ans[0] = p;
  int head = 0;
  grid[p.x][p.y] = 2;
  int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  while (head < *size) {
    point_t curr = ans[head++];
    for (int i = 0; i < 4; i++) {
      int dx = dir[i][0];
      int dy = dir[i][1];
      point_t new = {curr.x + dx, curr.y + dy, 0};
      if (0 <= new.x &&new.x < grid_size &&
          0 <= new.y &&new.y < grid_col_size && grid[new.x][new.y] == 1) {
        grid[new.x][new.y] = 2;
        ans[*size] = new;
        (*size)++;
      }
    }
  }
  return ans;
}

int shortestBridge(int grid_size, int grid[grid_size][grid_size],
                   int *grid_col_size) {
  if (!grid || grid_size <= 0 || *grid_col_size <= 0)
    return 0;
  point_t *lands;
  int *size = (int *)malloc(sizeof(int));
  *size = -1;
  int flag = 0;
  for (int i = 0; i < grid_size; i++) {
    for (int j = 0; j < *grid_col_size; j++) {
      if (!grid[i][j])
        continue;
      point_t tmp = {i, j, 0};
      lands = bfs(grid_size, grid, *grid_col_size, tmp, size);
      flag = 1;
      break;
    }
    if (flag)
      break;
  }
  int head = 0, dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  while (head < *size) {
    point_t curr = lands[head++];
    for (int i = 0; i < 4; i++) {
      int dx = dir[i][0];
      int dy = dir[i][1];
      point_t new = {curr.x + dx, curr.y + dy, curr.step + 1};
      if (0 <= new.x &&new.x < grid_size &&
          0 <= new.y &&new.y < *grid_col_size && grid[new.x][new.y] != 3) {
        if (grid[new.x][new.y] == 1) {
          free(size);
          free(lands);
          lands = NULL;
          return curr.step;
        }
        if (!grid[new.x][new.y]) {
          lands[*size] = new;
          (*size)++;
          grid[new.x][new.y] = 3;
        }
      }
    }
  }
  free(size);
  free(lands);
  lands = NULL;
  return -1;
}

int main() {
  int g1[2][2] = {{0, 1}, {1, 0}}, gs1 = 2, gcs1[] = {2, 2};
  int g2[3][3] = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}}, gs2 = 3, gcs2[] = {3, 3, 3};
  int g3[5][5] = {{1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 1},
                  {1, 0, 1, 0, 1},
                  {1, 0, 0, 0, 1},
                  {1, 1, 1, 1, 1}},
      gs3 = 5, gcs3[] = {5, 5, 5, 5, 5};
  printf("%d\n", shortestBridge(gs1, g1, gcs1)); // expect: 1
  printf("%d\n", shortestBridge(gs2, g2, gcs2)); // expect: 2
  printf("%d\n", shortestBridge(gs3, g3, gcs3)); // expect: 1
}
