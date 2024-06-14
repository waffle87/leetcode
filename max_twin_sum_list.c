// 2130. Maximum Twin Sum of a Linked List
#include <stdlib.h>

/*
 * in a linked-list of size 'n', where 'n' is even, the i'th node (0-indexed) of
 * the linked list is known as the twin of the 'n - 1 - i' node, if 0 <= i <= (n
 * / 2) - 1. for example, if 'n = 4', then node 0 is the twin of node 3, and
 * node 1 is the twin node of node 2. these are the only nodes with twins for 'n
 * = 4'. the twin sum is defined as the sum of a node and its twin. given the
 * 'head' of a linked list with even length, return the maximum twin sum of the
 * linked list.
 *
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

int pairSum(struct ListNode *head) {
  int arr[100001], i = 0, j;
  while (head) {
    arr[i++] = head->val;
    head = head->next;
  }
  i--;
  int max = -1;
  for (int j = 0; j <= i / 2; j++)
    if (arr[j] + arr[i - j] > max)
      max = arr[j] + arr[i - j];
  return max;
}
