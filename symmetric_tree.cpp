// 101. Symmetric Tree
#include "leetcode.h"

// given 'root' of binary tree, check whether it is a mirror of itself

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    TreeNode *left, *right;
    if (!root)
      return true;
    queue<TreeNode *> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty()) {
      left = q1.front();
      q1.pop();
      right = q2.front();
      q2.pop();
      if (left == NULL && right == NULL)
        continue;
      if (left == NULL || right == NULL)
        return false;
      if (left->val != right->val)
        return false;
      q1.push(left->left);
      q1.push(left->right);
      q2.push(right->right);
      q2.push(right->left);
    }
    return true;
  }
};
