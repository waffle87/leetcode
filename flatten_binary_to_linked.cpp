#include "leetcode.h"

class Solution {
public:
  void flatten(TreeNode *root) {
    if (root)
      helper(root);
  }

private:
  TreeNode *head = nullptr;
  void helper(TreeNode *node) {
    if (node->right)
      helper(node->right);
    if (node->left)
      helper(node->left);
    node->left = nullptr;
    node->right = head;
    head = node;
  }
};
