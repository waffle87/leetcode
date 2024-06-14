#include "leetcode.h"

class Solution {
public:
  int sum;
  int maxPathSum(TreeNode *root) {
    sum = INT_MIN;
    solve(root);
    return sum;
  }

private:
  int solve(TreeNode *root) {
    if (!root)
      return 0;
    int left = max(0, solve(root->left));
    int right = max(0, solve(root->right));
    sum = max(sum, left + right + root->val);
    return max(left, right) + root->val;
  }
};
