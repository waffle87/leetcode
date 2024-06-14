#include "leetcode.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *pre = new ListNode(0), *curr = head;
    pre->next = head;
    while (curr && curr->next) {
      ListNode *tmp = pre->next;
      pre->next = curr->next;
      curr->next = curr->next->next;
      pre->next->next = tmp;
    }
    return pre->next;
  }
};
