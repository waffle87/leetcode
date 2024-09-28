// 641. Design Circular Deque
#include "leetcode.h"

/*
 * design your implementation of the circular double ended queue (deque).
 * implement the 'MyCircularDeque' class
 */

struct node {
  struct node *next;
  struct node *prev;
  int val;
};

typedef struct {
  struct node *head;
  struct node *tail;
  int size;
  int max_size;
} MyCircularDeque;

MyCircularDeque *myCircularDequeCreate(int k) {
  MyCircularDeque *dq = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
  dq->head = (struct node *)malloc(sizeof(struct node));
  dq->tail = (struct node *)malloc(sizeof(struct node));
  dq->head->next = dq->tail;
  dq->head->prev = NULL;
  dq->tail->prev = dq->head;
  dq->tail->next = NULL;
  dq->size = 0;
  dq->max_size = k;
  return dq;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value) {
  if (obj->size == obj->max_size)
    return false;
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->val = value;
  n->prev = obj->head;
  n->next = obj->head->next;
  obj->head->next->prev = n;
  obj->head->next = n;
  obj->size++;
  return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value) {
  if (obj->size == obj->max_size)
    return false;
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->val = value;
  n->prev = obj->tail->prev;
  n->next = obj->tail;
  obj->tail->prev->next = n;
  obj->tail->prev = n;
  obj->size++;
  return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj) {
  if (!obj->size)
    return false;
  struct node *back = obj->head->next;
  obj->head->next->next->prev = obj->head;
  obj->head->next = obj->head->next->next;
  obj->size--;
  free(back);
  return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj) {
  if (!obj->size)
    return false;
  struct node *back = obj->tail->prev;
  obj->tail->prev->prev->next = obj->tail;
  obj->tail->prev = obj->tail->prev->prev;
  obj->size--;
  free(back);
  return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj) {
  return !obj->size ? -1 : obj->head->next->val;
}

int myCircularDequeGetRear(MyCircularDeque *obj) {
  return !obj->size ? -1 : obj->tail->prev->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque *obj) { return !obj->size; }

bool myCircularDequeIsFull(MyCircularDeque *obj) {
  return obj->size == obj->max_size;
}

void myCircularDequeFree(MyCircularDeque *obj) {
  struct node *curr = obj->head;
  while (curr) {
    struct node *back = curr;
    curr = curr->next;
    free(back);
  }
}

int main() {
  MyCircularDeque *obj = myCircularDequeCreate(3);
  printf("%d\n", myCircularDequeInsertLast(obj, 1));  // expect: 1
  printf("%d\n", myCircularDequeInsertLast(obj, 2));  // expect: 1
  printf("%d\n", myCircularDequeInsertFront(obj, 3)); // expect: 1
  printf("%d\n", myCircularDequeInsertFront(obj, 4)); // expect: 0
  printf("%d\n", myCircularDequeGetRear(obj));        // expect: 2
  printf("%d\n", myCircularDequeIsFull(obj));         // expect: 1
  printf("%d\n", myCircularDequeDeleteLast(obj));     // expect: 1
  printf("%d\n", myCircularDequeInsertFront(obj, 4)); // expect: 1
  printf("%d\n", myCircularDequeGetFront(obj));       // expect: 4
  myCircularDequeFree(obj);
}
