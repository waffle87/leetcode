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

int tree_height(struct TreeNode *root) {
  if (root) {
    int l = tree_height(root->left), r = tree_height(root->right);
    return l >= r ? l + 1 : r + 1;
  }
  return 0;
}

bool tree_lca(struct TreeNode *root, int tree_height, int curr,
              struct TreeNode **lca) {
  if (root) {
    bool l = tree_lca(root->left, tree_height, curr + 1, lca);
    bool r = tree_lca(root->right, tree_height, curr + 1, lca);
    if (curr == tree_height) {
      *lca = root;
      return true;
    }
    if (l && r)
      *lca = root;
    return l || r;
  }
  return false;
}

struct TreeNode *subtreeWithAllDeepest(struct TreeNode *root) {
  int height = tree_height(root);
  struct TreeNode *lca = NULL;
  tree_lca(root, height, 1, &lca);
  return lca;
}

int main() {
  struct TreeNode *root = treenode_create(3);
  root->left = treenode_create(5);
  root->left->left = treenode_create(6);
  root->left->right = treenode_create(2);
  root->left->right->left = treenode_create(7);
  root->left->right->right = treenode_create(4);
  root->right = treenode_create(1);
  root->right->left = treenode_create(0);
  root->right->right = treenode_create(8);
  struct TreeNode *res = subtreeWithAllDeepest(root);
  treenode_print(res); // expect: 7 2 4
}
