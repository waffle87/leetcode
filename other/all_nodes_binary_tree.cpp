// 863. All Nodes Distance K in Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, the value of a target node 'target', and
 * an integer 'k', return an array of the values of all nodes that have a
 * distance 'k' from the target node. you can return the answer in any order.
 */

class Solution {
  void dfs(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &back_edge,
           TreeNode *target) {
    if (!root || root == target)
      return;
    if (root->left) {
      back_edge[root->left] = root;
      dfs(root->left, back_edge, target);
    }
    if (root->right) {
      back_edge[root->right] = root;
      dfs(root->right, back_edge, target);
    }
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, TreeNode *> back_edge;
    unordered_set<TreeNode *> visited;
    vector<int> ans;
    dfs(root, back_edge, target);
    queue<TreeNode *> q;
    q.push(target);
    while (!q.empty() && k >= 0) {
      int s = q.size();
      while (s--) {
        TreeNode *curr = q.front();
        int val = curr->val;
        q.pop();
        visited.insert(curr);
        if (!k)
          ans.push_back(val);
        if (!visited.count(back_edge[curr]) && back_edge[curr])
          q.push(back_edge[curr]);
        if (!visited.count(curr->left) && curr->left)
          q.push(curr->left);
        if (!visited.count(curr->right) && curr->right)
          q.push(curr->right);
      }
      k--;
    }
    return ans;
  }
};
