#include "leetcode.h"

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == NULL)
      return false;
    stack<pair<TreeNode *, int>> s;
    s.push({root, root->val});
    while (!s.empty()) {
      TreeNode *curr = s.top().first;
      int total = s.top().second;
      s.pop();
      if (curr->right)
        s.push({curr->right, total + curr->right->val});
      if (curr->left)
        s.push({curr->left, total + curr->left->val});
      if (!curr->right && !curr->left && total == targetSum)
        return true;
    }
    return false;
  }
};
