// 1457. Pseudo-Palindromic Paths in a Binary Tree
#include "leetcode.h"

/*
 * given a binary tree where node values are digits from 1 to 9. a path in the
 * binary tree is said to be pseudo palindromic if at least one permutation of
 * the node values in the path is a palindrome. return the number of pseudo
 * palindromic paths going from the root node to leaf nodes.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int dfs(struct TreeNode *root, int *hash_table, int hash_size) {
  hash_table[root->val]++;
  if (!root->left && !root->right) {
    int odd = 0;
    for (int i = 0; i < hash_size; i++) {
      if (hash_table[i] % 2) {
        odd++;
        if (odd > 1)
          return 0;
      }
    }
    return 1;
  }
  int left_cnt = 0, right_cnt = 0;
  if (root->left) {
    left_cnt = dfs(root->left, hash_table, hash_size);
    hash_table[root->left->val]--;
  }
  if (root->right) {
    right_cnt = dfs(root->right, hash_table, hash_size);
    hash_table[root->right->val]--;
  }
  return left_cnt + right_cnt;
}

int pseudoPalindromicPaths(struct TreeNode *root) {
  int hash_size = 10;
  int *hash_table = calloc(hash_size, sizeof(int));
  return dfs(root, hash_table, hash_size);
}
