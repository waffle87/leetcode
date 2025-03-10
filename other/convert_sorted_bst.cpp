// 109. Convert Sorted List to Binary Search Tree
#include "leetcode.h"

/*
 * given 'head' of a singly linked list where elements are sorted in ascending
 * order convert it to a height balanced binary search tree. meaning the depth
 * of two sub- trees of every node never differs by more than one.
 */

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)
      return NULL;
    if (!head->next)
      return new TreeNode(head->val);
    auto slow = head, fast = head, pre = head;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = 0;
    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
  }
};
