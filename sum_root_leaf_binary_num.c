// 1022. Sum of Root To Leaf Binary Numbers
#include "leetcode.h"

/*
 * you are given the 'root' of a binary tree where each node has a value of 0
 * or 1. each root to leaf path represents a binary number starting with the
 * most significant bit. for all leaves in the tree, consider the numbers
 * represented by the path from the root to that leaf. return the  sum of these
 * numbers. the test cases are generated such that the answer fits in a 32-bit
 * integer.
 */

int dfs(struct TreeNode *root, int val) {
  if (!root)
    return 0;
  val = (val << 1) | root->val;
  int sum = dfs(root->left, val) + dfs(root->right, val);
  return (val & -!sum) | sum;
}

int sumRootToLeaf(struct TreeNode *root) { return dfs(root, 0); }

int main() {
  int r1i[] = {1, 0, 1, 0, 1, 0, 1}, r2i[] = {0};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  int srtl1 = sumRootToLeaf(r1);
  int srtl2 = sumRootToLeaf(r2);
  printf("%d\n", srtl1); // expect: 22
  assert(srtl1 == 22);
  printf("%d\n", srtl2); // expect: 0
  assert(srtl2 == 0);
  treenode_free(r1);
  treenode_free(r2);
}
