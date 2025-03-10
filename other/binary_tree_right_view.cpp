#include "leetcode.h"

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> q;
    vector<int> ans;
    if (!root)
      return ans;
    q.push(root);
    while (!q.empty()) {
      ans.push_back(q.back()->val);
      for (int i = q.size(); i > 0; i--) {
        TreeNode *n = q.front();
        q.pop();
        if (n->left)
          q.push(n->left);
        if (n->right)
          q.push(n->right);
      }
    }
    return ans;
  }
};
