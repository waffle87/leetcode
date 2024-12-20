// 2415. Reverse Odd Levels of Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a perfect binary tree, reverse the node values at each
 * odd level of the tree. return the root of the reversed tree. a binary tree is
 * perfect if all parent nodes have two children and all leaves are on the same
 * level. the level of a node is the number of edges along the path between it
 * and the root node.
 */

void dfs(struct TreeNode *node1, struct TreeNode *node2, int level) {
  if (!node1 || !node2)
    return;
  if (!(level % 2)) {
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
  }
  dfs(node1->left, node2->right, level + 1);
  dfs(node1->right, node2->left, level + 1);
}

struct TreeNode *reverseOddLevels(struct TreeNode *root) {
  dfs(root->left, root->right, 0);
  return root;
}

int main() {
  struct TreeNode *root = treenode_create(2);
  root->left = treenode_create(3);
  root->right = treenode_create(5);
  root->left->left = treenode_create(8);
  root->left->right = treenode_create(13);
  root->right->left = treenode_create(21);
  root->right->right = treenode_create(34);
  struct TreeNode *rol = reverseOddLevels(root);
  treenode_print(rol);
  treenode_free(root);
  treenode_free(rol);
}
