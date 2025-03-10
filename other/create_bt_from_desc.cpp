// 2196. Create Binary Tree From Descriptions
#include "leetcode.h"

/*
 * you are given a 2d integer array 'descriptions' where 'descriptions[i] =
 * [parent_i, child_i, isleft_i]' indicates that 'parent_i' is the parent of
 * 'child_i', in a binary tree of unique values. construct the binary tree
 * described by 'descriptions' and return its root. the test cases will be
 * generated such that the binary tree is valid.
 */

class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> get_node;
    unordered_map<int, bool> is_child;
    for (auto &i : descriptions) {
      if (!get_node.count(i[0])) {
        TreeNode *par = new TreeNode(i[0]);
        get_node[i[0]] = par;
      }
      if (!get_node.count(i[1])) {
        TreeNode *child = new TreeNode(i[1]);
        get_node[i[1]] = child;
      }
      if (i[2] == 1)
        get_node[i[0]]->left = get_node[i[1]];
      else
        get_node[i[0]]->right = get_node[i[1]];
      is_child[i[1]] = true;
    }
    TreeNode *ans = NULL;
    for (auto &i : descriptions)
      if (!is_child[i[0]]) {
        ans = get_node[i[0]];
        break;
      }
    return ans;
  }
};
