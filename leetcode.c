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
