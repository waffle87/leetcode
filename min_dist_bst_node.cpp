// 783. Minimum Distance Between BST Nodes
#include "leetcode.h"

// given the 'root' of BST, return the minimum difference between the values
// of any two different nodes in the tree!

class Solution {
public:
  int ans = INT_MAX, pre = -1;
  int minDiffInBST(TreeNode *root) {
    if (root->left != NULL)
      minDiffInBST(root->left);
    if (pre >= 0)
      ans = min(ans, root->val - pre);
    pre = root->val;
    if (root->right != NULL)
      minDiffInBST(root->right);
    return ans;
  }
};
