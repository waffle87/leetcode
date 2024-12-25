// 515. Find Largest Value in Each Tree Row
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return an array of the largest value in
 * each row of the tree (0-indexed).
 */

void pre_order(struct TreeNode *node, int level, int *arr, int *size) {
  if (!node)
    return;
  if (*size <= level) {
    (*size)++;
    arr[level] = INT_MIN;
  }
  arr[level] = arr[level] > node->val ? arr[level] : node->val;
  pre_order(node->left, level + 1, arr, size);
  pre_order(node->right, level + 1, arr, size);
}

int *largestValues(struct TreeNode *root, int *returnSize) {
  if (!root) {
    *returnSize = 0;
    return NULL;
  }
  int n = 0, arr[10001];
  pre_order(root, 0, arr, &n);
  *returnSize = n;
  int *ans = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    ans[i] = arr[i];
  return ans;
}

int main() {
  struct TreeNode *r1 = treenode_create(1);
  r1->left = treenode_create(3);
  r1->right = treenode_create(2);
  r1->left->left = treenode_create(5);
  r1->left->right = treenode_create(3);
  r1->right->right = treenode_create(9);
  struct TreeNode *r2 = treenode_create(1);
  r2->left = treenode_create(2);
  r2->right = treenode_create(3);
  int rs1, rs2;
  int *lv1 = largestValues(r1, &rs1);
  int *lv2 = largestValues(r2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", lv1[i]); // expect: 1 3 9
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", lv2[i]); // expect: 1 3
  printf("\n");
  free(lv1), free(lv2);
  treenode_free(r1), treenode_free(r2);
}
