// 1026. Maximum Difference Between Node and Ancestor
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, find the maximum value 'v' for which there
 * exists different nodes 'a' and 'b' where 'v = | a.val - b.val |' and 'a' is
 * an ancesotr of 'b'. a node 'a' is an ancesotr of 'b' if either any child if
 * 'a' is equal to 'b' or any child 'a' is an ancestor of 'b'.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int helper(struct TreeNode *node, int min_seen, int max_seen) {
  int leftdiff, rightdiff;
  if (!(node->val < min_seen || node->val > max_seen))
    ;
  else {
    if (node->val > max_seen)
      max_seen = node->val;
    else
      min_seen = node->val;
  }
  int diff = max_seen - min_seen;
  if (node->left == NULL && node->right == NULL)
    return diff;
  else if (!(node->left != NULL && node->right != NULL)) {
    if (node->left == NULL) {
      leftdiff = 0;
      rightdiff = helper(node->right, min_seen, max_seen);
      return (rightdiff > diff ? rightdiff : diff);
    } else {
      rightdiff = 0;
      leftdiff = helper(node->left, min_seen, max_seen);
      return (leftdiff > diff ? leftdiff : diff);
    }
  } else {
    leftdiff = helper(node->left, min_seen, max_seen);
    rightdiff = helper(node->right, min_seen, max_seen);
    return leftdiff > rightdiff ? leftdiff : rightdiff;
  }
}

int maxAncestorDiff(struct TreeNode *root) {
  return !root ? 0 : helper(root, root->val, root->val);
}
