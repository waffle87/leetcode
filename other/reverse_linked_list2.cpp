#include "leetcode.h"

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *tmp = new ListNode(-1);
    tmp->next = head;
    ListNode *itL = tmp, *preL = NULL;
    for (int i = 0; i < left; i++) {
      preL = itL;
      itL = itL->next;
    }
    ListNode *itR = itL, *preR = preL;
    for (int i = left; i <= right; i++) {
      ListNode *forward = itR->next;
      itR->next = preR;
      preR = itR;
      itR = forward;
    }
    preL->next = preR;
    itL->next = itR;
    return tmp->next;
  }
};
