// 1382. Balance a Binary Search Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary search tree, return a balance binary search tree
 * with the same node values. if there is more than one answer, return any of
 * them. a binary search tree is balance if the depth of the two subtrees of
 * every node never differs by more than 1.
 */

int depth(struct TreeNode *root) {
  if (!root)
    return 0;
  return depth(root->left) + depth(root->right) + 1;
}

void inorder(struct TreeNode *root, struct TreeNode **arr, int *idx) {
  if (!root)
    return;
  inorder(root->left, arr, idx);
  arr[(*idx)++] = root;
  inorder(root->right, arr, idx);
}

struct TreeNode *build(struct TreeNode **arr, int l, int r) {
  if (l > r)
    return NULL;
  int m = l + (r - l) / 2;
  struct TreeNode *node = arr[m];
  node->left = build(arr, l, m - 1);
  node->right = build(arr, m + 1, r);
  return node;
}

struct TreeNode *balanceBST(struct TreeNode *root) {
  if (!root)
    return NULL;
  int n = depth(root), idx = 0;
  struct TreeNode **nodes =
      (struct TreeNode **)malloc(n * sizeof(struct TreeNode *));
  inorder(root, nodes, &idx);
  struct TreeNode *ans = build(nodes, 0, n - 1);
  free(nodes);
  return ans;
}

int main() {
  int r1i[] = {1, -1, 2, -1, 3, -1, 4, -1, -1};
  int r2i[] = {2, 1, 3};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  struct TreeNode *bbst1 = balanceBST(r1);
  struct TreeNode *bbst2 = balanceBST(r2);
  treenode_print(bbst1); // expect: 2 1 3 -1 -1 -1 4
  treenode_print(bbst2); // expect: 2 1 3
  treenode_free(r1);
  treenode_free(r2);
  treenode_free(bbst1);
  treenode_free(bbst2);
}
