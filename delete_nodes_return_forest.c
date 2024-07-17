// 1110. Delete Nodes And Return Forest
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, each node in the tree has a distinct
 * value. after deleting all nodes with a value in 'to_delete', we are left with
 * a forest (a disjoint union of trees). return the roots of the trees in the
 * remaining forest. you may return the result in any order.
 */

void delete_nodes(struct TreeNode **tree, struct TreeNode **res, int *res_size,
                  bool *del) {
  if (!*tree)
    return;
  delete_nodes(&(*tree)->left, res, res_size, del);
  delete_nodes(&(*tree)->right, res, res_size, del);
  if (!del[(*tree)->val])
    return;
  if ((*tree)->left)
    res[(*res_size)++] = (*tree)->left;
  if ((*tree)->right)
    res[(*res_size)++] = (*tree)->right;
  *tree = NULL;
}

struct TreeNode **delNodes(struct TreeNode *root, int *to_delete,
                           int to_deleteSize, int *returnSize) {
  *returnSize = 0;
  struct TreeNode **ans =
      (struct TreeNode **)calloc(1001, sizeof(struct TreeNode *));
  bool *del = (bool *)calloc(1001, sizeof(bool));
  for (int i = 0; i < to_deleteSize; i++)
    del[to_delete[i]] = true;
  delete_nodes(&root, ans, returnSize, del);
  if (root)
    ans[(*returnSize)++] = root;
  return ans;
}
