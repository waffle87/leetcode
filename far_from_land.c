// 1162. As Far from Land as Possible
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given 'n * n grid' containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximised, and returh the distance. if no land or water
 * exists, return -1. the distance used is the manhattan distance: the distance
 * between two cells '(x0, y0)' and '(x1, y1)' is '|x0 - x1| + |y0 - y1|'
 */

int maxDistance(int **grid, int gridSize, int *gridColSize) {
  int queue[10000][2] = {0}, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int head = 0, tail = 0, step = -1;
  bool has_land = false, has_water = false;
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < *gridColSize; j++)
      if (grid[i][j] == 1) {
  has_land = true;
        grid[i][j] = 2;
        queue[tail][0] = i;
        queue[tail][1] = j;
        tail += 1;
      } else
        has_water = true;
  while (head < tail) {
    int size = tail - head;
    step += 1;
    for (int i = 0; i < size; i++) {
      int x = queue[head][0], y = queue[head][1];
      head += 1;
      for (int j = 0; j < 4; j++) {
        int new_x = x + dir[j][0], new_y = y + dir[j][1];
        if (new_x >= 0 && new_y >= 0 && new_x < gridSize &&
            new_y < *gridColSize && grid[new_x][new_y] == 0) {
          grid[new_x][new_y] = 2;
          queue[tail][0] = new_x;
          queue[tail][1] = new_y;
          tail += 1;
        }
      }
    }
  }
  if (!has_land || !has_water)
    return -1;
  return step;
}

int main() {
  int grid1[3][3] = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}, gs1 = 3, gcs1[] = {3};
  int grid2[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, gs2 = 3, gcs2[] = {3};
  printf("%d\n", maxDistance(grid1, gs1, gcs1)); // expect: 2
  printf("%d\n", maxDistance(grid2, gs2, gcs2)); // expect: 2
}
