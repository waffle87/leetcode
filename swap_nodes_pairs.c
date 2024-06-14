// 24. Swap Nodes in Pairs

/*
 * given a linked list, swap every two adjacent nodes and return
 * its head. problem must be solved without modifying values
 * in the list's nodes (ie only nodes themselves may be changed)
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) {
  if (!head || !head->next)
    return head;
  struct ListNode *tmp = head->next;
  head->next = swapPairs(head->next->next);
  tmp->next = head;
  return tmp;
}
