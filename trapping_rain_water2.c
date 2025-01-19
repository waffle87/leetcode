// 407. Trapping Rain Water II
#include "leetcode.h"

/*
 * given an 'm x n' integer matrix 'heightMap' representing the height of each
 * unit cell in a 2d elevation map, return the volume of water it can trap after
 * raining
 */

struct cell {
  int x;
  int y;
  int h;
};

struct heap {
  struct cell *cells;
  int size;
};

struct heap *heap_create(int capacity) {
  struct heap *heap = (struct heap *)malloc(sizeof(struct heap));
  heap->cells = (struct cell *)malloc(capacity * sizeof(struct cell));
  heap->size = 0;
  return heap;
}

void heap_push(struct heap *heap, int x, int y, int h) {
  int i = heap->size++;
  while (i && h < heap->cells[(i - 1) / 2].h)
    heap->cells[i] = heap->cells[(i - 1) / 2], i = (i - 1) / 2;
  heap->cells[i] = (struct cell){x, y, h};
}

struct cell heap_pop(struct heap *heap) {
  struct cell root = heap->cells[0], prev = heap->cells[--heap->size];
  int i, child;
  for (i = 0; (child = 2 * i + 1) < heap->size; i = child) {
    if (child + 1 < heap->size &&
        heap->cells[child].h > heap->cells[child + 1].h)
      child++;
    if (prev.h <= heap->cells[child].h)
      break;
    heap->cells[i] = heap->cells[child];
  }
  return heap->cells[i] = prev, root;
}

int trapRainWater(int **heightMap, int heightMapSize, int *heightMapColSize) {
  int m = heightMapSize, n = *heightMapColSize, water = 0, max_height = 0;
  bool vis[m][n];
  if (m < 3 || n < 3)
    return 0;
  memset(vis, false, sizeof(vis));
  struct heap *heap = heap_create(m * n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (!i || i == m - 1 || !j || j == n - 1) {
        heap_push(heap, i, j, heightMap[i][j]);
        vis[i][j] = true;
      }
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (heap->size) {
    struct cell cell = heap_pop(heap);
    max_height = cell.h > max_height ? cell.h : max_height;
    for (int i = 0; i < 4; i++) {
      int x = cell.x + dir[i][0], y = cell.y + dir[i][1];
      if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
        vis[x][y] = true;
        heightMap[x][y] < max_height ? (water += max_height - heightMap[x][y],
                                        heap_push(heap, x, y, max_height))
                                     : heap_push(heap, x, y, heightMap[x][y]);
      }
    }
  }
  free(heap->cells);
  free(heap);
  return water;
}

int main() {
  int hm1i[3][6] = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
  int hm2i[5][6] = {{3, 3, 3, 3, 3},
                    {3, 2, 2, 2, 3},
                    {3, 2, 1, 2, 3},
                    {3, 2, 2, 2, 3},
                    {3, 3, 3, 3, 3}};
  struct two_d_arr hm1, hm2, hm3;
  two_d_arr_init(&hm1, ARRAY_SIZE(hm1i), ARRAY_SIZE(hm1i[0]), hm1i);
  two_d_arr_init(&hm2, ARRAY_SIZE(hm2i), ARRAY_SIZE(hm2i[0]), hm2i);
  printf("%d\n",
         trapRainWater(hm1.arr, hm1.row_size, hm1.col_size)); // expect: 4
  printf("%d\n",
         trapRainWater(hm2.arr, hm2.row_size, hm2.col_size)); // expect: 10
}
