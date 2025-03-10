#include "leetcode.h"

class Solution {
public:
  int maxProduct(TreeNode *root) {
    tot = solve(root), solve(root);
    return ans % (1e9 + 7);
  }

private:
  long ans = 0, tot = 0, sub;
  int solve(TreeNode *root) {
    if (!root)
      return 0;
    sub = root->val + solve(root->left) + solve(root->right);
    ans = max(ans, sub * (tot - sub));
    return sub;
  }
};
