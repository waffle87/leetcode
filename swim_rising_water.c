// 778. Swim in Rising Water
#include "leetcode.h"

/*
 * you are given an 'n x n' integer matrix 'grid' where each value 'grid[i][j]'
 * represnts the elevation at that point '(i, j)'. it starts raining and water
 * gradually rises over time. at time 't', the water level is 't', meaning any
 * cell with elevation less than or equal to 't' is submerged or reachable. you
 * can swim from a square to another 4-direction adjacent square if and only if
 * the elevation of both squares individually are at most 't'. you can swim
 * infinite distances in zero time. of course, you must stay within the
 * boundaries of the grid. return the minimum time until you can reach the
 * bottom right . you can swim infinite distances in zero time. of course, you
 * must stay within the boundaries of the grid. return the minimum time until
 * you can reach the bottom right square if you start at the top left. you can
 * swim infinite distances in zero time. of course, you must stay within the
 * boundaries of the grid. return the minimum time until you can reach the
 * bottom right square if you start at the top left..square if you start at the
 * top left.
 */

static int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct node {
  int val;
  int row;
  int col;
};

struct pq {
  int size;
  int capacity;
  struct node *data;
};

void swap(struct node *a, struct node *b) {
  struct node tmp = *a;
  *a = *b;
  *b = tmp;
}

struct pq *pq_init(int capacity) {
  struct pq *obj = (struct pq *)malloc(sizeof(struct pq));
  obj->size = 0;
  obj->capacity = capacity;
  obj->data = (struct node *)malloc(capacity * sizeof(struct node));
  return obj;
}

void pq_free(struct pq *obj) {
  free(obj->data);
  free(obj);
}

void min_heapify(struct pq *obj, int idx) {
  int smallest = idx, left = idx * 2 + 1, right = idx * 2 + 2;
  if (left < obj->size && obj->data[left].val < obj->data[smallest].val)
    smallest = left;
  if (right < obj->size && obj->data[right].val < obj->data[smallest].val)
    smallest = right;
  if (smallest != idx) {
    swap(&obj->data[idx], &obj->data[smallest]);
    min_heapify(obj, smallest);
  }
}

void push(struct pq *obj, int val, int row, int col) {
  int idx = obj->size;
  struct node n = {val, row, col};
  obj->data[(obj->size)++] = n;
  while (idx && obj->data[(idx - 1) / 2].val > obj->data[idx].val) {
    swap(&obj->data[(idx - 1) / 2], &obj->data[idx]);
    idx = (idx - 1) / 2;
  }
}

struct node pop(struct pq *obj) {
  struct node root = obj->data[0];
  obj->data[0] = obj->data[--(obj->size)];
  min_heapify(obj, 0);
  return root;
}

bool is_empty(struct pq *obj) { return !obj->size; }

int swimInWater(int **grid, int gridSize, int *gridColSize) {
  int total = gridSize * (*gridColSize);
  struct pq *heap = pq_init(total);
  push(heap, grid[0][0], 0, 0);
  grid[0][0] = -1;
  while (!is_empty(heap)) {
    struct node tmp = pop(heap);
    for (int i = 0; i < 4; i++) {
      int x = tmp.row + dir[i][0];
      int y = tmp.col + dir[i][1];
      if (x >= 0 && x < gridSize && y >= 0 && y < *gridColSize &&
          grid[x][y] != -1) {
        int max = grid[x][y] > tmp.val ? grid[x][y] : tmp.val;
        if (x == gridSize - 1 && y == (*gridColSize) - 1) {
          pq_free(heap);
          return max;
        }
        push(heap, max, x, y);
        grid[x][y] = -1;
      }
    }
  }
  pq_free(heap);
  return 0;
}

int main() {
  int g1i[2][2] = {{0, 2}, {1, 3}}, g2i[5][5] = {{0, 1, 2, 3, 4},
                                                 {24, 23, 22, 21, 5},
                                                 {12, 13, 14, 15, 16},
                                                 {11, 17, 18, 19, 20},
                                                 {10, 9, 8, 7, 6}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n", swimInWater(g1->arr, g1->row_size, g1->col_size)); // expect: 3
  printf("%d\n", swimInWater(g2->arr, g2->row_size, g2->col_size)); // expect:
                                                                    // 16
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
