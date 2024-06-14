// 1171. Remove Zero Sum Consecutive Nodes from Linked List
#include "leetcode.h"

/*
 * given the 'head' of a linked list, we repeatedly delete the consecutive
 * sequences of nodes that sum to 0 until there are no such sequences. after
 * doing so, return the head of the final linked list. you may return any such
 * answer.
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *get_sum(struct ListNode *head) {
  struct ListNode *node = head;
  int sum = 0;
  while (node) {
    sum += node->val;
    if (!sum)
      return node;
    node = node->next;
  }
  return node;
}

struct ListNode *removeZeroSumSublists(struct ListNode *head) {
  struct ListNode *tmp, *node, *prev, *ans;
  tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
  tmp->val = -2000;
  tmp->next = head;
  while (1) {
    prev = tmp;
    node = tmp->next;
    int n = 0;
    while (node) {
      ans = get_sum(node);
      if (ans) {
        prev->next = ans->next;
        n = 1;
        break;
      } else {
        prev = node;
        node = node->next;
      }
    }
    if (!n)
      break;
  }
  return tmp->next;
}
