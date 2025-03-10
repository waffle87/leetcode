// 1372. Longest ZigZag Path in a Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree. a zigzag path for a binary tree is defined
 * as follows
 * - choose any node in the binary tree and a direction (left or right)
 * - if the current direction is right, move to the right child of the current
 * node
 * - change the direction from right to left or from left to right
 * - repeat the second nd third steps until you cannot move in the tree
 * zigzag length is defined as the number of nodes visited - 1. return longest
 * zigzag
 */

class Solution {
  int ans = 0;
  map<pair<TreeNode *, bool>, int> mp;
  int find(TreeNode *root, bool check) {
    if (mp.find({root, check}) != mp.end())
      return mp[{root, check}];
    if (check) {
      if (root->right)
        return mp[{root, check}] = 1 + find(root->right, !check);
      else if (root->left)
        return mp[{root, check}] = 1 + find(root->left, !check);
    }
    return mp[{root, check}] = 1;
  }
  void preorder(TreeNode *root) {
    if (root) {
      if (root->left)
        ans = max(ans, find(root->left, true));
      if (root->right)
        ans = max(ans, find(root->right, false));
      preorder(root->left);
      preorder(root->right);
    }
  }

public:
  int longestZigZag(TreeNode *root) {
    preorder(root);
    return ans;
  }
};
