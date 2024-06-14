// 226. Invert Binary Tree
// given 'root' of binary tree, invert the tree and return its root
#include <stddef.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
  struct TreeNode *tmp;
  if (root == NULL)
    return NULL;
  tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}
