// 2331. Evaluate Boolean Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a full binary tree with the following properties. leaf
 * nodes have either the value 0 or 1, where 0 represents false and 1 represents
 * true. non leaf nodes have either the value 2 or 3, where 2 represents the
 * boolean or, and 3 represents the boolean and. the evaluation of a node is as
 * follows. if the node is a leaf node, the evaluation is the value of the node,
 * ie. true or false. otherwise, evaluate the node's two children and apply the
 * boolean operation of its value with the children's evaluations. return the
 * boolean result of evaulating the 'root' node. a full binary tree is a binary
 * tree where each node has either 0 or 2 children. a leaf node is a node that
 * has zero children.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool evaluateTree(struct TreeNode *root) {
  if (!root)
    return true;
  bool l = evaluateTree(root->left), r = evaluateTree(root->right);
  switch (root->val) {
  case 2:
    root->val = l || r;
    return l || r;
  case 3:
    root->val = l && r;
    return l && r;
  case 0:
    return false;
  default:
    return true;
  }
}
