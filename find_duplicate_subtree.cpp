// 652. Find Duplicate Subtrees
#include "leetcode.h"

/*
 * given 'root' of a binary tree, return all duplicate subtrees. for each kind
 * of duplicate, only return the root node of any one of them. two trees are
 * duplicate if they have the same structure with the same node values.
 */

class Solution {
public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, vector<TreeNode *>> map;
    vector<TreeNode *> dups;
    serialise(root, map);
    for (auto it = map.begin(); it != map.end(); it++)
      if (it->second.size() > 1)
        dups.push_back(it->second[0]);
    return dups;
  }

private:
  string serialise(TreeNode *node,
                   unordered_map<string, vector<TreeNode *>> &map) {
    string s = "(" + serialise(node->left, map) + to_string(node->val) +
               serialise(node->right, map) + ")";
    map[s].push_back(node);
    return s;
  }
};
