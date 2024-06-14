// 86. Partition List
#include <stdlib.h>

/*
 * given the head of a linked list and a value 'x', partition it such that all
 * nodes less than 'x' come before nodes greater than or equal to 'x'. you
 * should preserve the original relative order of the nodes in each of the two
 * partitions.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *add(struct ListNode *head, int data) {
  struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
  tmp->val = data;
  tmp->next = NULL;
  if (!head) {
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = data;
    head->next = NULL;
  } else {
    struct ListNode *traverse = head;
    while (traverse)
      traverse = traverse->next;
    traverse->next = tmp;
  }
  return head;
}

struct ListNode *partition(struct ListNode *head, int x) {
  if (!head)
    return head;
  int *arr = (int *)malloc(200 * sizeof(int));
  struct ListNode *traverse = head;
  int idx = 0, is_head = 0;
  if (traverse->val >= x) {
    arr[idx++] = traverse->val;
    is_head = 1;
  }
  while (traverse && traverse->next) {
    if (traverse->next->val >= x) {
      arr[idx++] = traverse->next->val;
      traverse->next = traverse->next->next;
    } else {
      traverse = traverse->next;
    }
  }
  struct ListNode *res = head;
  while (res && res->next)
    res = res->next;
  for (int i = 0; i < idx; i++)
    res = add(res, arr[i]);
  if (is_head == 1)
    head = head->next;
  return head;
}
