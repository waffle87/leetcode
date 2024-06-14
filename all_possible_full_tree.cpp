// 894. All Possible Full Binary Trees
#include "leetcode.h"

/*
 * given an integer 'n', return a list of all possible full binary trees with
 * 'n' nodes. each node of each tree in the answer must have 'node.val == 0'.
 * each element of the answer is the root node of one possible tree. you may
 * return the final list of trees in any order. a full binary tree is a binary
 * tree where each node has exactly zero or two children
 */

class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int n) {
    unordered_map<int, vector<TreeNode *>> memo;
    vector<TreeNode *> ans;
    if (n < 1 || !n % 2)
      return ans;
    if (memo.find(n) != memo.end())
      return memo[n];
    if (n == 1) {
      ans.push_back(new TreeNode(0));
      memo[1] = ans;
      return ans;
    }
    for (int i = 1; i < n; i += 2) {
      vector<TreeNode *> left = allPossibleFBT(i);
      vector<TreeNode *> right = allPossibleFBT(n - 1 - i);
      for (int j = 0; j < left.size(); j++)
        for (int k = 0; k < right.size(); k++) {
          TreeNode *root = new TreeNode(0);
          root->left = left[j];
          root->right = right[k];
          ans.push_back(root);
        }
    }
    memo[n] = ans;
    return ans;
  }
};
