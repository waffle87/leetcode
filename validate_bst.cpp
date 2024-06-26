#include "leetcode.h"

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    inOrder(root);
    for (int i = 1; i < tree.size(); i++)
      if (tree[i] <= tree[i - 1])
        return false;
    return true;
  }

private:
  vector<int> tree;
  void inOrder(TreeNode *root) {
    if (!root)
      return;
    inOrder(root->left);
    tree.push_back(root->val);
    inOrder(root->right);
  }
};
