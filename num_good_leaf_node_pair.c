// 1530. Number of Good Leaf Nodes Pairs
#include "leetcode.h"

/*
 * you are given the 'root' of a binary tree and an integer 'distance' a pair of
 * two different leaf nodes of a binary tree is said to be good if the length of
 * the shortest path between them is less than or equal to 'distance'. return
 * the number of good leaf node pairs in the tree.
 */

int dfs(struct TreeNode *root, int distance, int *cnt, int *depth) {
  if (!root)
    return 0;
  if (!root->left && !root->right) {
    depth[0] = 1;
    return 1;
  }
  int left_depth[10] = {0}, right_depth[10] = {0};
  int left_cnt = dfs(root->left, distance, cnt, left_depth);
  int right_cnt = dfs(root->right, distance, cnt, right_depth);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (i + j + 2 <= distance)
        *cnt += left_depth[i] * right_depth[j];
  for (int i = 0; i < 9; i++)
    depth[i + 1] = left_depth[i] + right_depth[i];
  return left_cnt + right_cnt;
}

int countPairs(struct TreeNode *root, int distance) {
  int ans = 0, depth[10] = {0};
  dfs(root, distance, &ans, depth);
  return ans;
}

int main() {
  struct TreeNode *root = treenode_create(1);
  root->left = treenode_create(2);
  root->right = treenode_create(3);
  root->left->left = treenode_create(4);
  printf("%d\n", countPairs(root, 3)); // expect: 1
}
