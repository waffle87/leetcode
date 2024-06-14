#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/* 783. Minimum Distance Between BST Nodes
 * given the 'root' of BST, return the minimum difference between the values
 * of any two different nodes in the tree!
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void tree2array(struct TreeNode *root, int *data, int *idx) {
  if (root == NULL)
    return;
  tree2array(root->left, data, idx);
  data[*idx] = root->val;
  *idx = *idx + 1;
  tree2array(root->right, data, idx);
}

int minDiffInBST(struct TreeNode *root) {
  int *data = malloc(100 * sizeof(int));
  int *idx = calloc(1, sizeof(int));
  tree2array(root, data, idx);
  int min = INT_MAX;
  for (int i = 1; i < (*idx); i++)
    if ((data[i] - data[i - 1]) < min)
      min = data[i] - data[i - 1];
  free(data);
  free(idx);
  return min;
}
