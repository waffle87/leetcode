#include "leetcode.h"

class Solution {
public:
  int diff = INT_MIN;
  int maxAncestorDiff(TreeNode *root) {
    if (!root)
      return 0;
    int mx = INT_MIN, mn = INT_MAX;
    getMax(root, mx, mn);
    return diff;
  }

private:
  int getMax(TreeNode *root, int mx, int mn) {
    mx = max(mx, root->val);
    mn = min(mn, root->val);
    diff = max(diff, mx - mn);
    getMax(root->left, mx, mn);
    getMax(root->right, mx, mn);
  }
};
