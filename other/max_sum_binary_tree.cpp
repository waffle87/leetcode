// 1161. Maximum Level Sum of a Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on. return the smallest level 'x' such that the sum
 * of all the values of nodes at level 'x' is maximal.
 */

class Solution {
  vector<int> sums;
  void dfs(TreeNode *root, size_t level) {
    if (root) {
      sums.resize(max(sums.size(), level));
      sums[level - 1] += root->val;
      dfs(root->left, level + 1);
      dfs(root->right, level + 1);
    }
  }

public:
  int maxLevelSum(TreeNode *root) {
    dfs(root, 1);
    return distance(begin(sums), max_element(begin(sums), end(sums))) + 1;
  }
};
