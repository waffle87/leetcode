// 1123. Lowest Common Ancestor of Deepest Leaves
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return the lowest common ancestor of its
 * deepest leaves. recall that the node of a binary tree is a leaf if and only
 * if it has no children, the depth of the root of the tree is 0. if the depth
 * of a node is 'd', the depth of each of its children is 'd + 1'. and the
 * lowest common ancestor of a set 's' is the node 'a' with the largest depth
 * such that every node in 's' is in the subtree with root 'a'.
 */

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  int l = depth(root->left);
  int r = depth(root->right);
  return l > r ? l + 1 : r + 1;
}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root) {
  if (!root)
    return NULL;
  int l = depth(root->left);
  int r = depth(root->right);
  if (l == r)
    return root;
  return l > r ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
}

int main() {
  int r1i[] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}, r2i[] = {1},
      r3i[] = {0, 1, 3, -1, 2};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  struct TreeNode *r3 = treenode_build(r3i, ARRAY_SIZE(r3i));
  struct TreeNode *lcadl1 = lcaDeepestLeaves(r1);
  struct TreeNode *lcadl2 = lcaDeepestLeaves(r2);
  struct TreeNode *lcadl3 = lcaDeepestLeaves(r3);
  treenode_print(lcadl1); // expect: 2 7 4
  printf("\n");
  treenode_print(lcadl2); // expect: 1
  printf("\n");
  treenode_print(lcadl3); // expect: 2
  printf("\n");
  treenode_free(r1);
  treenode_free(r2);
  treenode_free(r3);
}
