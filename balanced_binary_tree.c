// 110. Balanced Binary Tree
#include "leetcode.h"

// given a binary tree, determine if it is height balanced

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  return fmax(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(struct TreeNode *root) {
  if (!root)
    return true;
  return isBalanced(root->left) && isBalanced(root->right) &&
         !(abs(depth(root->left) - depth(root->right)) > 1);
}

int main() {
  int r1i[] = {3, 9, 20, -1, -1, 15, 7}, r2i[] = {1, 2, 2, 3, 3, -1, -1, 4, 4};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  printf("%d\n", isBalanced(r1)); // expect: 1
  printf("%d\n", isBalanced(r2)); // expect: 0
  treenode_free(r1);
  treenode_free(r2);
}
