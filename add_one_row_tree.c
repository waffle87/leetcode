// 623. Add One Row to Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree and two integers 'val' and 'depth', add a
 * row of nodes with value 'val' at the given depth 'depth'. note that 'root'
 * node is at depth 1. the adding rule is given the integer 'depth' for each
 * non-null tree node 'curr' at the depth 'depth - 1' create two tree nodes with
 * value 'val' as 'curr's left subtree root and right subtree root. 'curr's
 * original left subtree should be the left subtree of the new left subtree
 * root. if 'depth == 1' that means that there is no depth 'depth - 1' at all,
 * then create a tree node with value 'val' as the new root of the whole
 * original tree, and the original tree is the new left subtree.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *addOneRow(struct TreeNode *root, int val, int depth) {
  if (depth == 1) {
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = root;
    new->right = NULL;
    root = new;
    return root;
  }
  if (depth == 2) {
    struct TreeNode *left = malloc(sizeof(struct TreeNode));
    struct TreeNode *right = malloc(sizeof(struct TreeNode));
    left->val = val;
    right->val = val;
    left->left = root->left;
    left->right = NULL;
    right->right = root->right;
    right->left = NULL;
    root->left = left;
    root->right = right;
    return root;
  }
  if (root->left)
    addOneRow(root->left, val, depth - 1);
  if (root->right)
    addOneRow(root->right, val, depth - 1);
  return root;
}
