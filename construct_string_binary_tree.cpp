#include "leetcode.h"

class Solution {
public:
  string tree2str(TreeNode *root) {
    if (!root)
      return "";
    string ans = to_string(root->val);
    if (root->left || root->right) {
      ans.push_back('(');
      ans += tree2str(root->left);
      ans.push_back(')');
    }
    if (root->right) {
      ans.push_back('(');
      ans += tree2str(root->right);
      ans.push_back(')');
    }
    return ans;
  }
};
