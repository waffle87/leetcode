// 2816. Double a Number Represented as a Linked List
#include "leetcode.h"

/*
 * given the 'head' of a non-empty linked list representing a non negative
 * integer without leading zeros. return the 'head' of the linked list after
 * doubling it.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

int depth(struct ListNode *head) {
  int n = 0;
  struct ListNode *tmp = head;
  while (tmp) {
    tmp = tmp->next;
    n++;
  }
  return n;
}

struct ListNode *gen_list(int *arr, int len) {
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *node = head;
  for (int i = 0; i < len; i++)
    if ((!i && arr[i]) || i) {
      node->val = arr[i];
      if (i == len - 1)
        break;
      struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
      node->next = tmp;
      node = node->next;
    }
  node->next = NULL;
  return head;
}

struct ListNode *doubleIt(struct ListNode *head) {
  int n = depth(head) + 1, *arr = (int *)calloc(n, sizeof(int));
  struct ListNode *tmp = head;
  for (int i = 1; i < n; i++) {
    arr[i] = tmp->val << 1;
    tmp = tmp->next;
  }
  int j = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] >= 10) {
      arr[i] += j;
      j = arr[i] / 10;
      arr[i] %= 10;
    } else {
      arr[i] += j;
      j = 0;
    }
  }
  struct ListNode *ans = gen_list(arr, n);
  free(arr);
  return ans;
}
