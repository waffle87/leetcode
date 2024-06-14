// 530. Minimum Absolute Difference in BST
#include <limits.h>
#include <stdlib.h>

/*
 * given the 'root' of a binary search tree (bst), return the minimum absolute
 * difference between the values of any two different nodes in the tree
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

inline int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

void process(struct TreeNode *root, int *val) {
  struct TreeNode *tmp;
  if (root->left) {
    tmp = root->left;
    while (tmp->right)
      tmp = tmp->right;
    *val = min(*val, root->val - tmp->val);
    if (*val == 1)
      return;
    process(root->left, val);
  }
  if (root->right) {
    tmp = root->right;
    while (tmp->left)
      tmp = tmp->left;
    *val = min(*val, tmp->val - root->val);
    if (*val == 1)
      return;
    process(root->right, val);
  }
}

int getMinimumDifference(struct TreeNode *root) {
  int *val = malloc(sizeof(int));
  *val = INT_MAX;
  process(root, val);
  int ans = *val;
  free(val);
  return ans;
}
