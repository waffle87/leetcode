#include "leetcode.h"

class Solution {
public:
  vvd pathSum(TreeNode *root, int targetSum) {
    vvd ans;
    vector<int> d;
    dfs(root, targetSum, d, ans);
    return ans;
  }

private:
  void dfs(TreeNode *root, int targetSum, vector<int> d, vvd & ans) {
    if (root == NULL)
      return;
    d.push_back(root->val);
    targetSum -= root->val;
    if (targetSum == 0 && root->left == NULL && root->right == NULL) {
      ans.push_back(d);
      return;
    }
    dfs(root->left, targetSum, d, ans);
    dfs(root->right, targetSum, d, ans);
  }
};
