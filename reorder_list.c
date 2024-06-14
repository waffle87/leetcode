// 143. Reorder List
#include "leetcode.h"

/*
 * given the head of a singly linked list. the list can be represented as 'l0 ->
 * l1 -> ... -> Ln'. reorder the list to be of the following form: 'l0 -> ln ->
 * ln-1 -> ln-2'. you may not modify the values in the list's nodes. only nodes
 * themselves may be changed.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *get_mid(struct ListNode *head) {
  struct ListNode *fast = head, *slow = head;
  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

struct ListNode *reverse(struct ListNode *head) {
  struct ListNode *tail = NULL;
  while (head) {
    struct ListNode *curr = head;
    head = head->next;
    curr->next = tail;
    tail = curr;
  }
  return tail;
}

void merge(struct ListNode *n, struct ListNode *m) {
  struct ListNode *head = n;
  while (m) {
    struct ListNode *tmp = m->next;
    m->next = head->next;
    head->next = m;
    head = head->next->next;
    m = tmp;
  }
}

void reorderList(struct ListNode *head) {
  if (!head || !head->next || !head->next->next)
    return;
  struct ListNode *mid = get_mid(head), *half = mid->next;
  mid->next = NULL;
  half = reverse(half);
  merge(head, half);
}
