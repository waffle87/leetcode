#include "leetcode.h"

class Solution {
public:
  int ans;
  int minCameraCover(TreeNode *root) {
    if (helper(root) == 0)
      ans++;
    return ans;
  }

private:
  int helper(TreeNode *root) {
    if (!root)
      return 1;
    int l = helper(root->left);
    int r = helper(root->right);
    if (l == 0 || r == 0) {
      ans++;
      return 2;
    } else if (l == 2 || r == 2)
      return 1;
    else
      return 0;
  }
};

int main() {}
