// 2290. Minimum Obstacle Removal to Reach Corner
#include "leetcode.h"

/*
 * you are given a 0-indexed 2d integer array 'grid' of size 'm x n'. each cell
 * has one of two values: 0 represents an empty cell, and 1 rperesents an
 * obstacle that may be removed. you can move up, down, left, or right from and
 * to an empty cell. return the minimum number of obstacles to remove so you can
 * move from the upper left corner ('0, 0') to the lower right corner ('m -1, n
 * - 1').
 */

static int dx[] = {-1, 0, 1, 0};
static int dy[] = {0, 1, 0, -1};

struct pair {
  int x;
  int y;
};

struct node {
  struct pair data;
  struct node *next;
  struct node *prev;
};

struct deque {
  struct node *front;
  struct node *rear;
};

void deque_init(struct deque *obj) {
  obj->front = NULL;
  obj->rear = NULL;
}

void push_front(struct deque *obj, struct pair p) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = p;
  n->next = obj->front;
  n->prev = NULL;
  if (obj->front)
    obj->front->prev = n;
  obj->front = n;
  if (!obj->rear)
    obj->rear = n;
}

void push_back(struct deque *obj, struct pair p) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = p;
  n->next = NULL;
  n->prev = obj->rear;
  if (obj->rear)
    obj->rear->next = n;
  obj->rear = n;
  if (!obj->front)
    obj->front = n;
}

struct pair pop_front(struct deque *obj) {
  struct pair data = obj->front->data;
  struct node *tmp = obj->front;
  obj->front = obj->front->next;
  if (obj->front)
    obj->front->prev = NULL;
  else
    obj->rear = NULL;
  free(tmp);
  return data;
}

bool deque_empty(struct deque *obj) { return !obj->front; }

void deque_free(struct deque *obj) {
  while (!deque_empty(obj))
    pop_front(obj);
}

int minimumObstacles(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = gridColSize[0];
  int **dist = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    dist[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      dist[i][j] = INT_MAX;
  }
  struct deque dq;
  deque_init(&dq);
  push_front(&dq, (struct pair){0, 0});
  dist[0][0] = 0;
  while (!deque_empty(&dq)) {
    struct pair p = pop_front(&dq);
    int x = p.x, y = p.y;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        continue;
      int new_dist = dist[x][y] + grid[nx][ny];
      if (new_dist < dist[nx][ny]) {
        dist[nx][ny] = new_dist;
        if (!grid[nx][ny])
          push_front(&dq, (struct pair){nx, ny});
        else
          push_back(&dq, (struct pair){nx, ny});
      }
    }
  }
  int ans = dist[m - 1][n - 1];
  for (int i = 0; i < m; i++)
    free(dist[i]);
  free(dist);
  deque_free(&dq);
  return ans;
}

int main() {
  int g1i[3][3] = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}},
      g2i[3][5] = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
  struct two_d_arr g1, g2;
  two_d_arr_init(&g1, 3, 3, g1i);
  two_d_arr_init(&g2, 3, 5, g2i);
  printf("%d\n",
         minimumObstacles(g1.arr, g1.row_size, g1.col_size)); // expect: 2
  printf("%d\n",
         minimumObstacles(g2.arr, g2.row_size, g2.col_size)); // expect: 0
  two_d_arr_free(&g1), two_d_arr_free(&g2);
}
