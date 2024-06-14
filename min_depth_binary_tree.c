// 111. Minimum Depth of Binary Tree

/*
 * given a binary tree, find its minimum depth. the minimum depth is the number
 * of nodes along the shortest path from the root node down to the nearest leaf
 * node. note: a leaf is a node with no children.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int minDepth(struct TreeNode *root) {
  if (!root)
    return 0;
  int l = minDepth(root->left);
  int r = minDepth(root->right);
  if (!l || !r)
    return l + r + 1;
  return 1 + (l > r ? r : l);
}
