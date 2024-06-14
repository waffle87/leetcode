// 1361. Validate Binary Tree Nodes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * you have n binary trees nodes numbered from 0 to n - 1 where node i has two
 * children left_child and right_child. return true if any only if all the given
 * nodes from exactly one valid binary tree. if node i has no left children,
 * then left_child[i] will equal -1. note that the nodes have no values and that
 * we only use the node numbers in this problem.
 */

bool validateBinaryTreeNodes(int n, int *left_child, int left_child_size,
                             int *right_child, int right_child_size) {
  bool *flag = calloc(n, sizeof(bool));
  for (int i = 0; i < n; i++) {
    if (left_child[i] == -1)
      continue;
    flag[left_child[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    if (right_child[i] == -1)
      continue;
    flag[right_child[i]] = true;
  }
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (!flag[i]) {
      if (root == -1)
        root = i;
      else
        return false;
    }
  }
  if (root == -1)
    return false;
  bool *visited = calloc(n, sizeof(bool));
  int *stack = malloc(2 * n * sizeof(int));
  int count = 0;
  stack[count] = root;
  count++;
  int p = 0, node = 0;

  while (p < count) {
    node++;
    int left = left_child[stack[p]];
    int right = right_child[stack[p]];
    visited[stack[p]] = true;
    p++;
    if (left != -1) {
      if (visited[left] == true)
        return false;
      stack[count] = left;
      count++;
    }
    if (right != -1) {
      if (visited[right] == true)
        return false;
      stack[count] = right;
      count++;
    }
  }
  free(flag), free(visited);
  if (node == n)
    return true;
  return false;
}

int main() {
  int lc1[] = {1, -1, 3, -1}, rc1[] = {2, -1, -1, -1};
  int lc2[] = {1, -1, 3, -1}, rc2[] = {2, 3, -1, -1};
  int lc3[] = {1, 0}, rc3[] = {-1, -1};
  printf("%d\n", validateBinaryTreeNodes(4, lc1, 4, rc1, 4)); // expect: 1
  printf("%d\n", validateBinaryTreeNodes(4, lc2, 4, rc2, 4)); // expect: 0
  printf("%d\n", validateBinaryTreeNodes(2, lc3, 2, rc3, 2)); // expect: 0
}
