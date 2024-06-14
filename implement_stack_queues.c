// 225. Implement Stack using Queues
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * implement a last in, first out (LIFO) stack using only two queues. the
 * implemented stack should support all the functions of a normal stack ('push',
 * 'top', 'pop', and 'empty'). implement the 'stack' class
 * - void push(int x) pushes element 'x' to the top of the stack
 * - int pop() removes the element on the top of the stack and returns it
 * - int top() returns the element on the top of the stack
 * - bool empty() returns 'true' if the stack is empty, 'false' otherwise
 * notes:
 * - you must use only standard operations of a queue, which means that only
 * push to back, peek/pop from front, size, and is empty are valid operations.
 * - depending on your language, the queue may not be supported natively. you
 * may simulate a queue using a list of dequeu (double ended queue) as long as
 * you only use a queue's standard operations.
 */

typedef struct {
  int *q;
  int size;
  int front;
  int rear;
} queue;

typedef struct {
  queue *q1;
  queue *q2;
} stack;

int queue_empty(queue *q) {
  if (q->front == -1 && q->rear == -1) {
    printf("\nqueue is EMPTY\n");
    return 1;
  }
  return 0;
}

int queue_full(queue *q) {
  if (q->rear == q->size - 1)
    return 1;
  return 0;
}

int queue_top(queue *q) {
  if (queue_empty(q))
    return -1;
  return q->q[q->front];
}

int queue_pop(queue *q) {
  if (queue_empty(q))
    return -1;
  int data = q->q[q->front];
  if (q->front == q->rear)
    q->front = q->rear = -1;
  else
    q->front++;
  return data;
}

void queue_push(queue *q, int val) {
  if (queue_full(q)) {
    printf("\nqueue is FULL\n");
    return;
  }
  if (queue_empty(q)) {
    q->front++;
    q->rear++;
  } else {
    q->rear++;
  }
  q->q[q->rear] = val;
}

queue *queue_create(int max_size) {
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = q->rear = -1;
  q->size = max_size;
  q->q = (int *)malloc(sizeof(int) * max_size);
  return q;
}

void stackCreate(stack *stk, int max_size) {
  stack **s = (stack **)stk;
  *s = (stack *)malloc(sizeof(stack));
  (*s)->q1 = queue_create(max_size);
  (*s)->q2 = queue_create(max_size);
}

void stackPush(stack *obj, int x) {
  stack **s = (stack **)obj;
  queue_push((*s)->q2, x);
  while (!queue_empty((*s)->q1)) {
    int data = queue_pop((*s)->q1);
    queue_push((*s)->q2, data);
  }
  queue *tmp = (*s)->q1;
  (*s)->q1 = (*s)->q2;
  (*s)->q2 = tmp;
}

int stackPop(stack *obj) {
  stack **s = (stack **)obj;
  return queue_pop((*s)->q1);
}

int stackTop(stack *obj) {
  stack **s = (stack **)obj;
  if (!queue_empty((*s)->q1))
    return queue_top((*s)->q1);
  return -1;
}

bool stackEmpty(stack *obj) {
  stack **s = (stack **)obj;
  if (queue_empty((*s)->q1))
    return true;
  return false;
}

void stackFree(stack *obj) {
  stack **s = (stack **)obj;
  free((*s)->q1);
  free((*s)->q2);
  free((*s));
}

int main() {
  stack *obj = stackCreate();
  stackPush(obj, 1);
  stackPush(obj, 2);
  printf("%d\n", stackTop(obj));   // expect: 2
  printf("%d\n", stackPop(obj));   // expect: 2
  printf("%d\n", stackEmpty(obj)); // expect: 0
}
