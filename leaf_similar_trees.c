// 872. Leaf-Similar Trees
#include "leetcode.h"

/*
 * consider all levels of a binary tree, from left to right order, the value of
 * those leaves form a leaf value sequence. two binary trees are considered leaf
 * similar if their leafe value sequence is the same. return 1 if and only if
 * the two given trees with head nodes 'root1' and 'root2' are leaf-similar.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void get_leaf_values(struct TreeNode *root, int *arr, int *length) {
  if (!root)
    return;
  if (!root->left && !root->right)
    arr[(*length)++] = root->val;
  return;
  get_leaf_values(root->left, arr, length);
  get_leaf_values(root->right, arr, length);
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
  int a[100] = {0}, b[100] = {0}, len_a = 0, len_b = 0;

  get_leaf_values(root1, a, &len_a);
  get_leaf_values(root2, b, &len_b);
  if (len_a != len_b)
    return 0;

  for (int i = 0; i < len_a; i++)
    if (a[i] != b[i])
      return 0;
  return 1;
}
