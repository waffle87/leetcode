// 606. Construct String from Binary Tree
#include "leetcode.h"

/*
 * given the root of a binary tree, construct a string consisting of parenthesis
 * and integers from a binary tree with the preorder traversal way, and return
 * it. omit all the empty parenthesis pairs that do not affect the one-to-one
 * mapping relationship between the string and the original binary tree
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void helper(struct TreeNode *t, char *ans, int *count) {
  if (!t)
    return;
  *count += sprintf(&ans[*count], "%d", t->val);
  if (!(t->left) && !(t->right))
    return;
  else {
    *count += sprintf(&ans[*count], "(");
    helper(t->left, ans, count);
    *count += sprintf(&ans[*count], ")");
    if (t->right != NULL) {
      *count += sprintf(&ans[*count], "(");
      helper(t->right, ans, count);
      *count += sprintf(&ans[*count], ")");
    }
    return;
  }
}

char *tree2str(struct TreeNode *t) {
  char *ans = calloc(30000, sizeof(char));
  int count = 0;
  helper(t, ans, &count);
  ans[count] = '\0';
  return ans;
}
