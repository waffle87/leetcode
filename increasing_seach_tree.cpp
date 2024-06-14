#include "leetcode.h"

class Solution {
public:
  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *temp;
    TreeNode *ans = new TreeNode();
    temp = ans;
    inOrder(ans, root);
    return temp->right;
  }

private:
  void inOrder(TreeNode *&ans, TreeNode *root) {
    if (!root)
      return;
    inOrder(ans, root->left);
    ans->right = new TreeNode(root->val);
    ans = ans->right;
    inOrder(ans, root->right);
  }
};

int main() {}
