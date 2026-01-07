// 1339. Maximum Product of Splitted Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, split the binary tree into two subtrees by
 * removing one edge such that the product of the sums of the subtrees is
 * maximised. return the maximum product of the sums of the two subtrees. since
 * the answer may be too large, return it modulo 10^9+7. note that you need to
 * maximise the answer before taking the mod, and not after.
 */

static long long total, best;

long long sum(struct TreeNode *node) {
  if (!node)
    return 0;
  return node->val + sum(node->left) + sum(node->right);
}

long long dfs(struct TreeNode *node) {
  if (!node)
    return 0;
  long long s = node->val + dfs(node->left) + dfs(node->right);
  long long p = s * (total - s);
  best = fmax(best, p);
  return s;
}

int maxProduct(struct TreeNode *root) {
  total = sum(root);
  best = 0;
  dfs(root);
  return best % (long long)(1e9 + 7);
}

int main() {
  int r1i[] = {1, 2, 3, 4, 5, 6}, r2i[] = {1, -1, 2, 3, 4, -1, -1, 5, 6};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  printf("%d\n", maxProduct(r1)); // expect: 110
  printf("%d\n", maxProduct(r2)); // expect: 90
  treenode_free(r1);
  treenode_free(r2);
}
