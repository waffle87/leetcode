// 530. Minimum Absolute Difference in BST
#include "leetcode.h"

/*
 * given the 'root' of a binary search tree (bst), return the minimum absolute
 * difference between the values of any two different nodes in the tree
 */

class Solution {
  int diff = INT_MAX;
  TreeNode *prev = NULL;
  void dfs(TreeNode *root) {
    if (root->left)
      dfs(root->left);
    if (prev)
      diff = min(diff, abs(prev->val - root->val));
    prev = root;
    if (root->right)
      dfs(root->right);
  }

public:
  int getMinimumDifference(TreeNode *root) {
    dfs(root);
    return diff;
  }
};
