// 865. Smallest Subtree with all the Deepest Nodes
#include "leetcode.h"

/*
 * given the 'root' of a binary tree, the depth of each node is the shortest
 * distance to the root. return the smallest subtree such that it contains all
 * the deepest nodes in the original tree. a node is called the deepest if it
 * has the largest depth possible among any node in the entire tree. the
 * subbtree of a node is a tree consisting of that node, plus the set of all
 * descendants of that node
 */

struct pair {
  int depth;
  struct TreeNode *node;
};

struct pair dfs(struct TreeNode *root) {
  if (!root)
    return (struct pair){0, NULL};
  struct pair l = dfs(root->left);
  struct pair r = dfs(root->right);
  if (l.depth > r.depth)
    return (struct pair){l.depth + 1, l.node};
  if (r.depth > l.depth)
    return (struct pair){r.depth + 1, r.node};
  return (struct pair){l.depth + 1, root};
}

struct TreeNode *subtreeWithAllDeepest(struct TreeNode *root) {
  return dfs(root).node;
}

int main() {
  int r1i[] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
  int r2i[] = {1};
  int r3i[] = {0, 1, 3, -1, 2};
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  struct TreeNode *r3 = treenode_build(r3i, ARRAY_SIZE(r3i));
  struct TreeNode *stwad1 = subtreeWithAllDeepest(r1);
  struct TreeNode *stwad2 = subtreeWithAllDeepest(r1);
  struct TreeNode *stwad3 = subtreeWithAllDeepest(r1);
  treenode_print(stwad1); // expect: 2 7 4
  treenode_print(stwad2); // expect: 1
  treenode_print(stwad3); // expect: 2
  treenode_free(r1);
  treenode_free(r2);
  treenode_free(r3);
  treenode_free(stwad1);
  treenode_free(stwad2);
  treenode_free(stwad3);
}
