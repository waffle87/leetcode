// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
#include "leetcode.h"

/*
 * given an 'm x n' grid. each cell of the grid has a sign pointing to the next
 * cell you shhould visit if you are currently in this cell. notice that there
 * could be some signs on the cells of the grid that point outside the grid. you
 * will initially start at the upper left cell '(0, 0)'. a valid path in the
 * grid is a path that starts from the uppper left cell '(0, 0)' and ends at the
 * bbbottom right cell '(m - 1, n - 1)' following the signs on the grid. the
 * valid path does not have to bbe the shortest. return the minimum cost to make
 * the grid have at least one valid path
 */

struct node {
  int state[2];
  int moves;
};

struct queue {
  struct node data[10000];
  int front, rear;
};

void queue_init(struct queue *obj) {
  obj->front = -1;
  obj->rear = -1;
}

bool queue_empty(struct queue *obj) {
  return obj->front == -1 && obj->rear == -1;
}

void queue_push(struct queue *obj, int *state, int moves) {
  if (queue_empty(obj)) {
    obj->front = 0;
    obj->rear = 0;
  } else
    obj->rear = (obj->rear + 1) % 10000;
  obj->data[obj->rear].state[0] = state[0];
  obj->data[obj->rear].state[1] = state[1];
  obj->data[obj->rear].moves = moves;
}

struct node queue_pop(struct queue *obj) {
  struct node n = obj->data[obj->front];
  if (obj->front == obj->rear) {
    obj->front = -1;
    obj->rear = -1;
  } else
    obj->front = (obj->front + 1) % 10000;
  return n;
}

int minCost(int **grid, int gridSize, int *gridColSize) {
  int n = gridSize, m = *gridColSize, min = INT_MAX;
  int vis[100][100] = {0};
  int **dp = (int **)malloc((n + 1) * sizeof(int *));
  for (int i = 0; i < n + 1; i++)
    dp[i] = (int *)malloc((m + 1) * sizeof(int));
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < m + 1; j++)
      dp[i][j] = -1;
  struct queue q;
  queue_init(&q);
  int init_state[2] = {0, 0};
  queue_push(&q, init_state, 0);
  dp[0][0] = 0;
  while (!queue_empty(&q)) {
    struct node curr = queue_pop(&q);
    int x = curr.state[0], y = curr.state[1];
    int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 1; i < 5; i++) {
      int curr_move = 0, next[2];
      if (grid[x][y] != i)
        curr_move = 1;
      next[0] = x + dir[i][0];
      next[1] = y + dir[i][1];
      int next_move = curr.moves + curr_move;
      if (next[0] == n && next[1] == m && min < next_move)
        min = next_move;
      if (next[0] >= 0 && next[1] >= 0 && next[0] < n && next[1] < m &&
          (!vis[next[0]][next[1]] || dp[next[0]][next[1]] > next_move)) {
        dp[next[0]][next[1]] = next_move;
        vis[next[0]][next[1]] = 1;
        queue_push(&q, next, next_move);
      }
    }
  }
  int ans = dp[n - 1][m - 1];
  for (int i = 0; i < n + 1; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int g1i[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
  int g2i[3][3] = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
  int g3i[2][2] = {{1, 2}, {4, 3}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  printf("%d\n", minCost(g1->arr, g1->row_size, g1->col_size)); // expect: 3
  printf("%d\n", minCost(g2->arr, g2->row_size, g2->col_size)); // expect: 0
  printf("%d\n", minCost(g3->arr, g3->row_size, g3->col_size)); // expect: 1
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
