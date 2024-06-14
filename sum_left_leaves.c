// 404. Sum of Left Leaves
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return the sum of all left leaves. a leaf
 * is a node with no childen. a leaft leaf is a leaf that is the left child of
 * another node.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *createNode(int val) {
  struct TreeNode *new_node =
      (struct TreeNode *)malloc(sizeof(struct TreeNode));
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void dfs(struct TreeNode *node, int *sum, bool left) {
  if (!node)
    return;
  if (!node->left && !node->right && left) {
    (*sum) += node->val;
    return;
  }
  dfs(node->left, sum, 1);
  dfs(node->right, sum, 0);
}

int sumOfLeftLeaves(struct TreeNode *root) {
  int sum = 0;
  dfs(root, &sum, 0);
  return sum;
}

int main() {
  struct TreeNode *root = createNode(3);
  root->left = createNode(9);
  root->right = createNode(20);
  root->right->left = createNode(15);
  root->right->right = createNode(7);
  printf("%d\n", sumOfLeftLeaves(root)); // expect: 24
  free(root);
}
