#include "leetcode.h"

class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    if (head->next == nullptr)
      return nullptr;
    auto slow = head, fast = head->next->next;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};
