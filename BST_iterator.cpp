#include "leetcode.h"

class BSTIterator {
public:
  stack<TreeNode *> s;
  BSTIterator(TreeNode *root) { partialOrder(root); }
  int next() {
    TreeNode *top = s.top();
    s.pop();
    partialOrder(top->right);
    return top->val;
  }
  bool hasNext() { return !s.empty(); }
  void partialOrder(TreeNode *root) {
    while (root != NULL) {
      s.push(root);
      root = root->left;
    }
  }
};

int main() {}
