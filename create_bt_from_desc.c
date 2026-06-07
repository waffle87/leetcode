// 2196. Create Binary Tree From Descriptions
#include "leetcode.h"

/*
 * you are given a 2d integer array 'descriptions' where 'descriptions[i] =
 * [parent, child, is_left]' indicates that 'parent' is the parent of 'child' in
 * a binary tree of unique values. construct the binary tree described by
 * 'descriptions' and return its root the test cases will be generate such that
 * the binary tree is valid.
 */

struct map {
  int id;
  struct TreeNode *node;
  struct TreeNode *parent;
  UT_hash_handle hh;
};

struct TreeNode *createBinaryTree(int **descriptions, int descriptionsSize,
                                  int *descriptionsColSize) {
  struct map *map = NULL, *map_parent, *map_child;
  struct TreeNode *root = NULL, *node_parent, *node_child;
  for (int i = 0; i < descriptionsSize; i++) {
    HASH_FIND_INT(map, &descriptions[i][0], map_parent);
    if (!map_parent) {
      node_parent = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      *node_parent = (struct TreeNode){descriptions[i][0], NULL, NULL};
      map_parent = (struct map *)malloc(sizeof(struct map));
      *map_parent = (struct map){descriptions[i][0], node_parent, NULL};
      HASH_ADD_INT(map, id, map_parent);
    } else
      node_parent = map_parent->node;
    HASH_FIND_INT(map, &descriptions[i][1], map_child);
    if (!map_child) {
      node_child = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      *node_child = (struct TreeNode){descriptions[i][1], NULL, NULL};
      map_child = (struct map *)malloc(sizeof(struct map));
      *map_child = (struct map){descriptions[i][1], node_child, node_parent};
      HASH_ADD_INT(map, id, map_child);
    } else {
      node_child = map_child->node;
      map_child->parent = node_parent;
    }
    if (descriptions[i][2])
      node_parent->left = node_child;
    else
      node_parent->right = node_child;
  }
  HASH_ITER(hh, map, map_parent, map_child) {
    if (!map_parent->parent)
      root = map_parent->node;
    HASH_DEL(map, map_parent);
    free(map_parent);
  }
  return root;
}

int main() {
  int d1i[5][3] = {
      {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
  int d2i[3][3] = {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
  int r1i[] = {50, 20, 80, 15, 17, 19}, r2i[] = {1, 2, -1, -1, 3, 4};
  struct two_d_arr *d1 = two_d_arr_init(ARRAY_SIZE(d1i), ARRAY_SIZE(d1i), d1i);
  struct two_d_arr *d2 = two_d_arr_init(ARRAY_SIZE(d2i), ARRAY_SIZE(d2i), d2i);
  struct TreeNode *r1 = treenode_build(r1i, ARRAY_SIZE(r1i));
  struct TreeNode *r2 = treenode_build(r2i, ARRAY_SIZE(r2i));
  struct TreeNode *cbt1 = createBinaryTree(d1->arr, d1->row_size, d1->col_size);
  struct TreeNode *cbt2 = createBinaryTree(d2->arr, d2->row_size, d2->col_size);
  treenode_print(cbt1);
  printf("\n");
  treenode_print(cbt2);
  treenode_free(cbt1);
  treenode_free(cbt2);
  treenode_free(r1);
  treenode_free(r2);
  two_d_arr_free(d1);
  two_d_arr_free(d2);
}
