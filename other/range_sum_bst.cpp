#include "leetcode.h"

class Solution {
public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    queue<TreeNode *> q;
    q.push(root);
    int sum = 0, v;
    while (q.size()) {
      root = q.front();
      q.pop();
      v = root->val;
      if (v >= low && v <= high)
        sum += v;
      if (v > low && root->left)
        q.push(root->left);
      if (v < high && root->right)
        q.push(root->right);
    }
    return sum;
  }
};
