// 382. Linked List Random Node
#include <stddef.h>
#include <stdlib.h>

/*
 * given singly linked list, return a random node's value from the linked list.
 * each node must have the same probability of being chosen. implement
 * 'Solution' class: f1: initialises object with head of signly linked list
 * 'head' f2: chooses node randomly from list and returns its value. all nodes
 * should be equally likely to be chosen
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct {
  struct ListNode *list;
  size_t size;
} Solution;

Solution *solutionCreate(struct ListNode *head) {
  Solution *obj = (Solution *)malloc(sizeof(Solution));
  obj->list = head;
  while (head->next)
    head = head->next;
  head->next = obj->list;
  return obj;
}

int solutionGetRandom(Solution *obj) {
  struct ListNode *node = obj->list;
  int n = rand() % 10;
  while (n--)
    node = node->next;
  return node->val;
}

void solutionFree(Solution *obj) {
  free(obj->list);
  free(obj);
}

int main() {
  struct ListNode *head;
  Solution *obj = solutionCreate(head);
  int param_1 = solutionGetRandom(obj);
}
