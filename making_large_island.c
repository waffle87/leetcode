// 827. Making A Large Island
#include "leetcode.h"

/*
 * you are given an 'm x n' binary matrix 'grid'. you are allowed to change at
 * most one 0 to be 1. return size of the largest island in 'grid' after
 * applying this operation. an island is a 4-directionally connected group of
 * 1's.
 */

enum state { water, land };

struct point {
  int r;
  int c;
};

int explor_island(int r, int c, int id, int **grid, int nrow, int ncol) {
  int land_size = 0, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  struct point queue[nrow * ncol];
  int front = 0, rear = 0;
  queue[rear++] = (struct point){r, c};
  grid[r][c] = id;
  while (front < rear) {
    struct point p = queue[front++];
    ++land_size;
    for (int i = 0; i < 4; ++i) {
      int dr = p.r + dir[i][0];
      int dc = p.c + dir[i][1];
      if (dr < 0 || dr >= nrow || dc < 0 || dc >= ncol || grid[dr][dc] != land)
        continue;
      grid[dr][dc] = id;
      queue[rear++] = (struct point){dr, dc};
    }
  }
  return land_size;
}

int largestIsland(int **grid, int gridSize, int *gridColSize) {
  int max_island = gridSize * (*gridColSize), id = 2;
  int *islands = (int *)calloc(max_island + 2, sizeof(int));
  for (int i = 0; i < gridSize; ++i)
    for (int j = 0; j < (*gridColSize); ++j)
      if (grid[i][j] == land) {
        islands[id] = explor_island(i, j, id, grid, gridSize, *gridColSize);
        ++id;
      }
  if (id == 2) {
    free(islands);
    return 1;
  }
  if (id == 3) {
    int total = gridSize * (*gridColSize), land_size = islands[2] + 1;
    int num_land = fmin(total, land_size);
    free(islands);
    return num_land;
  }
  int max_size = 1, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  for (int i = 0; i < gridSize; ++i)
    for (int j = 0; j < (*gridColSize); ++j) {
      if (grid[i][j] != water)
        continue;
      bool vis[id];
      int curr_size = 1;
      memset(vis, 0, sizeof(vis));
      for (int k = 0; k < 4; ++k) {
        int dr = i + dir[k][0];
        int dc = j + dir[k][1];
        if (dr < 0 || dr >= gridSize || dc < 0 || dc >= (*gridColSize) ||
            grid[dr][dc] <= land)
          continue;
        int curr_id = grid[dr][dc];
        if (!vis[curr_id]) {
          curr_size += islands[curr_id];
          vis[curr_id] = true;
        }
      }
      max_size = fmax(max_size, curr_size);
    }
  free(islands);
  return max_size;
}

int main() {
  int g1i[2][2] = {{1, 0}, {0, 1}}, g2i[2][2] = {{1, 1}, {1, 0}},
      g3i[2][2] = {{1, 1}, {1, 1}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n",
         largestIsland(g1->arr, g1->row_size, g1->col_size)); // expect: 3
  printf("%d\n",
         largestIsland(g2->arr, g2->row_size, g2->col_size)); // expect: 4
  printf("%d\n",
         largestIsland(g3->arr, g3->row_size, g3->col_size)); // expect: 4
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
