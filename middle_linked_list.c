// 876. Middle of the Linked List
#include "leetcode.h"

/*
 * given the head of a singly linked list, return the middle of the node of the
 * linked list. if there are two middle nodes, return the second middle node.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head) {
  struct ListNode *ans;
  int c = 0, i;
  for (ans = head; ans; ans = ans->next, c++)
    ;
  c /= 2;
  for (i = 0, ans = head; i < c; ans = ans->next, i++)
    ;
  return ans;
}
