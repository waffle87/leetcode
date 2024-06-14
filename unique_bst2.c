// 95. Unique Binary Search Trees II
#include <stdlib.h>

/*
 * given an integer 'n', return all the structurally unique BST's which has
 * exactly 'n' nodes of unique values from 1 to 'n'. return the answer in any
 * order.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode **process(int begin, int end, int *return_size, int *tree_num) {
  if (begin > end) {
    struct TreeNode **res = malloc(sizeof(struct TreeNode *));
    *return_size = 1;
    res[0] = NULL;
    return res;
  }
  if (begin == end) {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = begin;
    root->left = NULL;
    root->right = NULL;
    struct TreeNode **res = malloc(sizeof(struct TreeNode *));
    res[0] = root;
    *return_size = 1;
    return res;
  }
  int idx = 0;
  struct TreeNode **res =
      malloc(tree_num[end - begin + 1] * sizeof(struct TreeNode *));
  for (int i = begin; i <= end; i++) {
    int ln, rn;
    struct TreeNode **l = process(begin, i - 1, &ln, tree_num);
    struct TreeNode **r = process(i + 1, end, &rn, tree_num);
    for (int m = 0; m < ln; m++) {
      for (int n = 0; n < rn; n++) {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        root->val = i;
        root->left = l[m];
        root->right = r[n];
        res[idx] = root;
        idx++;
      }
    }
  }
  *return_size = idx;
  return res;
}

struct Treenode **generateTrees(int n, int *return_size) {
  int *tree_num = calloc(n + 1, sizeof(int));
  tree_num[0] = 1;
  tree_num[1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < i; j++)
      tree_num[i] += tree_num[j] * tree_num[i - 1 - j];
  return process(1, n, return_size, tree_num);
}
