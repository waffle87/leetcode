// 1261. Find Elements in a Contaminated Binary Tree
#include "leetcode.h"

/*
 * given a binary tree with the following rules: 'root.val == 0', for any
 * 'TreeNode': if 'TreeNode.val' has a value 'x' and 'TreeNode.left != null'
 * then 'TreeNode.left.val == 2 * x + 1', and if 'TreeNode.val' has a value 'x'
 * and 'TreeNode.right != null', then 'TreeNode.right.val = 2 * x + 2'. now the
 * binary tree is contaminated which means all 'TreeNode.val' have been changed
 * to -1. implemented the 'FindElements' class: 'findElementsCreate':
 * initialises the object with a contaminated tree and recovers it. 'bool
 * find(int target)' returns 'true' if the 'target' value exists in the
 * recovered binary tree.
 */

typedef struct {
  int map[10000];
  int map_size;
} FindElements;

void recover(FindElements *obj, struct TreeNode *node, int val) {
  obj->map[obj->map_size] = val;
  obj->map_size++;
  if (node->left)
    recover(obj, node->left, val * 2 + 1);
  if (node->right)
    recover(obj, node->right, val * 2 + 2);
  return;
}

FindElements *findElementsCreate(struct TreeNode *root) {
  FindElements *tree = (FindElements *)calloc(1, sizeof(FindElements));
  recover(tree, root, 0);
  return tree;
}

bool findElementsFind(FindElements *obj, int target) {
  for (int i = 0; i < obj->map_size; i++)
    if (obj->map[i] == target)
      return true;
  return false;
}

void findElementsFree(FindElements *obj) { free(obj); }

int main() {
  struct TreeNode *r1 = treenode_create(-1);
  r1->left = NULL;
  r1->right = treenode_create(-1);
  struct TreeNode *r2 = treenode_create(-1);
  r2->left = treenode_create(-1);
  r2->right = treenode_create(-1);
  r2->left->left = treenode_create(-1);
  r2->left->right = treenode_create(-1);
  struct TreeNode *r3 = treenode_create(-1);
  r3->left = NULL;
  r3->right = treenode_create(-1);
  r3->right->left = treenode_create(-1);
  r3->right->right = NULL;
  r3->right->left->left = treenode_create(-1);
  r3->right->left->right = NULL;
  FindElements *o1 = findElementsCreate(r1);
  FindElements *o2 = findElementsCreate(r2);
  FindElements *o3 = findElementsCreate(r3);
  printf("%d\n", findElementsFind(o1, 1)); // expect: 0
  printf("%d\n", findElementsFind(o1, 2)); // expect: 1
  printf("%d\n", findElementsFind(o2, 1)); // expect: 1
  printf("%d\n", findElementsFind(o2, 3)); // expect: 1
  printf("%d\n", findElementsFind(o2, 5)); // expect: 0
  printf("%d\n", findElementsFind(o3, 2)); // expect: 1
  printf("%d\n", findElementsFind(o3, 3)); // expect: 0
  printf("%d\n", findElementsFind(o3, 4)); // expect: 0
  printf("%d\n", findElementsFind(o3, 5)); // expect: 1
  findElementsFree(o1);
  findElementsFree(o2);
  findElementsFree(o3);
  treenode_free(r1);
  treenode_free(r2);
  treenode_free(r3);
}
