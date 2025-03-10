#include "leetcode.h"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    frame ans;
    stack<frame> st;
    st.push({root, &ans});
    while (st.size()) {
      frame *top = &st.top(), *parent = top->parent;
      TreeNode *node = top->node;
      if (!node || node == p || node == q) {
        parent->subs.push_back(node);
        st.pop();
      } else if (top->subs.empty()) {
        st.push({node->right, top});
        st.push({node->left, top});
      } else {
        TreeNode *left = top->subs[0], *right = top->subs[1];
        parent->subs.push_back(!left ? right : !right ? left : node);
        st.pop();
      }
    }
    return ans.subs[0];
  }

private:
  struct frame {
    TreeNode *node;
    frame *parent;
    vector<TreeNode *> subs;
  };
};
