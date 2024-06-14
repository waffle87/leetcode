// 206. Reverse Linked List
#include "leetcode.h"

/*
 * given the 'head' of a singly linked list, reverse the list, and return the
 * reversed list.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  if (!head || !head->next)
    return head;
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = head->val;
  new->next = NULL;
  head = head->next;
  while (head) {
    struct ListNode *tmp = new;
    new = head;
    head = head->next;
    new->next = tmp;
  }
  return new;
}
