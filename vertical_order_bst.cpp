#include "leetcode.h"

class Solution {
public:
  vvd(int) verticalTraversal(TreeNode *root) {
    map<int, map<int, multiset<int>>> mmm;
    queue<pair<TreeNode *, pair<int, int>>> qpp;
    qpp.push({root, {0, 0}});
    while (!qpp.empty()) {
      auto p = qpp.front();
      qpp.pop();
      TreeNode *node = p.first;
      int x = p.second.first, y = p.second.second;
      mmm[x][y].insert(node->val);
      if (node->left)
        qpp.push({node->left, {x - 1, y + 1}});
      if (node->right)
        qpp.push({node->right, {x + 1, y + 1}});
    }
    vvd(int) ans;
    for (auto q : mmm) {
      vector<int> col;
      for (auto p : q.second)
        col.insert(col.end(), p.second.begin(), p.second.end());
      ans.push_back(col);
    }
    return ans;
  }
};
