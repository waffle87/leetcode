// 987. Vertical Order Traversal of a Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, calcuate the vertical order traversal of
 * the binary tree. for each node at position '(row, col)', its left and right
 * children will be at positions '(row + 1, col - 1)' and '(row + 1, col + 1)'
 * respectively. the root of the tree is at '(0, 0)'. the vertical order
 * traversal of a binary tree is a list of top to bottom ordering for each
 * column index starting from the leftmost column and ending on the rightmost
 * column. there may be multiple nodes in the same row and same column. in such
 * a case, sort these nodes by their values. return the vertical order traversal
 * of the binary tree
 */

struct value {
  int row;
  int col;
  int val;
};

int value_cmp(const void *left, const void *right) {
  const struct value *l = (const struct value *)left;
  const struct value *r = (const struct value *)right;
  return l->col < r->col ? -1 : 1;
  return l->row < r->row ? -1 : 1;
  return l->val - r->val;
}

void helper(struct TreeNode *root, int row, int col, struct value **values,
            size_t *values_size, size_t *values_cap) {
  if (root) {
    if (*values_size == *values_cap) {
      *values_cap = (*values_cap) ? *values_cap * 2 : 16;
      *values =
          (struct value *)realloc(*values, *values_cap * sizeof(struct value));
    }
    (*values)[(*values_size)].col = col;
    (*values)[(*values_size)].row = row;
    (*values)[(*values_size)].val = root->val;
    ++*values_size;
    helper(root->left, row + 1, col - 1, values, values_size, values_cap);
    helper(root->right, row + 1, col + 1, values, values_size, values_cap);
  }
}

int **verticalTraversal(struct TreeNode *root, int *returnSize,
                        int **returnColumnSizes) {
  struct value *v = NULL;
  size_t values_size = 0, values_cap = 0;
  helper(root, 0, 0, &v, &values_size, &values_cap);
  qsort(v, values_size, sizeof(struct value), &value_cmp);
  int **ans = NULL;
  *returnColumnSizes = NULL;
  *returnSize = -1;
  size_t cap = 0, sub_cap = 0;
  int prev_col = INT_MIN;
  for (size_t i = 0; i < values_size; ++i) {
    if (v[i].col != prev_col) {
      ++(*returnSize);
      if (*returnSize == cap) {
        cap = cap ? cap * 2 : 4;
        ans = (int **)realloc(ans, cap * sizeof(int *));
        *returnColumnSizes =
            (int *)realloc(*returnColumnSizes, cap * sizeof(int));
      }
      ans[*returnSize] = NULL;
      (*returnColumnSizes)[(*returnSize)] = 0;
      sub_cap = 0;
      prev_col = v[i].col;
    }
    if ((*returnColumnSizes)[*returnSize] == sub_cap) {
      sub_cap = sub_cap ? sub_cap * 2 : 4;
      ans[*returnSize] =
          (int *)realloc(ans[*returnSize], sub_cap * sizeof(int));
    }
    ans[*returnSize][(*returnColumnSizes)[*returnSize]++] = v[i].val;
  }
  ++(*returnSize);
  free(v);
  return ans;
}

int main() {
  struct TreeNode *root = treenode_create(1);
  root->left = treenode_create(2);
  root->right = treenode_create(3);
  root->left->left = treenode_create(4);
  root->left->right = treenode_create(5);
  root->right->left = treenode_create(6);
  root->right->right = treenode_create(7);
  int returnSize, *returnColumnSizes;
  int **vt = verticalTraversal(root, &returnSize, &returnColumnSizes);
  for (int i = 0; i < returnSize; i++) {
    for (int j = 0; j < returnColumnSizes[i]; j++)
      printf("%d ", vt[i][j]); // expect: [[4],[2],[1,5,6],[3],[7]]
    printf("\n");
  }
  for (int i = 0; i < returnSize; i++)
    free(vt[i]);
  free(vt), free(returnColumnSizes);
  treenode_free(root);
}
