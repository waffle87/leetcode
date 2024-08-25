// 145. Binary Tree Postorder Traversal
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return the postorder traversal of its
 * nodes' values
 */

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  int *ans = (int *)malloc(100 * sizeof(int)), idx = 0;
  *returnSize = 0;
  struct TreeNode *stack[100] = {NULL};
  while (idx || root) {
    if (root) {
      stack[idx++] = root;
      ans[(*returnSize)++] = root->val;
      root = root->right;
    } else {
      struct TreeNode *node = stack[--idx];
      root = node->left;
    }
  }
  for (int i = 0, j = *returnSize - 1; i < j; i++, j--) {
    int tmp = ans[j];
    ans[j] = ans[i];
    ans[i] = tmp;
  }
  return ans;
}

int main() {
  struct TreeNode *root = treenode_create(1);
  root->right = treenode_create(2);
  root->right->left = treenode_create(3);
  int rs1, *pt1 = postorderTraversal(root, &rs1);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pt1[i]); // expect: 3 2 1
  printf("\n");
  free(pt1);
}
