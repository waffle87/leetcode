// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
#include "leetcode.h"

/*
 * you are given the 'root' of a binary tree with unique values. in one
 * operation, you can choose any two nodes at the same level and swap their
 * values. return the minimum number of operations needed to make the values at
 * each level sorted in a strictly increasing order. the level of a node is the
 * number of edges along the path between it and the root node.
 */

#define MAX_SIZE 34472

struct node_idx {
  struct TreeNode *node;
  int idx;
};

int cmp(const void *a, const void *b) {
  struct node_idx *aa = (struct node_idx *)a;
  struct node_idx *bb = (struct node_idx *)b;
  if ((*aa).node->val > (*bb).node->val)
    return 1;
  return -1;
}

int minimumOperations(struct TreeNode *root) {
  struct node_idx nodes[MAX_SIZE], new[MAX_SIZE];
  new[0].node = root;
  int len = 0, new_len = 1, tmp, ans = 0;
  struct node_idx *ptr = nodes, *new_ptr = new, *tmp_ptr;
  while (new_len) {
    tmp_ptr = new_ptr;
    new_ptr = ptr;
    ptr = tmp_ptr;
    len = new_len;
    new_len = 0;
    for (int i = 0; i < len; i++) {
      if (ptr[i].node->left) {
        new_ptr[new_len].idx = new_len;
        new_ptr[new_len++].node = ptr[i].node->left;
      }
      if (ptr[i].node->right) {
        new_ptr[new_len].idx = new_len;
        new_ptr[new_len++].node = ptr[i].node->right;
      }
    }
    qsort(ptr, len, sizeof(struct node_idx), cmp);
    for (int i = 0; i < len; i++)
      while (ptr[i].idx != i) {
        ans++;
        tmp = ptr[i].idx;
        ptr[i].idx = ptr[ptr[i].idx].idx;
        ptr[tmp].idx = tmp;
      }
  }
  return ans;
}

int main() {
  struct TreeNode *r1 = treenode_create(1);
  r1->left = treenode_create(4);
  r1->left->left = treenode_create(7);
  r1->left->right = treenode_create(6);
  r1->right = treenode_create(3);
  r1->right->left = treenode_create(8);
  r1->right->right = treenode_create(5);
  r1->right->left->left = treenode_create(9);
  r1->right->right->left = treenode_create(10);
  struct TreeNode *r2 = treenode_create(1);
  r2->left = treenode_create(3);
  r2->left->left = treenode_create(7);
  r2->left->right = treenode_create(6);
  r2->right = treenode_create(2);
  r2->right->left = treenode_create(5);
  r2->right->right = treenode_create(4);
  struct TreeNode *r3 = treenode_create(1);
  r3->left = treenode_create(2);
  r3->left->left = treenode_create(4);
  r3->left->right = treenode_create(5);
  r3->right = treenode_create(3);
  r3->right->left = treenode_create(6);
  printf("%d\n", minimumOperations(r1)); // expect: 3
  printf("%d\n", minimumOperations(r2)); // expect: 3
  printf("%d\n", minimumOperations(r3)); // expect: 0
  treenode_free(r1);
  treenode_free(r2);
  treenode_free(r3);
}
