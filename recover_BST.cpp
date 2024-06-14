#include "leetcode.h"

class Solution {
public:
  vector<pair<TreeNode *, TreeNode *>> vec;
  void recoverTree(TreeNode *root) {
    inOrder(root);
    if (vec.size() == 1)
      swap(vec[0].first->val, vec[0].second->val);
    if (vec.size() == 2)
      swap(vec[0].first->val, vec[1].second->val);
  }

private:
  TreeNode *prev = NULL;
  void inOrder(TreeNode *root) {
    if (!root)
      return;
    inOrder(root->left);
    if (prev && prev->val > root->val)
      vec.push_back({prev, root});
    prev = root;
    inOrder(root->right);
  }
};

int main() {}
