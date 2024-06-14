#include "leetcode.h"

class Solution {
public:
  vvd(int) pathSum(TreeNode *root, int targetSum) {
    vvd(int) ans;
    vector<int> d;
    dfs(root, targetSum, d, ans);
    return ans;
  }

private:
  void dfs(TreeNode *root, int targetSum, vector<int> d, vvd(int) & ans) {
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
