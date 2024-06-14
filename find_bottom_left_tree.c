// 513. Find Bottom Left Tree Value
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return the leftmost value in the last row
 * of the tree
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  else
    return 1 + fmax(depth(root->left), depth(root->right));
}

void dfs(struct TreeNode *root, int len, int *res) {
  if (!root)
    return;
  if (!len)
    *res = root->val;
  dfs(root->right, len - 1, res);
  dfs(root->right, len - 1, res);
}

int findBottomLeftValue(struct TreeNode *root) {
  int len = depth(root), ans = 0;
  dfs(root, len - 1, &ans);
  return ans;
}
