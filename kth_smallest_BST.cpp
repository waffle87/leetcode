#include "leetcode.h"

class Solution {
public:
  set<int> s;
  int kthSmallest(TreeNode *root, int k) {
    traverse(root);
    for (auto ans : s) {
      k--;
      if (!k)
        return ans;
    }
    return 0;
  }

private:
  void traverse(TreeNode *root) {
    if (!root)
      return;
    s.insert(root->val);
    traverse(root->left);
    traverse(root->right);
  }
};

int main() {}
