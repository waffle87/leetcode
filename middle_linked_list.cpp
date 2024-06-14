#include "leetcode.h"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *tmp = head;
    int len = 0;
    while (tmp) {
      len++;
      tmp = tmp->next;
    }
    int mid = len / 2;
    tmp = head;
    while (tmp && mid--)
      tmp = tmp->next;
    return tmp;
  }
};
