// 543. Diameter of Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return the length of the diameter of the
 * tree. the diameter of a binary tree is the length of the longest path between
 * any two nodes in a tree. this path may or may not pass through the 'root'.
 * the length of a path between two nodes is represented by the number of edges
 * between them
 */

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
};

int between_diameter(struct TreeNode *root, int *diameter) {
  if (!root)
    return 0;
  int left_height = between_diameter(root->left, diameter);
  int right_height = between_diameter(root->right, diameter);
  int curr = left_height + right_height;
  *diameter = fmax(*diameter, curr);
  return fmax(left_height, right_height) + 1;
}

int diameterOfBinaryTree(struct TreeNode *root) {
  int diameter = 0;
  return between_diameter(root, &diameter);
}
