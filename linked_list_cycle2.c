// 142. Linked List Cycle II
#include <stdio.h>
#include <stdlib.h>

/*
 * given 'head' of linked list, return node where the cycle begins. if there is
 * no cycle return null. there is a cycle in linked list of there is some node
 * in the list that can be reached again by continuously following the 'next'
 * pointer. internally, 'pos' is used to denote the index of the node that
 * tail's 'next' pointer is connected to. it is -1 if there is no cycle. note
 * 'pos' is not passed as parameter.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  if (!(fast && fast->next))
    return NULL;
  while (head != slow) {
    head = head->next;
    slow = slow->next;
  }
  return head;
}
