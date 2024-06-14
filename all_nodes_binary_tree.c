// 863. All Nodes Distance K in Binary Tree
#include <math.h>
#include <stdlib.h>

/*
 * given the 'root' of a binary tree, the value of a target node 'target', and
 * an integer 'k', return an array of the values of all nodes that have a
 * distance 'k' from the target node. you can return the answer in any order.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int depth(struct TreeNode *root) {
  if (!root)
    return -1;
  return fmax(depth(root->left), depth(root->right)) + 1;
}

void find_path(struct TreeNode *root, struct TreeNode *target,
               struct TreeNode **data, int data_idx, struct TreeNode **path,
               int *path_idx) {
  if (!root)
    return;
  data[data_idx] = root;
  if (root == target) {
    *path_idx = data_idx + 1;
    for (int i = 0; i < data_idx + 1; i++)
      path[i] = data[i];
    return;
  }
  find_path(root->left, target, data, data_idx + 1, path, path_idx);
  find_path(root->right, target, data, data_idx + 1, path, path_idx);
}

void k_level_data(struct TreeNode *root, int *data, int *idx, int k) {
  if (!root)
    return;
  if (!k) {
    data[*idx] = root->val;
    (*idx)++;
    return;
  }
  k_level_data(root->left, data, idx, k - 1);
  k_level_data(root->right, data, idx, k - 1);
}

int *distanceK(struct TreeNode *root, struct TreeNode *target, int k,
               int *return_size) {
  int *ans = malloc(100 * sizeof(int)), idx = 0;
  if (root == target) {
    k_level_data(root, ans, &idx, k);
    *return_size = idx;
    return ans;
  }
  int dep = depth(root);
  struct TreeNode **data = malloc((dep + 1) * sizeof(struct TreeNode *));
  struct TreeNode **path = malloc((dep + 1) * sizeof(struct TreeNode *));
  int data_idx = 0, path_idx = 0, a = 1;
  find_path(root, target, data, data_idx, path, &path_idx);
  k_level_data(target, ans, &idx, k);
  for (int i = path_idx - 2; i >= 0; i--) {
    if (!(k - a)) {
      ans[idx] = path[i]->val;
      idx++;
      break;
    }
    if (path[i]->left == path[i + 1])
      k_level_data(path[i]->right, ans, &idx, k - a - 1);
    else
      k_level_data(path[i]->left, ans, &idx, k - a - 1);
    a++;
  }
  *return_size = idx;
  return ans;
}
