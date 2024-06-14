#include "leetcode.h"

class Solution {
public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth-- == 1)
      return new TreeNode(val, root, nullptr);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      bool addLevel = depth-- == 1;
      size_t sz = q.size();
      for (size_t _ = 0; _ < sz; _++) {
        TreeNode *curr = q.front();
        q.pop();
        if (addLevel) {
          curr->left = new TreeNode(val, curr->left, nullptr);
          curr->right = new TreeNode(val, nullptr, curr->right);
          continue;
        }
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
    }
    return root;
  }
};
