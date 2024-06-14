// 95. Unique Binary Search Trees II
#include "leetcode.h"

/*
 * given an integer 'n', return all the structurally unique BST's which has
 * exactly 'n' nodes of unique values from 1 to 'n'. return the answer in any
 * order.
 */

class Solution {
  vector<TreeNode *> build(int from, int to) {
    vector<TreeNode *> res;
    if (to - from < 0)
      res.push_back(0);
    if (to - from == 0)
      res.push_back(new TreeNode(from));
    if (to - from > 0)
      for (int i = 0; i <= to; i++) {
        vector<TreeNode *> left = build(from, i - 1);
        vector<TreeNode *> right = build(i + 1, to);
        for (int j = 0; j < left.size(); j++)
          for (int k = 0; k < right.size(); k++) {
            TreeNode *height = new TreeNode(i);
            height->left = left[j];
            height->right = right[k];
            res.push_back(height);
          }
      }
    return res;
  }

public:
  vector<TreeNode *> generateTrees(int n) { return build(1, n); }
};
