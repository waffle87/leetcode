// 100. Same Tree
#include "leetcode.h"

/*
 * given the roots of two binary trees 'p' and 'q', write a function to check if
 * they are the same or not. two binary trees are considered the same if they
 * are structurally identical, and the nodes have the same value.
 */

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if (!p && !q)
    return 1;
  else if (!p || !q)
    return 0;
  return p->val == q->val
             ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right)
             : 0;
}
