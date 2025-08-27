// 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
#include "leetcode.h"

/*
 * given an 'm x n' binary matrix 'mat'. in one step, you can choose one cell
 * and flip it and all the four neighbours of it if they exist (fip is changing
 * 1 to 0, and 0 to 1). a pair ofcells are called neighbours if their share one
 * edge. return the minimum number of steps required to convert 'mat' to a zero
 * matrix or -1 if you cannot. a binary matrix isa matrix with all cells equal
 * to 0 or 1 only. a zero matrix is a matrix with all cells equal to 0.
 */

struct queue_node {
  int state;
  int step;
};

void push(struct queue_node q[], int *tail, int state, int step) {
  q[*tail].state = state;
  q[*tail].step = step;
  (*tail)++;
}

int pop_state(struct queue_node q[], int *head) {
  (*head)++;
  return q[*head].state;
}

int pop_step(struct queue_node q[], int *head) { return q[*head].step; }

int minFlips(int **mat, int matSize, int *matColSize) {
  int n = matSize, m = *matColSize, start = 0, head = -1, tail = 0;
  int dx[5] = {0, 0, 1, 0, -1};
  int dy[5] = {0, 1, 0, -1, 0};
  struct queue_node *q =
      (struct queue_node *)malloc((1 << (n * m)) * sizeof(struct queue_node));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j])
        start += 1 << (j + i * m);
  if (!start)
    return 0;
  bool *occur = (bool *)calloc(1, (1LL << (n * m)) * sizeof(bool));
  occur[start] = true;
  push(q, &tail, start, 0);
  while (head + 1 < tail) {
    int curr_state = pop_state(q, &head);
    int curr_step = pop_step(q, &head);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int new_state = curr_state;
        for (int k = 0; k < 5; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            new_state ^= 1 << (ny + nx * m);
        }
        if (!new_state) {
          free(q), free(occur);
          return curr_step + 1;
        } else if (!occur[new_state]) {
          occur[new_state] = true;
          push(q, &tail, new_state, curr_step + 1);
        }
      }
    }
  }
  free(q), free(occur);
  return -1;
}

int main() {
  int m1i[2][2] = {{0, 0}, {0, 1}}, m2i[1][1] = {{0}},
      m3i[2][3] = {{1, 0, 0}, {1, 0, 0}};
  struct two_d_arr *m1 = two_d_arr_init(2, 2, m1i);
  struct two_d_arr *m2 = two_d_arr_init(1, 1, m2i);
  struct two_d_arr *m3 = two_d_arr_init(2, 3, m3i);
  printf("%d\n", minFlips(m1->arr, m1->row_size, m1->col_size)); // expect: 3
  printf("%d\n", minFlips(m2->arr, m2->row_size, m2->col_size)); // expect: 0
  printf("%d\n", minFlips(m3->arr, m3->row_size, m3->col_size)); // expect: -1
  two_d_arr_free(m1);
  two_d_arr_free(m2);
  two_d_arr_free(m3);
}
