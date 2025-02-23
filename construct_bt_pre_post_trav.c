// 889. Construct Binary Tree from Preorder and Postorder Traversal
#include "leetcode.h"

/*
 * given two integer array, 'preorder' and 'postorder' where 'preorder' is the
 * preorder traversal of a binary tree of distinct values and 'postorder' is the
 * postorder traversal of the same tree, reconstruct and return the binary tree.
 * if there exists multiple answers, you can return any of  them.
 */

struct TreeNode *constructFromPrePost(int *preorder, int preorderSize,
                                      int *postorder, int postorderSize) {
  struct TreeNode *ans = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ans->val = *preorder;
  ans->left = ans->right = 0;
  if (preorderSize == 1)
    return ans;
  int val = postorder[postorderSize - 2], i;
  for (i = 1; preorder[i] ^ val; ++i)
    ;
  if (i > 1)
    ans->left = constructFromPrePost(preorder + 1, i - 1, postorder, i - 1);
  ans->right = constructFromPrePost(
      preorder + i, preorderSize - i,
      postorder + postorderSize - (preorderSize - i) - 1, preorderSize - i);
  return ans;
}

int main() {
  int pre1[] = {1, 2, 4, 5, 3, 6, 7}, post1[] = {4, 5, 2, 6, 7, 3, 1};
  int pre2[] = {1}, post2[] = {1};
  struct TreeNode *cfpp1 =
      constructFromPrePost(pre1, ARRAY_SIZE(pre1), post1, ARRAY_SIZE(post1));
  struct TreeNode *cfpp2 =
      constructFromPrePost(pre2, ARRAY_SIZE(pre2), post2, ARRAY_SIZE(post2));
  treenode_print(cfpp1); // expect: 1 2 3 4 5 6 7
  printf("\n");
  treenode_print(cfpp2); // expect: 1
  printf("\n");
  treenode_free(cfpp1);
  treenode_free(cfpp2);
}
