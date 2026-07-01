// 2812. Find the Safest Path in a Grid
#include "leetcode.h"

/*
 * given a 0-indexed 2d matrix 'grid' of size 'n  n' where '(r, c)' represents
 * a cell containing a thief if 'grid{r}{c} == 1', or an empty cell if
 * 'grid{r}{c} == 0'. you are initially positioned at cell '(0, 0)'. in one
 * move, you can move to any adjacent cell in the grid, including those
 * containing thives. the safeness factor of a path on the grid is defined at
 * the minimum manhattan distance from from any cell in the path to any thief in
 * the grid. return the maximum safeness factor of all paths leading to cell '(n
 * - 1, n - 1)'.
 */

static int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct node {
  int dist;
  int i;
  int j;
};

struct max_heap {
  struct node *data;
  int size;
  int capacity;
};

struct max_heap *max_heap_init(int capacity) {
  struct max_heap *obj = (struct max_heap *)malloc(sizeof(struct max_heap));
  obj->data = (struct node *)malloc(capacity * sizeof(struct node));
  obj->size = 0;
  obj->capacity = capacity;
  return obj;
}

void max_heap_push(struct max_heap *h, struct node n) {
  if (h->size == h->capacity) {
    h->capacity *= 2;
    h->data =
        (struct node *)realloc(h->data, h->capacity * sizeof(struct node));
  }
  h->data[h->size] = n;
  int curr = h->size;
  h->size++;
  while (curr > 0) {
    int parent = (curr - 1) / 2;
    if (h->data[curr].dist > h->data[parent].dist) {
      struct node tmp = h->data[curr];
      h->data[curr] = h->data[parent];
      h->data[parent] = tmp;
      curr = parent;
    } else
      break;
  }
}

struct node max_heap_pop(struct max_heap *obj) {
  struct node top = obj->data[0];
  obj->size--;
  obj->data[0] = obj->data[obj->size];
  int curr = 0;
  while (true) {
    int left = 2 * curr + 1, right = 2 * curr + 2, largest = curr;
    if (left < obj->size && obj->data[left].dist > obj->data[largest].dist)
      largest = left;
    if (right < obj->size && obj->data[right].dist > obj->data[largest].dist)
      largest = right;
    if (largest != curr) {
      struct node tmp = obj->data[curr];
      obj->data[curr] = obj->data[largest];
      obj->data[largest] = tmp;
      curr = largest;
    } else
      break;
  }
  return top;
}

bool valid(int x, int y, int n) { return x >= 0 && x < n && y >= 0 && y < n; }

int **compute_distance_grid(int **grid, int n) {
  int **dist_grid = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    dist_grid[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      dist_grid[i][j] = INT_MAX;
  }
  int **q = (int **)malloc(n * n * sizeof(int *));
  for (int i = 0; i < n * n; i++)
    q[i] = (int *)malloc(2 * sizeof(int));
  int front = 0, rear = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == 1) {
        q[rear][0] = i;
        q[rear][1] = j;
        rear++;
        dist_grid[i][j] = 0;
      }
  while (front < rear) {
    int x = q[front][0], y = q[front][1];
    front++;
    for (int d = 0; d < 4; d++) {
      int xx = x + dir[d][0];
      int yy = y + dir[d][1];
      if (valid(xx, yy, n) && dist_grid[xx][yy] == INT_MAX) {
        dist_grid[xx][yy] = dist_grid[x][y] + 1;
        q[rear][0] = xx;
        q[rear][1] = yy;
        rear++;
      }
    }
  }
  for (int i = 0; i < n * n; i++)
    free(q[i]);
  free(q);
  return dist_grid;
}

int maximumSafenessFactor(int **grid, int gridSize, int *gridColSize) {
  int n = gridSize;
  if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1)
    return 0;
  int **dist = compute_distance_grid(grid, n);
  struct max_heap *heap = max_heap_init(n * n);
  bool **vis = (bool **)malloc(n * sizeof(bool *));
  for (int i = 0; i < n; i++)
    vis[i] = (bool *)calloc(n, sizeof(bool));
  max_heap_push(heap, (struct node){dist[0][0], 0, 0});
  vis[0][0] = true;
  while (heap->size > 0) {
    struct node curr_node = max_heap_pop(heap);
    int ds0 = curr_node.dist, i = curr_node.i, j = curr_node.j;
    if (i == n - 1 && j == n - 1) {
      free(dist);
      for (int k = 0; k < n; k++)
        free(vis[k]);
      free(vis);
      free(heap->data);
      return ds0;
    }
    for (int d = 0; d < 4; d++) {
      int nr = i + dir[d][0], nc = j + dir[d][1];
      if (valid(nr, nc, n) && grid[nr][nc] != 1 && !vis[nr][nc]) {
        vis[nr][nc] = true;
        int ds1 = dist[nr][nc];
        max_heap_push(heap, (struct node){fmin(ds0, ds1), nr, nc});
      }
    }
  }
  free(dist);
  for (int i = 0; i < n; i++)
    free(vis[i]);
  free(vis);
  free(heap->data);
  free(heap);
  return 0;
}

int main() {
  int g1i[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
  int g2i[4][3] = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
  int g3i[4][4] = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  int r1 = maximumSafenessFactor(g1->arr, g1->row_size, g1->col_size);
  int r2 = maximumSafenessFactor(g2->arr, g2->row_size, g2->col_size);
  int r3 = maximumSafenessFactor(g3->arr, g3->row_size, g3->col_size);
  printf("%d\n", r1);
  assert(r1 == 0);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
