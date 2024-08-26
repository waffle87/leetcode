#include "leetcode.h"

struct ListNode *listnode_create(int val) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = val;
  new->next = NULL;
  return new;
}

void listnode_print(struct ListNode *head) {
  struct ListNode *curr = head;
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}

void listnode_free(struct ListNode *head) {
  struct ListNode *tmp;
  while (head) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

struct TreeNode *treenode_create(int val) {
  struct TreeNode *new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  new->val = val;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void treenode_print(struct TreeNode *root) {
  if (!root)
    return;
  treenode_print(root->left);
  printf("%d ", root->val);
  treenode_print(root->right);
}

void treenode_free(struct TreeNode *root) {
  if (!root)
    return;
  treenode_free(root->left);
  treenode_free(root->right);
  free(root);
}

struct Node *node_create(int val, int numChildren) {
  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->val = val;
  new->numChildren = numChildren;
  if (numChildren) {
    new->children = (struct Node **)malloc(numChildren * sizeof(struct Node *));
    for (int i = 0; i < numChildren; i++)
      new->children[i] = NULL;
  } else
    new->children = NULL;
  return new;
}

void node_print(struct Node *root, int depth) {
  if (!root)
    return;
  printf("%d\n", root->val);
  for (int i = 0; i < root->numChildren; i++)
    node_print(root->children[i], depth + 1);
}

void node_free(struct Node *root) {
  if (!root)
    return;
  for (int i = 0; i < root->numChildren; i++)
    node_free(root->children[i]);
  free(root->children);
  free(root);
}
