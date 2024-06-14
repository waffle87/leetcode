#include "leetcode.h"

class Solution {
public:
  int currSum;
  TreeNode *convertBST(TreeNode *root) {
    if (!root)
      return root;
    currSum = 0;
    traverse(root);
    return root;
  }

private:
  void traverse(TreeNode *node) {
    if (node->right)
      traverse(node->right);
    currSum += node->val;
    node->val = currSum;
    if (node->left)
      traverse(node->left);
  }
};

int main() {}
