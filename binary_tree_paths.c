// 257. Binary Tree Paths
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, return all root to leaf paths in any
 * order. a leaf is a node with no children
 */

void dfs(struct TreeNode *node, char **paths, char *path, int path_size,
         int *path_num) {
  if (!node)
    return;
  int size = snprintf(path + path_size, 7, "%d->", node->val);
  path_size += size;
  if (!node->left && !node->right) {
    paths[*path_num] = (char *)malloc((path_size - 1) * sizeof(char));
    memcpy(paths[*path_num], path, path_size - 2);
    paths[*path_num][path_size - 2] = '\0';
    (*path_num)++;
  }
  dfs(node->left, paths, path, path_size, path_num);
  dfs(node->right, paths, path, path_size, path_num);
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
  // 1 + 2 + 4 + 8 + 16 + 32 + "37" = 100 implies max path possibility is 37
  char **paths = (char **)malloc(37 * sizeof(char *));
  // 100 * 4("-100") + 99 * 2("->") + 1("\0")
  char *path = (char *)malloc(599 * sizeof(char));
  *returnSize = 0;
  dfs(root, paths, path, 0, returnSize);
  free(path);
  return paths;
}

int main() {
  int returnSize;
  struct TreeNode *root = treenode_create(1);
  root->left = treenode_create(2);
  root->left->right = treenode_create(5);
  root->right = treenode_create(3);
  char **btp = binaryTreePaths(root, &returnSize);
  for (int i = 0; i < returnSize; i++)
    printf("%s ", btp[i]); // expect: "1->2->5","1->3"
  free(btp);
}
