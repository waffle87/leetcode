// 19. Remove Nth Node From End of List
#include "leetcode.h"

/*
 * given the 'head' of a linked list, remove the n'th node from the end of the
 * list and return its head
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

int get_len(struct ListNode *head) {
  struct ListNode *traverse = head;
  int n = 0;
  while (traverse) {
    traverse = traverse->next;
    n++;
  }
  return n;
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  int len = get_len(head);
  if (len == 1 && n == 1)
    return NULL;
  if (len == n)
    return head->next;
  int del_idx = len - n - 1;
  struct ListNode *traverse = head;
  while (del_idx) {
    traverse = traverse->next;
    del_idx--;
  }
  traverse->next = traverse->next->next;
  return head;
}
