// 2458. Height of Binary Tree After Subtree Removal Queries
#include "leetcode.h"

/*
 * you are given the 'root' of a binary tree with 'n' nodes. each node is
 * assigned a unique value from 1 to 'n'. you are also given an array 'queries'
 * of size 'm'. you have to perform 'm' independent queries on the tree where in
 * the i'th query, you remove the subtree rooted at the node with the value
 * 'queries[i]' from thre tree. it is guaranteed that 'queries[i]' will not be
 * equal to the value of the root. return an array 'answer' of size 'm' where
 * 'answer[i]' is the height of the tree after performining the i'th query
 */

#define MAX_NODES 100001

struct node_info {
  int height;
  int level;
};

struct level_info {
  int max_height1;
  int max_height2;
};

struct node_info *node_map[MAX_NODES];
struct level_info *level_map[MAX_NODES];

int dfs(struct TreeNode *root, int level) {
  if (!root)
    return 0;
  int left = dfs(root->left, level + 1);
  int right = dfs(root->right, level + 1);
  int height = left > right ? left : right;
  if (!level_map[level]) {
    level_map[level] = (struct level_info *)malloc(sizeof(struct level_info));
    level_map[level]->max_height1 = -1;
    level_map[level]->max_height2 = -1;
  }
  if (height >= level_map[level]->max_height1) {
    level_map[level]->max_height2 = level_map[level]->max_height1;
    level_map[level]->max_height1 = height;
  } else if (height > level_map[level]->max_height2)
    level_map[level]->max_height2 = height;
  node_map[root->val] = (struct node_info *)malloc(sizeof(struct node_info));
  node_map[root->val]->height = height;
  node_map[root->val]->level = level;
  return height + 1;
}

int *treeQueries(struct TreeNode *root, int *queries, int queriesSize,
                 int *returnSize) {
  *returnSize = queriesSize;
  int max_depth = dfs(root, 0) - 1;
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int curr = queries[i];
    struct node_info *n = node_map[curr];
    int height = n->height;
    int level = n->level;
    struct level_info *l = level_map[level];
    if (l->max_height1 == height)
      ans[i] = l->max_height2 != -1
                   ? max_depth - abs(l->max_height1 - l->max_height2)
                   : max_depth - 1;
    else
      ans[i] = max_depth;
  }
  for (int i = 0; i < MAX_NODES; i++) {
    if (node_map[i]) {
      free(node_map[i]);
      node_map[i] = NULL;
    }
    if (level_map[i]) {
      free(level_map[i]);
      level_map[i] = NULL;
    }
  }
  return ans;
}

int main() {
  struct TreeNode *root = treenode_create(5);
  root->left = treenode_create(8);
  root->right = treenode_create(9);
  root->left->left = treenode_create(2);
  root->left->right = treenode_create(1);
  root->right->left = treenode_create(3);
  root->right->right = treenode_create(7);
  root->left->left->left = treenode_create(4);
  root->left->left->right = treenode_create(6);
  int queries[] = {3, 2, 4, 8}, returnSize;
  int *tq = treeQueries(root, queries, ARRAY_SIZE(queries), &returnSize);
  for (int i = 0; i < returnSize; i++)
    printf("%d ", tq[i]); // expect: 3 2 3 2
  printf("\n");
  free(tq);
  treenode_free(root);
}
