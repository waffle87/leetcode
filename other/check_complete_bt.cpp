// 958. Check Completeness of a Binary Tree
#include "leetcode.h"

/*
 * given 'root' of binary tree, determine if it is a complete binary tree. in a
 * completely filled binary tree, every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. it can have between 1 and 2^h nodes inclusive at the last level h.
 */

class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    vector<TreeNode *> bfs;
    bfs.push_back(root);
    int i = 0;
    while (i < bfs.size() && bfs[i]) {
      bfs.push_back(bfs[i]->left);
      bfs.push_back(bfs[i]->right);
      i++;
    }
    while (i < bfs.size() && !bfs[i])
      i++;
    return i == bfs.size();
  }
};
