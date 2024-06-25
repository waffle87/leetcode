// 1038. Binary Search Tree to Greater Sum Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary search tree, convert it to a greater tree such
 * that every key o the original bst is changed to the original key plus the sum
 * of all keys greater than the original key in bst. as a reminder, a binary
 * search tree is a tree that satisfies the following constraints. the left
 * subtree of a node contains only nodes with keys less than the node's key. the
 * right subtree of a node contains only nodes with keys greater than the node's
 * key. both the left and right subtrees also be binary search trees.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *dfs(struct TreeNode *root) {
  int accum = 0;
  if (!root)
    return NULL;
  else {
    dfs(root->right);
    accum += root->val;
    root->val = accum;
    dfs(root->left);
    return root;
  }
}

struct TreeNode *bstToGst(struct TreeNode *root) { return dfs(root); }
