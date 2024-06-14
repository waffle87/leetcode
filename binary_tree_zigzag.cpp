// 103. Binary Tree Zigzag Level Order Traversal
#include "leetcode.h"
// given the 'root' of a binary tree, return the zigzag level order traversal of
// its nodes' values (ie. from left to right, then right to left for the next
// level)

class Solution {
public:
  vvd(int) zigzagLevelOrder(TreeNode *root) {
    if (!root)
      return {};
    queue<TreeNode *> q;
    vvd(int) ans;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int sz = q.size();
      vector<int> curr(sz);
      for (int i = 0; i < sz; i++) {
        TreeNode *tmp = q.front();
        q.pop();
        if (level == 0)
          curr[i] = tmp->val;
        else
          curr[sz - i - 1] = tmp->val;
        if (tmp->left)
          q.push(tmp->left);
        if (tmp->right)
          q.push(tmp->right);
      }
      ans.push_back(curr);
      level = !level;
    }
    return ans;
  }
};
