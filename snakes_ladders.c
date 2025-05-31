// 909. Snakes and Ladders
#include "leetcode.h"

/*
 * you are given an 'n x n' integer matrix 'board' where the cells are all
 * labeled from 1 to 'n^2' in 'boustropheden style' starting from bottom left of
 * the board, and alternating direction each row. a board square on row 'r' and
 * column 'c' has a snake of a ladder if 'board[r][c] != -1'. the destination of
 * that snake or ladder is 'board[r][c]'. squares 1 and 'n^2' are not the
 * starting points of any snake or ladder. note that you only take a snake or a
 * ladder at most once per dice roll. if the destination to a snake or ladder is
 * the start of another snake or ladder, you do not follow the subsequent snake
 * or ladder.
 */

struct queue {
  int num;
  int moves;
};

void coordinates(int num, int n, int *row, int *col) {
  int r = (num - 1) / n, c = (num - 1) % n;
  if (r % 2 == 1)
    c = n - 1 - c;
  *row = n - 1 - r;
  *col = c;
}

int snakesAndLadders(int **board, int boardSize, int *boardColSize) {
  int n = boardSize * boardSize, front = 0, rear = 0;
  bool *vis = (bool *)calloc(n + 1, sizeof(bool));
  struct queue *q = (struct queue *)malloc(n * sizeof(struct queue));
  q[rear].num = 1;
  q[rear++].moves = 0;
  vis[1] = true;
  while (front < rear) {
    struct queue curr = q[front++];
    if (curr.num == n) {
      free(vis);
      free(q);
      return curr.moves;
    }
    for (int i = 1; i <= 6; i++) {
      int next = curr.num + 1;
      if (next > n)
        continue;
      int row, col;
      coordinates(next, boardSize, &row, &col);
      if (board[row][col] != -1)
        next = board[row][col];
      if (next == n) {
        free(vis);
        free(q);
        return curr.moves + 1;
      }
      if (!vis[next]) {
        vis[next] = true;
        q[rear].num = next;
        q[rear++].moves = curr.moves + 1;
      }
    }
  }
  free(vis);
  free(q);
  return -1;
}

int main() {
  int b1i[6][6] = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
                   {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
                   {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  int b2i[2][2] = {{-1, -1}, {-1, 3}};
  struct two_d_arr b1, b2;
  two_d_arr_init(&b1, ARRAY_SIZE(b1i), ARRAY_SIZE(b1i[0]), b1i);
  two_d_arr_init(&b2, ARRAY_SIZE(b2i), ARRAY_SIZE(b2i[0]), b2i);
  printf("%d\n",
         snakesAndLadders(b1.arr, b1.row_size, b1.col_size)); // expect: 4
  printf("%d\n",
         snakesAndLadders(b2.arr, b2.row_size, b2.col_size)); // expect: 1
  two_d_arr_free(&b1);
  two_d_arr_free(&b2);
}
