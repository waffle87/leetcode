// 2385. Amount of Time for Binary Tree to Be Infected
#include "leetcode.h"

/*
 * given the 'root' of a binary tree with unique values, and an integer 'start'.
 * at minute 0, an infection starts from the node with value 'start' each
 * minute, a node becomes infected if the node is currently uninfected, or the
 * node is adjacent to an infected node. return the number of minutes needed for
 * the entire tree to be infected.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int depthAndFindVal(struct TreeNode *root, int val, bool *exist,
                    int *height_start) {
  if (!root)
    return -1;
  int height = 1 + fmax(depthAndFindVal(root->left, val, exist, height_start),
                        depthAndFindVal(root->right, val, exist, height_start));
  if (root->val == val) {
    *exist = true;
    *height_start = height;
  }
  return height;
}

int depth(struct TreeNode *root) {
  if (!root)
    return -1;
  return 1 + fmax(depth(root->left), depth(root->right));
}

void findPath(struct TreeNode *root, int start, struct TreeNode **data,
              int data_idx, struct TreeNode **path, int *path_idx) {
  if (!root)
    return;
  data[data_idx] = root;
  if (root->val == start) {
    *path_idx = data_idx + 1;
    for (int i = 0; i < *path_idx; i++)
      path[i] = data[i];
    return;
  }
  findPath(root->left, start, data, data_idx + 1, path, path_idx);
  findPath(root->right, start, data, data_idx + 1, path, path_idx);
}

int amountOfTime(struct TreeNode *root, int start) {
  bool left_exist = false, right_exist = false;
  int height_start = 0, data_idx = 0, path_idx = 0, ans;

  int left_height =
      depthAndFindVal(root->left, start, &left_exist, &height_start) + 1;
  int right_height =
      depthAndFindVal(root->right, start, &right_exist, &height_start) + 1;

  if (root->val == start)
    return fmax(left_height, right_height);

  int n = fmax(left_height, right_height);
  struct TreeNode **data = malloc(n * sizeof(struct TreeNode *));
  struct TreeNode **path = malloc(n * sizeof(struct TreeNode *));
  struct TreeNode *tmp = left_exist ? root->left : root->right;
  findPath(tmp, start, data, data_idx, path, &path_idx);
  ans = left_exist ? right_height + path_idx : left_height + path_idx;

  int start_height = depth(path[path_idx - 1]);
  ans = fmax(ans, start_height);
  int k = 1;
  for (int i = path_idx - 2; i >= 0; i--) {
    int d;
    if (path[i]->left == path[i + 1])
      d = depth(path[i]->right);
    else
      d = depth(path[i]->left);
    ans = fmax(ans, d + 1 + k);
    k++;
  }
  return ans;
}
