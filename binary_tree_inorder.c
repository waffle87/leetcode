// 94. Binary Tree Inorder Traversal
#include "leetcode.h"

/*
 * given the root of a binary tree, return the inorder traversal of its nodes
 * values
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void travel(struct TreeNode *root, int *res, int *size) {
  if (!root)
    return;
  travel(root->left, res, size);
  res[(*size)++] = root->val;
  travel(root->right, res, size);
}

int *inorderTraversal(struct TreeNode *root, int *return_size) {
  *return_size = 0;
  int *ans = malloc(sizeof(int) * 100);
  travel(root, ans, return_size);
  return ans;
}
