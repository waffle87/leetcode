// 988. Smallest String Starting From Leaf
#include "leetcode.h"

/*
 * given the 'root' of a binary tree where each node has a value in the range
 * '[0, 25]' representing letters 'a' to 'z'. return the lexicographically
 * smallest string that starts at a leaf of this tree and ends at the root. as a
 * reminder, any shorter prefix of a string is lexicographically smaller. a leaf
 * of a node is a node that has no children.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *createNode(int val) {
  struct TreeNode *new_node =
      (struct TreeNode *)malloc(sizeof(struct TreeNode));
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

int depth(struct TreeNode *root) {
  return !root ? 0 : fmax(depth(root->left), depth(root->right)) + 1;
}

void process(struct TreeNode *root, int *small, char *res, char *data,
             int idx) {
  if (!root)
    return;
  data[idx] = root->val + 'a';
  idx++;
  if (!root->left && !root->right) {
    data[idx] = '\0';
    if (root->val < *small) {
      strcpy(res, data);
      *small = root->val;
    } else if (root->val == *small) {
      int l_a = strlen(res) - 1, l_d = strlen(data) - 1;
      while (l_a >= 0 && l_d >= 0) {
        if (data[l_d] < res[l_a]) {
          strcpy(res, data);
          break;
        }
        if (data[l_d] > res[l_d])
          break;
        if (!l_d) {
          strcpy(res, data);
          break;
        }
        l_a--, l_d--;
      }
    }
  }
  process(root->left, small, res, data, idx);
  process(root->right, small, res, data, idx);
}

char *smallestFromLeaf(struct TreeNode *root) {
  int d = depth(root), small = 27;
  char *data = calloc(d + 1, sizeof(char));
  char *ans = calloc(d + 1, sizeof(char));
  process(root, &small, ans, data, 0);
  int n = strlen(ans);
  for (int i = 0; i < n / 2; i++) {
    char tmp = ans[i];
    ans[i] = ans[n - i - 1];
    ans[n - i - 1] = tmp;
  }
  return ans;
}

int main() {
  struct TreeNode *root = createNode(0);
  root->left = createNode(1);
  root->right = createNode(2);
  root->left->left = createNode(3);
  root->left->right = createNode(4);
  root->right->left = createNode(3);
  root->right->right = createNode(4);
  printf("%s\n", smallestFromLeaf(root));
}
