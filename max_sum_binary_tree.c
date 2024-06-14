// 1161. Maximum Level Sum of a Binary Tree
#include <limits.h>
#include <stdlib.h>

/*
 * given the 'root' of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on. return the smallest level 'x' such that the sum
 * of all the values of nodes at level 'x' is maximal.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxLevelSum(struct TreeNode *root) {
  struct TreeNode **even = malloc(5000 * sizeof(struct TreeNode *));
  struct TreeNode **odd = malloc(5000 * sizeof(struct TreeNode *));
  int even_idx = 0, odd_idx = 0;
  even[0] = root, even_idx = 1;
  int max_sum = INT_MIN, max_id = -1, level = 1;
  while (even_idx || odd_idx) {
    int sum = 0;
    if (even_idx) {
      for (int i = 0; i < even_idx; i++) {
        sum += even[i]->val;
        if (even[i]->left) {
          odd[odd_idx] = even[i]->left;
          odd_idx++;
        }
        if (even[i]->right) {
          odd[odd_idx] = even[i]->right;
          odd_idx++;
        }
      }
      if (sum > max_sum) {
        max_sum = sum;
        max_id = level;
      }
      even_idx = 0;
      level++;
    } else {
      for (int i = 0; i < odd_idx; i++) {
        sum += odd[i]->val;
        if (odd[i]->left) {
          even[even_idx] = odd[i]->left;
          even_idx++;
        }
        if (odd[i]->right) {
          even[even_idx] = odd[i]->right;
          even_idx++;
        }
      }
      if (sum > max_sum) {
        max_sum = sum;
        max_id = level;
      }
      odd_idx = 0;
      level++;
    }
  }
  return max_id;
}
