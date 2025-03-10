#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> curr;
    while (!q.empty()) {
      TreeNode *t = q.front();
      q.pop();
      if (t == NULL) {
        ans.push_back(curr);
        curr.resize(0);
        if (q.size() > 0)
          q.push(NULL);
      } else {
        curr.push_back(t->val);
        if (t->left)
          q.push(t->left);
        if (t->right)
          q.push(t->right);
      }
    }
    return ans;
  }
};
