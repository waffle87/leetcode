// 652. Find Duplicate Subtrees
#include "./lib/uthash/src/uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given 'root' of a binary tree, return all duplicate subtrees. for each kind
 * of duplicate, only return the root node of any one of them. two trees are
 * duplicate if they have the same structure with the same node values.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct {
  char *r_key;
  int cnt;
  UT_hash_handle hh;
} h_elem;

char *dfs(struct TreeNode *root, h_elem **map, struct TreeNode **ans,
          int *idx) {
  h_elem *tmp;
  if (!root) {
    char *r = calloc(sizeof(char), 2);
    strcpy(r, "N");
    return r;
  }
  char *l_str = dfs(root->left, map, ans, idx);
  char *r_str = dfs(root->right, map, ans, idx);
  int c_len = strlen(l_str) + strlen(r_str) + 7;
  char *ans_str = calloc(sizeof(char), c_len);
  sprintf(ans_str, "%d, %s, %s\n", root->val, l_str, r_str);
  HASH_FIND_STR(*map, ans_str, tmp);
  if (tmp) {
    tmp->cnt++;
    if (tmp->cnt == 2)
      ans[(*idx)++] = root;
  } else {
    h_elem *tmp = malloc(sizeof(h_elem));
    tmp->r_key = ans_str;
    tmp->cnt = 1;
    HASH_ADD_KEYPTR(hh, *map, tmp->r_key, strlen(tmp->r_key), tmp);
  }
  return ans_str;
}

struct TreeNode **findDuplicateSubtrees(struct TreeNode *root,
                                        int *returnSize) {
  struct TreeNode **ans = malloc(sizeof(struct TreeNode *) * 250);
  *returnSize = 0;
  h_elem *map = NULL;
  dfs(root, &map, ans, returnSize);
  return ans;
}
