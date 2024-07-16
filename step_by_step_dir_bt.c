// 2096. Step-By-Step Directions From a Binary Tree Node to Another
#include "leetcode.h"

/*
 * you are given the 'root' of a binary tree with 'n' nodes. each node is
 * uniquely assigned a value from 1 to 'n'. you are also given an integer
 * 'startValue' representing the value of the stat node 's', nd a different
 * integer 'destValue' representing the value of the destination node 't', find
 * the shortest path from node 's' to node 't'. generate step by step directions
 * of such path as a string consisting only of upper case letters L R and U,
 * return the step by step directions of the shortest path.
 */

void reverse_str(char *s) {
  int tmp;
  for (int i = 0; i < strlen(s) / 2; i++) {
    tmp = s[i];
    s[i] = s[strlen(s) - 1 - i];
    s[strlen(s) - 1 - i] = tmp;
  }
}

int find_node(struct TreeNode *root, int val, char *s) {
  if (!root)
    return 0;
  if (root->val == val)
    return 1;
  int res = find_node(root->left, val, s);
  if (res == 1) {
    strcat(s, "L");
    return 1;
  }
  res = find_node(root->right, val, s);
  if (res == 1) {
    strcat(s, "R");
    return 1;
  }
  return 0;
}

#define MAX_SZ 10001

char *getDirections(struct TreeNode *root, int startValue, int destValue) {
  char str_s[MAX_SZ] = "", str_d[MAX_SZ] = "";
  char *ans = (char *)malloc(MAX_SZ * sizeof(char));
  ans[0] = '\0';
  find_node(root, startValue, str_s);
  find_node(root, destValue, str_d);
  int s_idx = strlen(str_s) - 1, d_idx = strlen(str_d) - 1;
  while (s_idx >= 0 && d_idx >= 0) {
    if (str_s[s_idx] == str_d[d_idx]) {
      str_s[s_idx] = '\0';
      str_d[d_idx] = '\0';
      s_idx--, d_idx--;
    } else
      break;
  }
  for (int i = 0; i <= s_idx; i++)
    strcat(ans, "U");
  reverse_str(str_d);
  strcat(ans, str_d);
  return ans;
}

int main() {
  struct TreeNode *root = treenode_create(5);
  root->left = treenode_create(1);
  root->right = treenode_create(2);
  root->left->left = treenode_create(3);
  root->right->left = treenode_create(6);
  root->right->right->right = treenode_create(4);
  printf("%s\n", getDirections(root, 3, 6)); // expect: UURL
}
