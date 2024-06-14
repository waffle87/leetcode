#include "leetcode.h"

class Solution {
public:
  int deepestLeavesSum(TreeNode *root) {
    int ans = 0, i;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
      for (i = q.size() - 1, ans = 0; i >= 0; --i) {
        TreeNode *node = q.front();
        q.pop();
        ans += node->val;
        if (node->right)
          q.push(node->right);
        if (node->left)
          q.push(node->left);
      }
    }
    return ans;
  }
};

int main() {}
