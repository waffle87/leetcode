#include "leetcode.h"

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL)
      return true;
    if (p == NULL || q == NULL)
      return false;
    if (p->val != q->val)
      return false;
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
  }
};
