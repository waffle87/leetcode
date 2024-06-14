// 2487. Remove Nodes From Linked List
#include "leetcode.h"

/*
 * given the 'head' of a linked list, remove evey node which has a node with a
 * greater value anywhere to the right side of it. return the 'head' of the
 * modified linked list.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

int depth(struct ListNode *head) {
  int n = 0;
  struct ListNode *tmp = head;
  while (tmp) {
    n++;
    tmp = tmp->next;
  }
  return n;
}

struct ListNode *removeNodes(struct ListNode *head) {
  int n = depth(head), i = 0;
  struct ListNode **arr =
      (struct ListNode **)malloc(n * sizeof(struct ListNode *));
  struct ListNode *tmp = head;
  while (tmp) {
    arr[i] = tmp;
    i++;
    tmp = tmp->next;
  }
  bool *remove = (bool *)calloc(n, sizeof(bool));
  int max = arr[n - 1]->val;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i]->val < max)
      remove[i] = true;
    else if (arr[i]->val > max)
      max = arr[i]->val;
  }
  struct ListNode *ans;
  for (int i = 0; i < n; i++) {
    if (!remove[i]) {
      ans = arr[i];
      tmp = ans;
      for (int j = i + 1; j < n; j++)
        if (!remove[j]) {
          tmp->next = arr[j];
          tmp = tmp->next;
        }
      tmp->next = NULL;
      break;
    }
  }
  free(arr), free(remove);
  return ans;
}
