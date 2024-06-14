#include "leetcode.h"

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode *odd = NULL, *headOdd = NULL, *even = NULL, *headEven = NULL;
    if (!head || !head->next || !head->next->next)
      return head;
    odd = head;
    headOdd = odd;
    even = head->next;
    headEven = even;
    while (even && even->next) {
      odd->next = odd->next->next;
      even->next = even->next->next;
      odd = odd->next;
      even = even->next;
    }
    odd->next = headEven;
    return headOdd;
  }
};
