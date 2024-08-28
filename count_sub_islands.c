// 1905. Count Sub Islands
#include "leetcode.h"

/*
 * you are given two 'm * n' binary matricies 'grid1', and 'grid2' containing
 * only 0's (represeting water) and 1's (representing land). an island is a
 * group of 1's connected 4 directionally (horizontal or vertical). any cells
 * outside of the grid are considered water cells. an island in 'grid2' is
 * considered a sub-island if there is an island in 'grid1' that contains all
 * the cells that make up this island is 'grid2'. return the number of islands
 * in 'grid2' that are considered sub islands
 */

int countSubIslands(int **grid1, int grid1Size, int *grid1ColSize, int **grid2,
                    int grid2Size, int *grid2ColSize) {
  const int row = grid1Size, col = *grid1ColSize;
  int cnt = 0, head, tail;
  struct point {
    int row, col;
  } bfs_queue[col * row];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (!grid2[i][j])
        continue;
      bool matched = true;
      head = 0;
      grid2[i][j] = 0;
      bfs_queue[0].row = i;
      bfs_queue[0].col = j;
      tail = 1;
      do {
        const struct point curr = bfs_queue[head];
        head++;
        if (!grid1[curr.row][curr.col])
          matched = false;
        static const struct point offsets[] = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int k = 0; k < sizeof(offsets) / sizeof(offsets[0]); k++) {
          const struct point next = {curr.row + offsets[k].row,
                                     curr.col + offsets[k].col};
          if ((next.row >= 0 && next.row < row) &&
              (next.col >= 0 && next.col < col) && grid2[next.row][next.col]) {
            grid2[next.row][next.col] = 0;
            bfs_queue[tail] = next;
            tail++;
          }
        }
      } while (head < tail);
      if (matched)
        cnt++;
    }
  }
  return cnt;
}

int main() {
  int g11[5][5] = {{1, 1, 1, 0, 0},
                   {0, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1}},
      g11cs = 5;
  int g21[5][5] = {{1, 1, 1, 0, 0},
                   {0, 0, 1, 1, 1},
                   {0, 1, 0, 0, 0},
                   {1, 0, 1, 1, 0},
                   {0, 1, 0, 1, 0}},
      g21cs = 5;
  int g12[5][5] = {{1, 0, 1, 0, 1},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 1, 1, 1, 1},
                   {1, 0, 1, 0, 1}},
      g12cs = 5;
  int g22[5][5] = {{0, 0, 0, 0, 0},
                   {1, 1, 1, 1, 1},
                   {0, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0},
                   {1, 0, 0, 0, 1}},
      g22cs = 5;
  printf("%d\n",
         countSubIslands((int **)g11, ARRAY_SIZE(g11), &g11cs, (int **)g21,
                         ARRAY_SIZE(g21), &g21cs)); // expect: 3
  printf("%d\n",
         countSubIslands((int **)g12, ARRAY_SIZE(g12), &g12cs, (int **)g22,
                         ARRAY_SIZE(g22), &g22cs)); // expect: 2
}
