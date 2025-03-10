#include "leetcode.h"

class Solution {
public:
  int goodNodes(TreeNode *root) {
    dfs(root, root->val);
    return count;
  }

private:
  int count = 0;
  void dfs(TreeNode *node, int currMax) {
    if (!node)
      return;
    if (node->val >= currMax) {
      count++;
      currMax = node->val;
    }
    dfs(node->left, currMax);
    dfs(node->right, currMax);
  }
};
