// 124. Binary Tree Maximum Path Sum
#include "leetcode.h"

/*
 * a path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. a node can only appear in
 * the sequence at most once. note that the path does not need to pass through
 * the root. the path sum of a path is the sum of the node's value in the path.
 * given the 'root' of a binary tree, return the maximum path sum of any non
 * empty path
 */

class Solution {
public:
  int sum;
  int maxPathSum(TreeNode *root) {
    sum = INT_MIN;
    solve(root);
    return sum;
  }

private:
  int solve(TreeNode *root) {
    if (!root)
      return 0;
    int left = max(0, solve(root->left));
    int right = max(0, solve(root->right));
    sum = max(sum, left + right + root->val);
    return max(left, right) + root->val;
  }
};
