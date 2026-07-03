// 3286. Find a Safe Walk Through a Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' binary matrix 'grid' and an integer 'health'. you
 * start on the upper left corner and would like to get to the lower right
 * corner. you can move up, down, left, or right from one cell to another
 * adjacent cell as long as your health remains positive. cells '(i, j)' with
 * grid 'grid[i][j] == 1' are considered unsafe and reduce your health by 1.
 * return true if you can reach the final cell with a health of value 1 or more,
 * and false otherwise.
 */

struct pair {
  int x;
  int y;
};

bool findSafeWalk(int **grid, int gridSize, int *gridColSize, int health) {
  int row = gridSize, col = gridColSize[0];
  int **dist = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++) {
    dist[i] = (int *)malloc(col * sizeof(int));
    for (int j = 0; j < col; j++)
      dist[i][j] = -2;
  }
  int max_size = row * col * 2 + 5;
  struct pair *q = (struct pair *)malloc(max_size * sizeof(struct pair));
  int front = max_size / 2, back = max_size / 2;
  q[back++] = (struct pair){0, 0};
  if (grid[0][0]) {
    dist[0][0] = health - 1;
    if (dist[0][0] <= 0) {
      for (int i = 0; i < row; i++)
        free(dist[i]);
      free(dist);
      free(q);
      return false;
    }
  } else
    dist[0][0] = health;
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (front < back) {
    struct pair curr = q[front++];
    int i = curr.x, j = curr.y;
    if (i == row - 1 && j == col - 1) {
      for (int k = 0; k < row; k++)
        free(dist[k]);
      free(dist);
      free(q);
      return true;
    }
    for (int d = 0; d < 4; d++) {
      int x = i + dirs[d][0];
      int y = j + dirs[d][1];
      if (x >= 0 && x < row && y >= 0 && y < col && dist[x][y] == -2) {
        int cost = grid[x][y] == 1 ? 1 : 0;
        int new_health = dist[i][j] - cost;
        if (new_health > 0 && new_health > dist[x][y]) {
          dist[x][y] = new_health;
          if (!cost)
            q[--front] = (struct pair){x, y};
          else
            q[back++] = (struct pair){x, y};
        }
      }
    }
  }
  for (int i = 0; i < row; i++)
    free(dist[i]);
  free(dist);
  free(q);
  return false;
}

int main() {
  int g1i[3][5] = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
  int g2i[4][6] = {{0, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0},
                   {0, 1, 1, 1, 0, 1},
                   {0, 0, 1, 0, 1, 0}};
  int g3i[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  bool r1 = findSafeWalk(g1->arr, g1->row_size, g1->col_size, 1);
  bool r2 = findSafeWalk(g2->arr, g2->row_size, g2->col_size, 3);
  bool r3 = findSafeWalk(g3->arr, g3->row_size, g3->col_size, 5);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == true);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
