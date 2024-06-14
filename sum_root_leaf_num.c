// 129. Sum Root to Leaf Numbers
#include "leetcode.h"

/*
 * given 'root' of binary tree containing digits 0-9 only. each root-to-leaf
 * pattern in the tree represents a number. eg. root-to-leaf path 1->2->3
 * represents the integer 123. return total sum of all root-to-leaf numbers.
 * test cases will fit in 32-bit integer. a leaf node is a node with no children
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

int calc_num(struct TreeNode *root, int tree_num) {
  if (!root)
    return 0;
  return !root->left && !root->right
             ? tree_num * 10 + root->val
             : calc_num(root->left, tree_num * 10 + root->val) +
                   calc_num(root->right, tree_num * 10 + root->val);
}

int sumNumbers(struct TreeNode *root) { return calc_num(root, 0); }

int main() {
  struct TreeNode *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  printf("%d\n", sumNumbers(root)); // expect: 25
}
