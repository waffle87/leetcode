// 226. Invert Binary Tree
#include "leetcode.h"

// given 'root' of binary tree, invert the tree and return its root

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return root;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
      TreeNode *tmp = node->left;
      node->left = node->right;
      node->right = tmp;
    }
    return root;
  }
};
