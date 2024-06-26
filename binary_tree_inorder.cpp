#include "leetcode.h"

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }
      curr = s.top();
      s.pop();
      ans.push_back(curr->val);
      curr = curr->right;
    }
    return ans;
  }
};

int main() { Solution obj; }
