#include "leetcode.h"

class Solution {
public:
  int pseudoPalindromicPaths(TreeNode *root) {
    vector<int> v(10, 0);
    dfs(root, v);
    return count;
  }

private:
  int count = 0;
  void dfs(TreeNode *root, vector<int> v) {
    if (root == NULL)
      return;
    v[root->val]++;
    if (root->left == NULL && root->right == NULL) {
      int oddCount = 0;
      for (auto x : v)
        if (x % 2)
          oddCount++;
      if (oddCount <= 1)
        count++;
      return;
    }
    dfs(root->left, v);
    dfs(root->right, v);
  }
};
