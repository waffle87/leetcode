// 1372. Longest ZigZag Path in a Binary Tree
#include <math.h>
#include <stdlib.h>

/*
 * given the 'root' of a binary tree. a zigzag path for a binary tree is defined
 * as follows
 * - choose any node in the binary tree and a direction (left or right)
 * - if the current direction is right, move to the right child of the current
 * node
 * - change the direction from right to left or from left to right
 * - repeat the second nd third steps until you cannot move in the tree
 * zigzag length is defined as the number of nodes visited - 1. return longest
 * zigzag
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct {
  int left;
  int right;
} data;

data process(struct TreeNode *root, int *max) {
  data res;
  if (!root) {
    res.left = -1;
    res.right = -1;
    return res;
  }
  data l_tree = process(root->left, max);
  data r_tree = process(root->right, max);
  res.left = 1 + r_tree.right;
  res.right = 1 + l_tree.left;
  *max = fmax(fmax(res.left, *max), res.right);
  return res;
}

int longestZigZag(struct TreeNode *root) {
  int max = 0;
  process(root, &max);
  return max;
}
