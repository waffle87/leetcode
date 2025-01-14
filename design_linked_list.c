// 707. Design Linked List
#include "leetcode.h"

/*
 * design your implementation of the linked list. you can choose to use a singly
 * or doubly linked list. a node in a singly linked list should have two
 * attributes: 'val' and 'next'. 'val' is the value of the current node, and
 * 'next' is a pointing/reference to the next code. if you want to use the
 * doubly linked list, you will need one more attribute 'prev' to indicate the
 * previous node  in the linked list. assume all nodes in the linked list are
 * 0-indexed to indicate the previous node  in the linked list. assume all nodes
 * in the linked list are 0-indexed.
 */

typedef struct List {
  int val;
  struct List *next;
} MyLinkedList;

MyLinkedList *myLinkedListCreate() {
  MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  obj->val = -1;
  obj->next = NULL;
  return obj;
}

int myLinkedListGet(MyLinkedList *obj, int index) {
  obj = obj->next;
  int cnt = 0;
  while (obj) {
    if (cnt == index)
      return obj->val;
    cnt++;
    obj = obj->next;
  }
  return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
  MyLinkedList *tmp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  tmp->val = val;
  tmp->next = obj->next;
  obj->next = tmp;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
  while (obj && obj->next)
    obj = obj->next;
  MyLinkedList *tmp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  tmp->val = val;
  tmp->next = NULL;
  obj->next = tmp;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
  int cnt = 0;
  MyLinkedList *tmp = obj;
  while (tmp) {
    if (cnt == index) {
      MyLinkedList *curr = (MyLinkedList *)malloc(sizeof(MyLinkedList));
      curr->val = val;
      curr->next = tmp->next;
      tmp->next = curr;
      break;
    }
    cnt++;
    tmp = tmp->next;
  }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
  int cnt = 0;
  MyLinkedList *curr = obj->next, *pre = obj;
  while (curr) {
    if (cnt == index) {
      pre->next = curr->next;
      free(curr);
      return;
    }
    cnt++;
    pre = curr;
    curr = curr->next;
  }
}

void myLinkedListFree(MyLinkedList *obj) {
  while (obj) {
    MyLinkedList *tmp = obj;
    obj = obj->next;
    free(tmp);
  }
}

int main() {
  MyLinkedList *obj = myLinkedListCreate();
  myLinkedListAddAtHead(obj, 1);
  myLinkedListAddAtTail(obj, 3);
  myLinkedListAddAtIndex(obj, 1, 2);
  printf("%d\n", myLinkedListGet(obj, 1)); // expect: 2
  myLinkedListDeleteAtIndex(obj, 1);
  printf("%d\n", myLinkedListGet(obj, 1)); // expect: 3
  myLinkedListFree(obj);
}
