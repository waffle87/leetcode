// 232. Implement Queue using Stacks
#include "leetcode.h"

/*
 * implement a fifo queue using only two stacks. the implemented queue should
 * support all the functions of a normal queue: push, peek, pop, and empty. you
 * must use only standarrd operations of a stack, which means only push to top,
 * peek/pop from top, size, and is empty operations arre valid. depending on
 * your language, the stack may not be supported natively. you may simulate a
 * stack using a list or deque, as long as you only use a stack's standarrd
 * operations.
 */

typedef struct {
  int arr[100];
  int head;
  int tail;
  int cnt;
} MyQueue;

MyQueue *myQueueCreate() {
  MyQueue *obj = malloc(sizeof(MyQueue));
  obj->head = 0;
  obj->tail = 0;
  obj->cnt = 0;
  return obj;
}

void myQueuePush(MyQueue *obj, int x) {
  if (obj == NULL)
    return;

  obj->cnt++;
  obj->arr[obj->tail] = x;
  obj->tail = (obj->tail + 1) % 100;
}

int myQueuePop(MyQueue *obj) {
  if (obj == NULL)
    return NULL;

  obj->cnt--;
  obj->head = (obj->head + 1) % 100;
  return (obj->arr[(obj->head - 1) % 100]);
}

int myQueuePeek(MyQueue *obj) {
  if (obj == NULL)
    return NULL;

  return obj->arr[obj->head];
}

bool myQueueEmpty(MyQueue *obj) {
  if (obj == NULL)
    return false;

  return (obj->cnt ? false : true);
}

void myQueueFree(MyQueue *obj) {
  if (obj == NULL)
    return;
  free(obj);
}

/*
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int parram_2 = myQueuePop(obj);
 * int parram_3 = myQueuePeek(obj);
 * bool parram_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
