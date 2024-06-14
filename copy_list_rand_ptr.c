// 138. Copy List with Random Pointer
#include <stdlib.h>

/*
  A linked list of length n is given such that each node contains an additional
  random pointer, which could point to any node in the list, or null.

  Construct a deep copy of the list. The deep copy should consist of exactly n
  brand new nodes, where each new node has its value set to the value of its
  corresponding original node. Both the next and random pointer of the new nodes
  should point to new nodes in the copied list such that the pointers in the
  original list and copied list represent the same list state. None of the
  pointers in the new list should point to nodes in the original list.

  For example, if there are two nodes X and Y in the original list, where
  X.random
  --> Y, then for the corresponding two nodes x and y in the copied list,
  x.random
  --> y.

  Return the head of the copied linked list.

  The linked list is represented in the input/output as a list of n nodes. Each
  node is represented as a pair of [val, random_index] where:

      val: an integer representing Node.val
      random_index: the index of the node (range from 0 to n-1) that the random
  pointer points to, or null if it does not point to any node.

  Your code will only be given the head of the original linked list.
*/

struct Node {
  int val;
  struct Node *next;
  struct Node *random;
};

int find_position(struct Node *head, struct Node *random) {
  if (!random)
    return -1;
  struct Node *tmp = head;
  int idx = 0;
  while (tmp) {
    if (tmp == random)
      return idx;
    idx++;
    tmp = tmp->next;
  }
  return -1;
}

struct Node *copy_step(struct Node *head, struct Node *new_table) {
  struct Node *new_head = malloc(sizeof(struct Node));
  int cnt = 0;
  new_head->val = head->val;
  new_head->next = NULL;
  struct Node *ptr = new_head, *tmp = head->next;
  new_table[cnt] = ptr;
  cnt++;
  while (tmp) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = tmp->val;
    ptr->next = n;
    ptr = n;
    tmp = tmp->next;
    new_table[cnt] = ptr;
    cnt++;
  }
  ptr->next = NULL;
  return new_head;
}

struct Node *copyRandomList(struct Node *head) {
  if (!head)
    return NULL;
  int random_idx[1000], cnt = 0;
  struct Node *new_table[1000], *tmp = head;
  while (tmp) {
    random_idx[cnt] = find_position(head, tmp->random);
    tmp = tmp->next;
    cnt++;
  }
  struct Node *new_head = copy_step(head, new_table);
  struct Node *new_tmp = new_head;
  for (int i = 0; i < cnt; i++) {
    if (random_idx[i] == -1)
      new_tmp->random = NULL;
    else
      new_tmp->random = new_table[random_idx[i]];
    new_tmp = new_tmp->next;
  }
  return new_head;
}
