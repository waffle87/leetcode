// 662. Maximum Width of Binary Tree
#include "leetcode.h"

/*
 * given 'root' of binary tree, return the maximum width of the
 * given tree. the maximum width of a tree is the maximum width
 * among all levels. the width of one level is defined as the
 * length between the end-nodes (the leftmost and rightmost non
 * null nodes), where the null nodes between the end-nodes that
 * would be present in a complete binary tree extending down to
 * that level are also counted into the length calculation.
 */

class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    if (root == NULL)
      return 0;
    int max_width = 1;
    queue<pair<TreeNode *, int>> qp;
    qp.push({root, 0});
    while (!qp.empty()) {
      int level_size = qp.size();
      int start_idx = qp.front().second;
      int end_idx = qp.back().second;
      max_width = max(max_width, end_idx - start_idx + 1);
      for (int i = 0; i < level_size; ++i) {
        auto node_idx_pair = qp.front();
        TreeNode *node = node_idx_pair.first;
        int node_idx = node_idx_pair.second - start_idx;
        qp.pop();
        if (node->left != nullptr)
          qp.push({node->left, 2LL * node_idx + 1});
        if (node->right != nullptr)
          qp.push({node->right, 2LL * node_idx + 2});
      }
    }
    return max_width;
  }
};
