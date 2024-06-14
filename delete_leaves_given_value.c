// 1325. Delete Leaves With a Given Value
#include "leetcode.h"

/*
 * given a binary tree 'root' and an integer 'target', delete all the leaf nodes
 * with value 'target'. note that once you delete a leaf node with value
 * 'target', if its parent node becomes a leaf node and has the value 'target',
 * it should also be deleted (you need to continue doing that until you cannot)
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *removeLeafNodes(struct TreeNode *root, int target) {
  if (!root)
    return NULL;
  root->left = removeLeafNodes(root->left, target);
  root->right = removeLeafNodes(root->right, target);
  if (!root->left && !root->right && root->val == target)
    return NULL;
  return root;
}
