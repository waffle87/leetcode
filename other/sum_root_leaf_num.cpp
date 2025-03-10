// 129. Sum Root to Leaf Numbers
#include "leetcode.h"

/*
 * given 'root' of binary tree containing digits 0-9 only. each root-to-leaf
 * pattern in the tree represents a number. eg. root-to-leaf path 1->2->3
 * represents the integer 123. return total sum of all root-to-leaf numbers.
 * test cases will fit in 32-bit integer. a leaf node is a node with no children
 */

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    int sum = 0, curr = 0, depth = 0;
    while (root) {
      if (root->left) {
        auto pre = root->left;
        depth = 1;
        while (pre->right && pre->right != root) {
          pre = pre->right;
          depth++;
        }
        if (!pre->right) {
          pre->right = root;
          curr = curr * 10 + root->val;
          root = root->left;
        } else {
          pre->right = nullptr;
          if (!pre->left)
            sum += curr;
          curr /= pow(10, depth);
        }
      } else {
        curr = curr * 10 + root->val;
        if (!root->right)
          sum += curr;
        root = root->right;
      }
    }
    return sum;
  }
};
