// 1161. Maximum Level Sum of a Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on. return the smallest level 'x' such that the sum
 * of all the values of nodes at level 'x' is maximal.
 */

int maxLevelSum(struct TreeNode *root) {
  struct TreeNode **q =
      (struct TreeNode **)malloc(10001 * sizeof(struct TreeNode *));
  int head = 0, tail = 0;
  q[tail++] = root;
  long long max_sum = LLONG_MIN;
  int max_level = 1, curr_level = 1;
  while (head < tail) {
    long long curr_sum = 0;
    for (int i = 0; i < tail - head; i++) {
      struct TreeNode *curr_node = q[head++];
      curr_sum += curr_node->val;
      if (curr_node->left)
        q[tail++] = curr_node->left;
      if (curr_node->right)
        q[tail++] = curr_node->right;
    }
    if (curr_sum > max_sum) {
      max_sum = curr_sum;
      max_level = curr_level;
    }
    curr_level++;
  }
  free(q);
  return max_level;
}

int main() {
  int r1i[] = {1, 7, 0, 7, -8, -1, -1};
  int r2i[] = {989, -1, 10250, 98693, -89388, -1, -1, -1, -32127};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  printf("%d\n", maxLevelSum(r1)); // expect: 2
  printf("%d\n", maxLevelSum(r2)); // expect: 2
  treenode_free(r1);
  treenode_free(r2);
}
