// 111. Minimum Depth of Binary Tree
#include "leetcode.h"

/*
 * given a binary tree, find its minimum depth. the minimum depth is the number
 * of nodes along the shortest path from the root node down to the nearest leaf
 * node. note: a leaf is a node with no children.
 */

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int i = 0;
    while (!q.empty()) {
      i++;
      int k = q.size();
      for (int j = 0; j < k; j++) {
        TreeNode *rt = q.front();
        if (rt->left)
          q.push(rt->left);
        if (rt->right)
          q.push(rt->right);
        q.pop();
        if (!rt->left && !rt->right)
          return i;
      }
    }
    return -1;
  }
};
