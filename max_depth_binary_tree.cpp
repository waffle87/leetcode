// 104. Maximum Depth of Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return its maximum depth. a binary tree's
 * max depth is the number of nodes along the longest path from the root node
 * down to the farthest leaf node.
 */

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    int max_left = maxDepth(root->left);
    int max_rght = maxDepth(root->right);
    return max(max_left, max_rght) + 1;
  }
};
