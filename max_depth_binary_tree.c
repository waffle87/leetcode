/* 104. Maximum Depth of Binary Tree
 * given the 'root' of a binary tree, return its maximum depth. a binary tree's
 * max depth is the number of nodes along the longest path from the root node
 * down to the farthest leaf node.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxDepth(struct TreeNode *root) {
  if (!root)
    return 0;
  int max_left = maxDepth(root->left);
  int max_rght = maxDepth(root->right);
  if (max_left > max_rght)
    return max_left + 1;
  else
    return max_rght + 1;
}
