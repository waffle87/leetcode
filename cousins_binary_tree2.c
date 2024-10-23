// 2641. Cousins in Binary Tree II
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, replace the value of each node in the tree
 * with the sum of all its cousins' values. two nodes of a binary tree are
 * cousins if they have the same depth with different paths. return 'root' of
 * the modified tree. note that the depth of a nodie is a number of edges in the
 * path from the root node to it.
 */

void dfs1(struct TreeNode *root, int *sum, int idx) {
  if (!root)
    return;
  sum[idx] += root->val;
  dfs1(root->left, sum, idx + 1);
  dfs1(root->right, sum, idx + 1);
}

int dfs2(struct TreeNode *root, int *sum, int idx) {
  if (!root)
    return 0;
  int l = dfs2(root->left, sum, idx + 1);
  int r = dfs2(root->right, sum, idx + 1);
  if (l && !r)
    root->left->val = sum[idx + 1] - l;
  if (!l && r)
    root->right->val = sum[idx + 1] - r;
  if (l && r) {
    root->left->val = sum[idx + 1] - r - l;
    root->right->val = sum[idx + 1] - r - l;
  }
  return root->val;
}

struct TreeNode *replaceValueInTree(struct TreeNode *root) {
  int *sum = (int *)calloc(100000, sizeof(int));
  dfs1(root, sum, 0);
  root->val -= dfs2(root, sum, 0);
  free(sum);
  return root;
}

int main() {
  struct TreeNode *r1 = treenode_create(5);
  r1->left = treenode_create(4);
  r1->right = treenode_create(9);
  r1->left->left = treenode_create(10);
  r1->left->right = treenode_create(10);
  r1->right->left = NULL;
  r1->right->right = treenode_create(7);
  struct TreeNode *r2 = treenode_create(3);
  r2->left = treenode_create(2);
  r2->right = treenode_create(1);
  struct TreeNode *rvit1 = replaceValueInTree(r1);
  struct TreeNode *rvit2 = replaceValueInTree(r2);
  treenode_print(rvit1); // expect : 0 0 0 7 7 null 11
  treenode_print(rvit2); // expect: 0 0 0
  treenode_free(r1), treenode_free(rvit1);
  treenode_free(r2), treenode_free(rvit2);
}
