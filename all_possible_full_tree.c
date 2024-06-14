// 894. All Possible Full Binary Trees
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer 'n', return a list of all possible full binary trees with
 * 'n' nodes. each node of each tree in the answer must have 'node.val == 0'.
 * each element of the answer is the root node of one possible tree. you may
 * return the final list of trees in any order. a full binary tree is a binary
 * tree where each node has exactly zero or two children
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode **allPossibleFBT(int n, int *return_size) {
  if (!n % 2) {
    *return_size = 0;
    return NULL;
  }
  if (n == 1) {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = 0;
    root->left = NULL;
    root->right = NULL;
    struct TreeNode **ans = malloc(sizeof(struct TreeNode *));
    *return_size = 1;
    ans[0] = root;
    return ans;
  }
  if (n == 3) {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    struct TreeNode *left = malloc(sizeof(struct TreeNode));
    struct TreeNode *right = malloc(sizeof(struct TreeNode));
    root->val = 0;
    left->val = 0;
    right->val = 0;
    left->left = NULL;
    left->right = NULL;
    right->left = NULL;
    right->right = NULL;
    root->left = left;
    root->right = right;
    struct TreeNode **ans = malloc(sizeof(struct TreeNode));
    *return_size = 1;
    ans[0] = root;
    return ans;
  }
  struct TreeNode **ans = malloc(5000 * sizeof(struct TreeNode));
  int idx = 0;
  for (int i = 1; i <= (n - 1); i += 2) {
    int *cnt_l = calloc(1, sizeof(int));
    int *cnt_r = calloc(1, sizeof(int));
    struct TreeNode **l_tree = allPossibleFBT(i, cnt_l);
    struct TreeNode **r_tree = allPossibleFBT(n - 1 - i, cnt_r);
    for (int j = 0; j < (*cnt_l); j++) {
      for (int k = 0; k < (*cnt_r); k++) {
        struct TreeNode *new = malloc(sizeof(struct TreeNode));
        new->val = 0;
        new->left = l_tree[j];
        new->right = r_tree[k];
        ans[idx] = new;
        idx++;
      }
    }
    free(cnt_l), free(cnt_r);
  }
  ans = realloc(ans, idx * sizeof(struct TreeNode *));
  *return_size = idx;
  return ans;
}
