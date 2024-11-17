// 862 Shortest Subarray with Sum at Least K
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k' return the length of the
 * shortest non empty subarray of 'nums' with a sum of at least 'k'. if there is
 * no such subarray, return -1. a subarray is a contiguous part of an array
 */

struct element {
  int idx;
  long long prefix_sum;
};

struct deque {
  struct element *data;
  int front;
  int rear;
  int size;
  int capacity;
};

struct deque *create_deque(int capacity) {
  struct deque *dq = (struct deque *)malloc(sizeof(struct deque));
  dq->data = (struct element *)malloc(capacity * sizeof(struct element));
  dq->front = 0;
  dq->rear = -1;
  dq->size = 0;
  dq->capacity = capacity;
  return dq;
}

bool is_empty(struct deque *dq) { return !dq->size; }

void push_back(struct deque *dq, struct element e) {
  dq->rear = (dq->rear + 1) % dq->capacity;
  dq->data[dq->rear] = e;
  dq->size++;
}

struct element pop_front(struct deque *dq) {
  struct element e = dq->data[dq->front];
  dq->front = (dq->front + 1) % dq->capacity;
  dq->size--;
  return e;
}

struct element back(struct deque *dq) { return dq->data[dq->rear]; }

struct element front(struct deque *dq) { return dq->data[dq->front]; }

void pop_back(struct deque *dq) {
  dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
  dq->size--;
}

void free_deque(struct deque *dq) {
  free(dq->data);
  free(dq);
}

int shortestSubarray(int *nums, int numsSize, int k) {
  long long *prefix_sum =
      (long long *)malloc((numsSize + 1) * sizeof(long long));
  prefix_sum[0] = 0;
  for (int i = 0; i < numsSize; i++)
    prefix_sum[i + 1] = prefix_sum[i] + nums[i];
  struct deque *dq = create_deque(numsSize + 1);
  int min_len = INT_MAX;
  for (int i = 0; i <= numsSize; i++) {
    while (!is_empty(dq) && prefix_sum[i] - front(dq).prefix_sum >= k) {
      min_len = (i - front(dq).idx) < min_len ? (i - front(dq).idx) : min_len;
      pop_front(dq);
    }
    while (!is_empty(dq) && prefix_sum[i] <= back(dq).prefix_sum) {
      pop_back(dq);
    }
    struct element e = {i, prefix_sum[i]};
    push_back(dq, e);
  }
  free(prefix_sum);
  free_deque(dq);
  return min_len == INT_MAX ? -1 : min_len;
}

int main() {
  int n1[] = {1}, n2[] = {1, 2}, n3[] = {2, -1, 2};
  printf("%d\n", shortestSubarray(n1, ARRAY_SIZE(n1), 1)); // expect: 1
  printf("%d\n", shortestSubarray(n2, ARRAY_SIZE(n2), 4)); // expect: -1
  printf("%d\n", shortestSubarray(n3, ARRAY_SIZE(n3), 3)); // expect: 3
}
