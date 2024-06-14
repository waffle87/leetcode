// 501. Find Mode in Binary Search Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary search tree with duplicates, return all the
 * 'modes(s)' (ie. the most frequently occured element in it). if the tree has
 * more than one mode, return them in any order.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void order(struct TreeNode *root, int *cnt, int a[2][10000], int *max) {
  if (!root)
    return;
  order(root->left, cnt, a, max);
  if (!a[1][*cnt]) {
    a[0][*cnt] = root->val;
    a[1][*cnt]++;
  } else if (root->val != a[0][*cnt]) {
    (*cnt)++;
    a[0][*cnt] = root->val;
    a[1][*cnt]++;
  } else {
    a[1][*cnt]++;
  }
  if (*max < a[1][*cnt])
    *max = a[1][*cnt];
  order(root->right, cnt, a, max);
}

int *findMode(struct TreeNode *root, int *return_size) {
  if (!root)
    return NULL;
  int a[2][10000] = {0};
  int *max = (int *)malloc(sizeof(int));
  int *cnt = (int *)malloc(sizeof(int));
  *max = 0, *cnt = 0;
  order(root, cnt, a, max);
  int *ans = (int *)malloc(sizeof(int) * 10000);
  *return_size = 0;
  for (int i = 0; i <= *cnt; i++)
    if (a[1][i] == *max)
      ans[(*return_size)++] = a[0][i];
  return ans;
}
