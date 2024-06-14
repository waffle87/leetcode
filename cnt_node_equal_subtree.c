// 2265. Count Nodes Equal to Average of Subtree
#include "leetcode.h"

/*
 * given the root of a binary tree, return the number of nodes where the value
 * of the node is equal to the average of the values in its subtree. note, the
 * average of 'n' elements is the sum of the n elements divided by n and rounded
 * down to the nearest integer. also, a subtree of root is a tree consisting of
 * root and all of its descendants
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int cnt_subtree(struct TreeNode *root, int *res) {
  if (!root)
    return 0;
  int left = cnt_subtree(root->left, res);
  int rght = cnt_subtree(root->right, res);
  int curr_cnt = left + rght + 1, curr_sum = root->val;
  curr_sum += (root->left) ? root->left->val : 0;
  curr_sum += (root->right) ? root->right->val : 0;
  if (root->val == (curr_sum / curr_cnt))
    (*res)++;
  root->val = curr_sum;
  return curr_cnt;
}

int averageOfSubtree(struct TreeNode *root) {
  int ans = 0;
  cnt_subtree(root, &ans);
  return ans;
}
