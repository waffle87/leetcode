#include "leetcode.h"

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *fTmp = new ListNode(0), *bTmp = new ListNode(0), *front = fTmp,
             *back = bTmp, *curr = head;
    while (curr) {
      if (curr->val < x) {
        front->next = curr;
        front = curr;
      } else {
        back->next = curr;
        back = curr;
      }
    }
    front->next = bTmp->next, back->next = nullptr;
    return fTmp->next;
  }
};
