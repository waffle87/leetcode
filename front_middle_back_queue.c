// 1670. Design Front Middle Back Queue
#include "leetcode.h"

/*
 * design a queue that supports 'push' and 'pop' operations in the front,
 * middle, and back. notice that when there are two middle position choices, the
 * operation is performed on the frontmost middle position choice.
 */

struct node {
  int val;
  struct node *next;
};

typedef struct {
  struct node *front;
  struct node *rear;
  int cnt;
} FrontMiddleBackQueue;

FrontMiddleBackQueue *frontMiddleBackQueueCreate() {
  FrontMiddleBackQueue *q =
      (FrontMiddleBackQueue *)malloc(sizeof(FrontMiddleBackQueue));
  q->front = NULL;
  q->rear = NULL;
  q->cnt = 0;
  return q;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue *obj, int val) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->val = val;
  new->next = obj->front;
  obj->front = new;
  if (!obj->rear)
    obj->rear = obj->front;
  obj->cnt++;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue *obj, int val) {
  struct node *slow = obj->front;
  if (!slow) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = val;
    new->next = NULL;
    obj->front = new;
    obj->rear = new;
    obj->cnt++;
  } else if (!slow->next) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = val;
    obj->front = new;
    new->next = slow;
    obj->cnt++;
    return;
  }
  struct node *prev_slow = NULL, *fast = obj->front->next;
  while (fast) {
    prev_slow = slow;
    slow = slow->next;
    fast = fast->next;
    if (fast)
      fast = fast->next;
  }
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->val = val;
  prev_slow->next = new;
  new->next = slow;
  obj->cnt++;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue *obj, int val) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->val = val;
  if (obj->rear)
    obj->rear->next = new;
  else
    obj->front = new;
  obj->rear = new;
  new->next = NULL;
  obj->cnt++;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue *obj) {
  if (!obj->front)
    return -1;
  int res = obj->front->val;
  struct node *del = obj->front;
  obj->front = obj->front->next;
  free(del);
  if (!obj->front)
    obj->rear = NULL;
  obj->cnt--;
  return res;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue *obj) {
  struct node *slow = obj->front;
  int res;
  if (!slow)
    return -1;
  if (!slow->next) {
    res = slow->val;
    obj->front = NULL;
    obj->rear = NULL;
    obj->cnt--;
    free(slow);
    return res;
  }
  struct node *prev_slow = NULL, *prev_prev_slow = NULL,
              *fast = obj->front->next;
  while (fast) {
    prev_prev_slow = prev_slow;
    prev_slow = slow;
    slow = slow->next;
    fast = fast->next;
    if (fast)
      fast = fast->next;
  }
  if (!(obj->cnt % 2)) {
    res = prev_slow->val;
    if (obj->cnt == 2) {
      free(prev_slow);
      obj->front = slow;
    } else {
      prev_prev_slow->next = slow;
      free(prev_slow);
    }
  } else {
    res = slow->val;
    prev_slow->next = slow->next;
    free(slow);
  }
  obj->cnt--;
  return res;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue *obj) {
  if (!obj->rear)
    return -1;
  int res = obj->rear->val;
  struct node *trav = obj->front;
  if (trav == obj->rear) {
    obj->front = NULL;
    obj->rear = NULL;
    free(trav);
  } else {
    while (trav->next != obj->rear)
      trav = trav->next;
    trav->next = NULL;
    free(obj->rear);
    obj->rear = trav;
  }
  obj->cnt--;
  return res;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue *obj) {
  struct node *trav = obj->front, *del = NULL;
  while (trav) {
    del = trav;
    trav = trav->next;
    free(del);
  }
  obj->front = NULL;
  obj->rear = NULL;
  obj->cnt = 0;
}

int main() {
  FrontMiddleBackQueue *obj = frontMiddleBackQueueCreate();
  frontMiddleBackQueuePushFront(obj, 1);
  frontMiddleBackQueuePushBack(obj, 2);
  frontMiddleBackQueuePushMiddle(obj, 3);
  frontMiddleBackQueuePushMiddle(obj, 4);
  printf("%d\n", frontMiddleBackQueuePopFront(obj));  // expect: 1
  printf("%d\n", frontMiddleBackQueuePopMiddle(obj)); // expect: 3
  printf("%d\n", frontMiddleBackQueuePopMiddle(obj)); // expect: 4
  printf("%d\n", frontMiddleBackQueuePopBack(obj));   // expect: 2
  printf("%d\n", frontMiddleBackQueuePopFront(obj));  // expect: -1
  frontMiddleBackQueueFree(obj);
}
