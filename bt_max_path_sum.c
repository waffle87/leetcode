// 124. Binary Tree Maximum Path Sum
#include "leetcode.h"

/*
 * a path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. a node can only appear in
 * the sequence at most once. note that the path does not need to pass through
 * the root. the path sum of a path is the sum of the node's value in the path.
 * given the 'root' of a binary tree, return the maximum path sum of any non
 * empty path
 */

int dfs(struct TreeNode *root, int *max) {
  if (!root)
    return 0;
  int left = dfs(root->left, max);
  int right = dfs(root->right, max);
  left = fmax(left, 0);
  right = fmax(right, 0);
  int curr = left + root->val + right;
  *max = fmax(*max, curr);
  return root->val + fmax(left, right);
}

int maxPathSum(struct TreeNode *root) {
  int ans = INT_MIN;
  dfs(root, &ans);
  return ans;
}

int main() {
  struct TreeNode *root = treenode_create(-10);
  root->left = treenode_create(9);
  root->right = treenode_create(20);
  root->right->left = treenode_create(15);
  root->right->right = treenode_create(7);
  printf("%d\n", maxPathSum(root)); // expect: 42
}
