// 2265. Count Nodes Equal to Average of Subtree
#include "leetcode.h"

/*
 * given the root of a binary tree, return the number of nodes where the value
 * of the node is equal to the average of the values in its subtree. note, the
 * average of 'n' elements is the sum of the n elements divided by n and rounded
 * down to the nearest integer. also, a subtree of root is a tree consisting of
 * root and all of its descendants
 */

struct data {
  int total;
  int count;
};

struct data postorder(struct TreeNode *root, int *mid) {
  struct data res = {0, 0};
  if (!root)
    return res;
  if (root->left) {
    struct data left = postorder(root->left, mid);
    res.total += left.total;
    res.count += left.count;
  }
  if (root->right) {
    struct data right = postorder(root->right, mid);
    res.total += right.total;
    res.count += right.count;
  }
  res.total += root->val;
  res.count++;
  if (res.total / res.count == root->val)
    ++(*mid);
  return res;
}

int averageOfSubtree(struct TreeNode *root) {
  int mid = 0;
  struct data res = postorder(root, &mid);
  return mid;
}

int main() {
  int r1i[] = {4, 8, 5, 0, 1, -1, 6}, r2i[] = {1};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  int aos1 = averageOfSubtree(r1);
  int aos2 = averageOfSubtree(r2);
  printf("%d\n", aos1);
  assert(aos1 == 5);
  printf("%d\n", aos2);
  assert(aos2 == 1);
  treenode_free(r1);
  treenode_free(r2);
}
