#include "leetcode.h"

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
      m[inorder[i]] = i;
    return splitTree(preorder, m, 0, 0, inorder.size() - 1);
  }

private:
  TreeNode *splitTree(vector<int> &preorder, unordered_map<int, int> &m,
                      int pix, int iLeft, int iRight) {
    int rVal = preorder[pix], iMid = m[rVal];
    TreeNode *root = new TreeNode(rVal);
    if (iMid > iLeft)
      root->left = splitTree(preorder, m, pix + 1, iLeft, iMid - 1);
    if (iMid < iRight)
      root->right =
          splitTree(preorder, m, pix + iMid - iLeft + 1, iMid + 1, iRight);
    return root;
  }
};
