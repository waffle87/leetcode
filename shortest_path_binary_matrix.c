// 1091. Shortest Path in Binary Matrix
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct pair {
  int x;
  int y;
} pair_t;

typedef pair_t queue_data_t;

typedef enum queue {
  QUEUE_OK,
  QUEUE_EMPTY,
  QUEUE_FULL,
  QUEUE_ERROR = 0xFF
} queue_er_em;

typedef struct queue_t {
  queue_data_t *value;
  int buf_size;
  int offer_i;
  int poll_i;
  int cnt;
} queue_t;

queue_t *create_queue(int buf_size) {
  queue_t *q = malloc(sizeof(queue_t));
  memset(q, 0, sizeof(queue_t));
  q->buf_size = buf_size;
  q->value = malloc(buf_size * sizeof(queue_data_t));
  memset(q->value, 0, buf_size * sizeof(queue_data_t));
  return q;
}

queue_er_em offer_queue(queue_t *q, queue_data_t *data) {
  assert(q->cnt < q->buf_size);
  if (q->cnt >= q->buf_size)
    return QUEUE_ERROR;
  memcpy(&q->value[q->offer_i++], data, sizeof(queue_data_t));
  if (q->offer_i == q->buf_size)
    q->offer_i = 0;
  q->cnt++;
  return QUEUE_OK;
}

queue_er_em poll_queue(queue_t *q, queue_data_t *data) {
  assert(q->cnt);
  if (q->cnt < 1)
    return QUEUE_EMPTY;
  memcpy(data, &q->value[q->poll_i++], sizeof(queue_data_t));
  if (q->poll_i == q->buf_size)
    q->poll_i = 0;
  q->cnt--;
  return QUEUE_OK;
}

inline int get_data(queue_t *q) { return q->cnt; }

bool empty(queue_t *q) { return (q->cnt); }

int shortestPathBinaryMatrix(int **grid, int grid_size, int *grid_col_size) {
  if (grid[0][0] == 1)
    return -1;
  queue_t *buf = create_queue(500);
  int dirr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
  pair_t p = {.x = 0, .y = 0};
  pair_t tmp;
  int cnt = 0;
  offer_queue(buf, &p);
  while (!empty(buf)) {
    int c = get_data(buf);
    cnt++;
    for (int i = 0; i < c; i++) {
      poll_queue(buf, &p);
      if (p.x == grid_size - 1 && p.y == grid_col_size[0] - 1)
        return cnt;
      for (int j = 0; j < 8; j++) {
        int tr = p.x + dirr[j][0];
        int tc = p.y + dirr[j][1];
        if (tr >= 0 && tr < grid_size && tc >= 0 && tc < grid_col_size[0] &&
            !grid[tr][tc]) {
          tmp.x = tr;
          tmp.y = tc;
          offer_queue(buf, &tmp);
          grid[tr][tc] = -1;
        }
      }
    }
  }
  return -1;
}

int main() int g1[2][2] = {{0, 1}, {1, 0}}, gs1 = 2, gcs1[] = { 2, 2 };
int g2[3][3] = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}}, gs2 = 3, gcs[] = {3, 3, 3};
int g3[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}, gs3 = 3, gc3[] = {3, 3, 3};
printf("%d\n", shortestPathBinaryMatrix(g1, gs1, gc1)); // expect: 2
printf("%d\n", shortestPathBinaryMatrix(g2, gs2, gc2)); // expect: 4
printf("%d\n", shortestPathBinaryMatrix(g3, gs3, gc3)); // expect: -1
}
