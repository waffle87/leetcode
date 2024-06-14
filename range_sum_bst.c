// 938. Range Sum of BST
#include "leetcode.h"

/*
 * given the 'root' of a binary search tree and two integers 'low' and 'high',
 * return the sum of values of all nodes with a value in the inclusive range
 * '(low, high)'
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int rangeSumBST(struct TreeNode *root, int low, int high) {
  if (!root)
    return 0;
  else if (root->val >= low && root->val <= high)
    return root->val + rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  else
    return rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
}
