// 655. Print Binary Tree
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, construct a 0-indexed 'm x n' string
 * matrix 'res' that represents a formatted layout of the tree. the formatted
 * layout matrix should be constructed using the following rules. the height of
 * the tree is 'height' and the number of rows 'm' should be equal to 'height +
 * 1'. the number of columns 'n' should be equal to '2^(height + 1) - 1'. place
 * the root node in the middle of the top row (more formally, at location
 * 'res[0][(n - 1) / 2]'). continue this process until all the nodes in the tree
 * have been placed. any empty cells should contain the empty string "". return
 * the constructed matrix 'res'.
 */

#define STR_LEN 10

int height(struct TreeNode *node) {
  if (!node)
    return -1;
  return 1 + fmax(height(node->left), height(node->right));
}

void build(struct TreeNode *node, char ***grid, int h, int r, int c) {
  if (!node)
    return;
  sprintf(grid[r][c], "%d", node->val);
  build(node->left, grid, h, r + 1, c - (int)pow(2, h - r - 1));
  build(node->right, grid, h, r + 1, c + (int)pow(2, h - r - 1));
}

char ***new_grid(size_t m, size_t n) {
  char ***res = (char ***)malloc(m * sizeof(char **));
  for (int i = 0; i < m; i++) {
    res[i] = (char **)malloc(n * sizeof(char *));
    for (int j = 0; j < n; j++) {
      res[i][j] = (char *)calloc(STR_LEN, sizeof(char));
      strcat(res[i][j], ""
                        "");
    }
  }
  return res;
}

char ***printTree(struct TreeNode *root, int *returnSize,
                  int **returnColumnSizes) {
  int h = height(root), m = h + 1, n = (1 << (h + 1)) - 1;
  char ***grid = new_grid(m, n);
  build(root, grid, h, 0, (n - 1) / 2);
  *returnSize = m;
  *returnColumnSizes = (int *)malloc(m * sizeof(int));
  for (int i = 0; i < m; i++)
    *returnColumnSizes[i] = n;
  return grid;
}

int main() {
  int r1i[] = {1, 2}, rs1, *rcs1;
  int r2i[] = {1, 2, 3, -1, 4}, rs2, *rcs2;
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  char ***pt1 = printTree(r1, &rs1, &rcs1);
  char ***pt2 = printTree(r2, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%s ", pt1[i][j]);
    printf("\n");
  }
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%s ", pt2[i][j]);
    printf("\n");
  }
  for (int i = 0; i < rs1; i++)
    free(pt1[i]);
  free(pt1);
  free(rcs1);
  treenode_free(r1);
  for (int i = 0; i < rs2; i++)
    free(pt2[i]);
  free(pt2);
  free(rcs2);
  treenode_free(r2);
}
