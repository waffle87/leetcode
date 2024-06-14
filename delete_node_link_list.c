// 237. Delete Node in a Linked List
#include "leetcode.h"

/*
 * there is a singly linked list 'head' and we want to delete a node 'node' in
 * it. you are given the node to be deleted 'node'. you will not be given access
 * to the first node of 'head'. all the values of the linked list are unique and
 * it is guaranteed that the given node 'node' is not the last node in the
 * linked list. delete the given node. note that by deleting the node, we do not
 * mean removing it from memory.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

void deleteNode(struct ListNode *node) {
  struct ListNode *tmp = node, *q = NULL;
  while (tmp->next) {
    q = tmp;
    tmp->val = tmp->next->val;
    tmp = tmp->next;
  }
  q->next = NULL;
  free(tmp);
}
