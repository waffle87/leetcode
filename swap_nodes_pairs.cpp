// 24. Swap Nodes in Pairs
#include "leetcode.h"

/*
 * given a linked list, swap every two adjacent nodes and return
 * its head. problem must be solved without modifying values
 * in the list's nodes (ie only nodes themselves may be changed)
 */

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *tmp;
    tmp = head->next;
    head->next = swapPairs(head->next->next);
    tmp->next = head;
    return tmp;
  }
};
