// 106. Construct Binary Tree from Inorder and Postorder Traversal
#include "leetcode.h"

/*
 * given two integer arrays 'inorder' and 'postorder', where 'inorder' is the
 * inorder traversal of a binary tree, and 'postorder' is the postorder
 * traversal of the same tree, construct and return the binary tree.
 */

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size(), po_idx = n - 1;
    for (int i = 0; i < n; i++)
      um[inorder[i]] = i;
    return construct(inorder, postorder, 0, n - 1, po_idx);
  }

private:
  unordered_map<int, int> um;
  TreeNode *construct(vector<int> &inorder, vector<int> &postorder,
                      int io_start, int io_end, int po_idx) {
    if (io_start > io_end)
      return nullptr;
    TreeNode *root = new TreeNode(postorder[po_idx--]);
    int io_idx = um[root->val];
    root->right = construct(inorder, postorder, io_idx + 1, io_end, po_idx);
    root->left = construct(inorder, postorder, io_start, io_idx - 1, po_idx);
    return root;
  }
};
