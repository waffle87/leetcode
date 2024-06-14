// 106. Construct Binary Tree from Inorder and Postorder Traversal
#include <stdint.h>
#include <stdlib.h>

/*
 * given two integer arrays 'inorder' and 'postorder', where 'inorder' is the
 * inorder traversal of a binary tree, and 'postorder' is the postorder
 * traversal of the same tree, construct and return the binary tree.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *buildTree(int *inorder, int inorder_size, int *postorder,
                           int postorder_size) {
  if (inorder_size == 0)
    return NULL;
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->val = postorder[postorder_size - 1];
  root->left = NULL;
  root->right = NULL;
  if (postorder_size == 1)
    return root;
  uint16_t i;
  for (i = 0; i < inorder_size; i++)
    if (inorder[i] == root->val)
      break;
  int l_size = i;
  root->left = buildTree(inorder, l_size, postorder, l_size);
  int r_size = postorder_size - 1 - l_size;
  root->right =
      buildTree(&inorder[1 + l_size], r_size, &postorder[l_size], r_size);
  return root;
}
