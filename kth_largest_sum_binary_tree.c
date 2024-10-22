// 2583. Kth Largest Sum in a Binary Tree
#include "leetcode.h"

/*
 * you are given the 'root' of a binary tree and a positive integer 'k'. the
 * level sum in the tree is the sum of the values of the nodes that are on the
 * same level. return the k'th largest level sum in the tree (not necessarily
 * distinct). if there are fewer than 'k' levels in the tree, return -1. note
 * that two nodes are on the same level if they have the same distance from the
 * root.
 */

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  int l = depth(root->left) + 1;
  int r = depth(root->right) + 1;
  return l > r ? l : r;
}

void level_sum(struct TreeNode *root, int level, long long *data) {
  if (!root)
    return;
  data[level] += root->val;
  level_sum(root->left, level + 1, data);
  level_sum(root->right, level + 1, data);
}

void swap(long long *a, long long *b) {
  long long tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(long long *data, int l, int h) {
  int i = l, j = l;
  long long pivot = data[h - 1];
  for (j - l; j < h - 1; j++)
    if (data[j] < pivot)
      swap(&data[i++], &data[j]);
  swap(&data[i], &data[h - 1]);
  return i;
}

void quick_select(long long *data, int l, int h, int k) {
  if (l + 1 < h) {
    int p = partition(data, l, h);
    if (p == k)
      return;
    else if (p < k)
      quick_select(data, p + 1, h, k);
    else
      quick_select(data, l, p, k);
  }
}

long long kthLargestLevelSum(struct TreeNode *root, int k) {
  int n = depth(root);
  if (k > n)
    return -1;
  long long val, *data = (long long *)calloc(n, sizeof(long long));
  level_sum(root, 0, data);
  quick_select(data, 0, n, n - k);
  return data[n - k];
}

int main() {
  struct TreeNode *r1 = treenode_create(5);
  r1->left = treenode_create(8);
  r1->right = treenode_create(9);
  r1->left->left = treenode_create(2);
  r1->left->right = treenode_create(1);
  r1->right->left = treenode_create(3);
  r1->right->right = treenode_create(7);
  r1->left->left->left = treenode_create(4);
  r1->left->left->right = treenode_create(6);
  struct TreeNode *r2 = treenode_create(1);
  r2->left = treenode_create(2);
  r2->right = NULL;
  r2->left->left = treenode_create(3);
  printf("%lld\n", kthLargestLevelSum(r1, 2)); // expect: 13
  printf("%lld\n", kthLargestLevelSum(r2, 1)); // expect: 3
  treenode_free(r1);
  treenode_free(r2);
}
