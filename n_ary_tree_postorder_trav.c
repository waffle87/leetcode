// 590. N-ary Tree Postorder Traversal
#include "leetcode.h"

/*
 * given the 'root' of an n-ary tree, return the postorder traversal of its
 * nodes' values. nary-tree input serialisation is represented in their level
 * order traversal. each group of children is separated by the null value.
 */

void *post_vis(struct Node *root, int *n, int *idx) {
  int i = 0, cnt[1000] = {0};
  struct Node *prev[1000];
  prev[i++] = NULL;
  while (root) {
    if (root->numChildren == cnt[i]) {
      n[(*idx)++] = root->val;
      cnt[i--] = 0;
      root = prev[i];
    } else {
      prev[i] = root;
      root = root->children[cnt[i++]++];
    }
  }
  return NULL;
}

int *postorder(struct Node *root, int *returnSize) {
  int *n = (int *)calloc(10000, sizeof(int)), idx = 0;
  post_vis(root, n, &idx);
  *returnSize = idx;
  return n;
}

int main() {
  struct Node *root = node_create(1, 3);
  root->children[0] = node_create(3, 2);
  root->children[1] = node_create(2, 0);
  root->children[2] = node_create(4, 0);
  root->children[0]->children[0] = node_create(5, 0);
  root->children[0]->children[1] = node_create(6, 0);
  int rs, *p = postorder(root, &rs);
  for (int i = 0; i < rs; i++)
    printf("%d ", p[i]); // expect: 5 6 3 2 4 1
  free(p);
}
