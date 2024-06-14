// 979. Distribute Coins in Binay Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree with 'n' nodes where each 'node' is the
 * tree that has 'node.val' coins. there are 'n' coins in total throughout the
 * whole tree. in one move, we may choose two adjacent nodes and move one coin
 * from one node to another. a move may be from parent to child, or from child
 * to parent. return the minimum number of moves required to make every node
 * have exactly one coin.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int dfs(struct TreeNode *root, int steps) {
  if (!root)
    return 0;
  int val = root->val + dfs(root->left, steps) + dfs(root->right, steps);
  steps += abs(val - 1);
  return val - 1;
}

int distributeCoins(struct TreeNode *root) {
  int steps = 0, tmp = dfs(root, steps);
  return steps;
}
