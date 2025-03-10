#include "leetcode.h"

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      double tmp = q.size(), sum = 0;
      for (int i = 0; i < tmp; i++) {
        auto tt = q.front();
        q.pop();
        sum += (tt->val);
        if (tt->left)
          q.push(tt->left);
        if (tt->right)
          q.push(tt->right);
      }
      ans.push_back(sum / tmp);
    }
    return ans;
  }
};
