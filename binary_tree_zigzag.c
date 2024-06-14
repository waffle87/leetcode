// 103. Binary Tree Zigzag Level Order Traversal
// given the 'root' of a binary tree, return the zigzag level order traversal of
// its nodes' values (ie. from left to right, then right to left for the next
// level)
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int depth(struct TreeNode *root) {
  if (root == NULL)
    return 0;
  else
    return 1 + fmax(depth(root->left), depth(root->right));
}

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
  int dep = depth(root);
  if (dep == 0) {
    *returnSize = 0;
    return NULL;
  }
  *returnColumnSizes = malloc(dep * sizeof(int));
  int **ans = malloc(dep * sizeof(int *)), ans_idx = 0;
  struct TreeNode **q0 = malloc(1000 * sizeof(struct TreeNode *));
  struct TreeNode **q1 = malloc(1000 * sizeof(struct TreeNode *));
  int idx0 = 0, idx1 = 0;
  q0[idx0] = root;
  idx0 = 1;
  while (idx0 || idx1) {
    if (idx0) {
      ans[ans_idx] = malloc(idx0 * sizeof(int));
      returnColumnSizes[0][ans_idx] = idx0;
      for (int i = idx0 - 1; i >= 0; i--) {
        ans[ans_idx][idx0 - 1 - i] = q0[i]->val;
        if (q0[i]->left) {
          q1[idx1] = q0[i]->left;
          idx1++;
        }
        if (q0[i]->right) {
          q1[idx1] = q0[i]->right;
          idx1++;
        }
      }
      ans_idx++;
      idx0 = 0;
    } else {
      ans[ans_idx] = malloc(idx1 * sizeof(int));
      returnColumnSizes[0][ans_idx] = idx1;
      for (int i = idx1 - 1 - i; i >= 0; i--) {
        ans[ans_idx][idx1 - 1 - i] = q1[i]->val;
        if (q1[i]->right) {
          q0[idx0] = q1[i]->left;
          idx0++;
        }
      }
      ans_idx++;
      idx1 = 0;
    }
  }
  *returnSize = dep;
  return ans;
}
