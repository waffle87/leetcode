// 515. Find Largest Value in Each Tree Row
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return an array of the largest value in
 * each row of the tree (0-indexed)
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  else
    return 1 + fmax(depth(root->left), depth(root->right));
}

int *largestValues(struct TreeNode *root, int *return_size) {
  int dep = depth(root);
  if (!dep) {
    *return_size = 0;
    return 0;
  }
  int *ans = malloc(dep * sizeof(int));
  int ans_idx = 0, idx0 = 0, idx1 = 0;
  struct TreeNode **q0 = malloc(5000 * sizeof(struct TreeNode *));
  struct TreeNode **q1 = malloc(5000 * sizeof(struct TreeNode *));
  q0[idx0] = root;
  idx0 = 1;
  while (idx0 || idx1) {
    int max = INT_MIN;
    if (idx0) {
      for (int i = 0; i < idx0; i++) {
        if (q0[i]->val > max)
          max = q0[i]->val;
        if (q0[i]->left) {
          q1[idx1] = q0[i]->left;
          idx1++;
        }
        if (q0[i]->right) {
          q1[idx1] = q0[i]->right;
          idx1++;
        }
      }
      ans[ans_idx] = max;
      ans_idx++;
      idx0 = 0;
    } else {
      for (int i = 0; i < idx1; i++) {
        if (q1[i]->val > max)
          max = q1[i]->val;
        if (q1[i]->left) {
          q0[idx0] = q1[i]->left;
          idx0++;
        }
        if (q1[i]->right) {
          q0[idx0] = q1[i]->right;
          idx0++;
        }
      }
      ans[ans_idx] = max;
      ans_idx++;
      idx1 = 0;
    }
  }
  *return_size = ans_idx;
  return ans;
}
