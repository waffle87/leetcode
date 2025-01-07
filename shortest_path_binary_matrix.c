// 1091. Shortest Path in Binary Matrix
#include "leetcode.h"

/*
 * given an n x n binary matrix 'grid', return the length of the shortest clear
 * path in the matrix. if there is no clear path, return -1. a clear path in a
 * binary matrix is a path from the top-left cell (ie. 0,0) to the bottom-right
 * cell (ie. n - 1, n - 1) such thatyt
 * - all the visited cells are of the path 0
 * - all the adjacent cells of the path are 8-directionally connected (ie. they
 * are different and they share an edge of a corner) the length of a clear path
 * is the number of visited cells of this path
 */

#define MAX_SIZE 100

struct node {
  int row;
  int col;
  int step;
};

struct queue {
  struct node n[MAX_SIZE * MAX_SIZE];
  int front;
  int rear;
};

void queue_init(struct queue *q) {
  q->front = -1;
  q->rear = -1;
}

bool queue_empty(struct queue *q) { return q->front == -1; }

bool queue_full(struct queue *q) { return q->rear == MAX_SIZE * MAX_SIZE - 1; }

void queue_push(struct queue *q, struct node n) {
  if (queue_full(q))
    return;
  if (queue_empty(q))
    q->front = 0;
  q->n[++q->rear] = n;
}

struct node queue_pop(struct queue *q) {
  struct node n = {0, 0, 0};
  if (queue_empty(q))
    return n;
  n = q->n[q->front++];
  if (q->front > q->rear) {
    q->front = -1;
    q->rear = -1;
  }
  return n;
}

bool valid(int row, int col, int n, int **grid) {
  return row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0;
}

int shortestPathBinaryMatrix(int **grid, int gridSize, int *gridColSize) {
  if (grid[0][0] == 1)
    return -1;
  int dir[8][2] = {{0, 1},   {1, 0},  {0, -1}, {-1, 0},
                   {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  int n = gridSize;
  bool vis[MAX_SIZE][MAX_SIZE] = {false};
  struct queue q;
  queue_init(&q);
  vis[0][0] = true;
  struct node start = {0, 0, 1};
  queue_push(&q, start);
  while (!queue_empty(&q)) {
    struct node curr = queue_pop(&q);
    if (curr.row == n - 1 && curr.col == n - 1)
      return curr.step;
    for (int i = 0; i < 8; i++) {
      int nr = curr.row + dir[i][0], nc = curr.col + dir[i][1];
      if (valid(nr, nc, n, grid) && !vis[nr][nc]) {
        vis[nr][nc] = true;
        struct node next = {nr, nc, curr.step + 1};
        queue_push(&q, next);
      }
    }
  }
  return -1;
}

int main() {
  int g1i[2][2] = {{0, 1}, {1, 0}};
  int g2i[3][3] = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int g3i[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  struct two_d_arr g1, g2, g3;
  two_d_arr_init(&g1, 2, 2, g1i);
  two_d_arr_init(&g2, 3, 3, g2i);
  two_d_arr_init(&g3, 3, 3, g3i);
  printf("%d\n", shortestPathBinaryMatrix(g1.arr, g1.row_size,
                                          g1.col_size)); // expect: 2
  printf("%d\n", shortestPathBinaryMatrix(g2.arr, g2.row_size,
                                          g3.col_size)); // expect: 4
  printf("%d\n", shortestPathBinaryMatrix(g3.arr, g3.row_size,
                                          g3.col_size)); // expect: -1
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
  two_d_arr_free(&g3);
}
