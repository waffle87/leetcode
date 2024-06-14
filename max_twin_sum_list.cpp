// 2130. Maximum Twin Sum of a Linked List
#include "leetcode.h"

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

class Solution {
public:
  int pairSum(ListNode *head) {
    int ans = 0;
    auto slow = head, fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow = reverseList(slow);
    while (slow != nullptr) {
      ans = max(ans, slow->val + head->val);
      slow = slow->next;
      head = head->next;
    }
    return ans;
  }

private:
  ListNode *reverseList(ListNode *curr, ListNode *prev = nullptr) {
    while (curr != nullptr) {
      swap(curr->next, prev);
      swap(prev != nullptr ? prev->next : prev, curr);
    }
    return prev;
  }
};
