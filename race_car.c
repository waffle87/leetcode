// 818. Race Car
#include "leetcode.h"

/*
 * your car starts at position 0 and speed +1 on an infinite number line. your
 * car can go into negative positions. your car drives automatically according
 * to a sequence of instructions 'A' (accelerate), and 'R' (reverse). given a
 * target position 'target', return the length of the shortest sequence of
 * instructions to get there.
 */

#define MAX_POW_2 20

struct args {
  int position;
  int speed;
};

struct queue {
  struct args *a;
  int prev;
  int curr;
  size_t len;
};

int *get_pow_2(void) {
  int *res = (int *)malloc(2 * MAX_POW_2 * sizeof(int));
  res[0] = 1;
  for (int i = 1; i < MAX_POW_2; ++i)
    res[i] = res[i - 1] * 2;
  res[MAX_POW_2] = -1;
  for (int i = MAX_POW_2 + 1; i < MAX_POW_2 * 2; ++i)
    res[i] = res[i - 1] * 2;
  return res;
}

void queue_init(struct queue *q) {
  q->a = (struct args *)malloc(128 * sizeof(struct args *));
  q->len = 128;
  q->prev = -1;
  q->curr = 0;
}

void queue_push(struct queue *q, struct args a) {
  q->prev++;
  if (q->prev >= q->len) {
    q->a = (struct args *)realloc(q->a, 2 * q->len * sizeof(struct args));
    q->len *= 2;
  }
  q->a[q->prev] = a;
}

struct args queue_pop(struct queue *q) {
  struct args res = q->a[q->curr];
  q->curr++;
  return res;
}

bool queue_empty(struct queue *q) { return q->curr > q->prev || q->prev == -1; }

void queue_free(struct queue *q) { free(q->a); }

int racecar(int target) {
  int *pow = get_pow_2();
  int row_size = 2 * target + 1;
  int col_size = 2 * MAX_POW_2;
  int *vis[row_size];
  for (int i = 0; i < row_size; ++i) {
    vis[i] = (int *)malloc(col_size * sizeof(int));
    memset(vis[i], -1, col_size * sizeof(int));
  }
  struct queue q;
  queue_init(&q);
  struct args initial;
  initial.position = 0;
  initial.speed = 0;
  vis[initial.position][initial.speed] = 0;
  queue_push(&q, initial);
  while (!queue_empty(&q)) {
    struct args curr = queue_pop(&q);
    if (curr.position + pow[curr.speed] < row_size &&
        curr.position + pow[curr.speed] >= 0 &&
        vis[curr.position + pow[curr.speed]][1 + curr.speed] == -1) {
      vis[curr.position + pow[curr.speed]][1 + curr.speed] =
          vis[curr.position][curr.speed] + 1;
      if (curr.position + pow[curr.speed] == target)
        return vis[curr.position + pow[curr.speed]][1 + curr.speed];
      struct args next;
      next.position = curr.position + pow[curr.speed];
      next.speed = curr.speed + 1;
      queue_push(&q, next);
    }
    int change = curr.speed < MAX_POW_2 ? MAX_POW_2 : 0;
    if (vis[curr.position][change] == -1) {
      vis[curr.position][change] = vis[curr.position][curr.speed] + 1;
      struct args next;
      next.position = curr.position;
      next.speed = change;
      queue_push(&q, next);
    }
  }
  for (int i = 0; i < row_size; i++)
    free(vis[i]);
  free(pow);
  queue_free(&q);
  return -1;
}

int main() {
  printf("%d\n", racecar(3)); // expect: 2
  printf("%d\n", racecar(6)); // expect: 5
}
