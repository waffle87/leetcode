// 1609. Even Odd Tree
#include "leetcode.h"

/*
 * a binary tree is even-odd if it meets the following conditions. the root of
 * the binary tree is at level index 0 it s children are at level index 1 and
 * their children are at level index 2, etc. for every even indexed level, all
 * nodes at the level have odd integer values in strictly ordere (from left to
 * right). for every odd-indexed level, all nodes at the level have even integer
 * values in strictly decreasing order (from left to right). given 'root' of a
 * binary tree, return true if the binary tree is even-odd, otherwise return
 * false.
 */

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
};

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  else
    return 1 + fmax(depth(root->left), depth(root->right));
}

bool isEvenOddTree(struct TreeNode *root) {
  int d = depth(root);
  struct TreeNode **q0 = malloc(50000 * sizeof(struct TreeNode *));
  struct TreeNode **q1 = malloc(50000 * sizeof(struct TreeNode *));
  int idx0 = 0, idx1 = 0;
  q0[idx0] = root;
  idx0 = 1;
  while (idx0 || idx1) {
    if (idx0) {
      for (int i = 0; i < idx0; i++) {
        if (!i) {
          if (!(q0[i]->val % 2))
            return 0;
        } else {
          if (!(q0[i]->val % 2) || q0[i]->val <= q0[i - 1]->val)
            return 0;
        }
        if (q0[i]->left) {
          q1[idx1] = q0[i]->left;
          idx1++;
        }
        if (q0[i]->right) {
          q1[idx1] = q0[i]->right;
          idx1++;
        }
      }
      idx0 = 0;
    } else {
      for (int i = 0; i < idx1; i++) {
        if (!i) {
          if (q1[i]->val % 2 == 1)
            return 0;
        } else {
          if (q1[i]->val % 2 == 1 || q1[i]->val >= q1[i - 1]->val)
            return 0;
        }
        if (q1[i]->left) {
          q0[idx0] = q1[i]->left;
          idx0++;
        }
        if (q1[i]->right) {
          q0[idx0] = q1[i]->right;
          idx0++;
        }
      }
      idx1 = 0;
    }
  }
  return 1;
}
