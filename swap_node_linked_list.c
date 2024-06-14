// 1721. Swapping Nodes in a Linked List
#include <stdlib.h>

/*
 * given the 'head' of a linked list, and a an integer 'k', return
 * the head of the linked list after swapping the values of the
 * k'th node from the beginning and the k'th node from the end
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

int countNode(struct ListNode *head) {
  int d = 0;
  struct ListNode *tmp = head;
  while (tmp) {
    d++;
    tmp = tmp->next;
  }
  return d;
}

struct ListNode *swapNodes(struct ListNode *head, int k) {
  int total = countNode(head);
  if (total == 1)
    return head;
  if (total == 2) {
    struct ListNode *tmp = head->next;
    tmp->next = head;
    head->next = NULL;
    head = tmp;
    return head;
  }
  int p = total - k + 1, i = 1;
  struct ListNode *node1 = head;
  struct ListNode *ptr1 = NULL;
  struct ListNode *post1 = NULL;
  while (i < k) {
    ptr1 = node1;
    node1 = node1->next;
    i++;
  }
  post1 = node1->next;
  i = 1;
  struct ListNode *node2 = head;
  struct ListNode *ptr2 = NULL;
  struct ListNode *post2 = NULL;
  while (i < p) {
    ptr2 = node2;
    node2 = node2->next;
    i++;
  }
  post2 = node2->next;
  if (node1 == node2)
    return head;
  if (p - k == 1) {
    ptr1->next = node2;
    node2->next = node1;
    node1->next = post2;
    return head;
  }
  if (k - p == 1) {
    ptr2->next = node1;
    node1->next = node2;
    node2->next = post1;
    return head;
  }
  if (k == 1) {
    node2->next = post1;
    head = node2;
    ptr2->next = node1;
    node1->next = NULL;
  } else if (k == total) {
    node1->next = post2;
    head = node1;
    ptr1->next = node2;
    node2->next = NULL;
  } else {
    ptr1->next = node2;
    node2->next = post1;
    ptr2->next = node1;
    node1->next = post2;
  }
  return head;
}
