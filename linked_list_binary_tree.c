// 1367. Linked List in Binary Tree
#include "leetcode.h"

/*
 * given a binary tree 'root' and a linked list with 'head' as the first node.
 * return true if all the elements in the linked list starting from the 'head'
 * correspond to some downward path connected in the binary tree otherwise
 * return false. in this context downward path means a path that starts at some
 * node and goes downwards.
 */

bool findSubPath(struct ListNode *head, struct TreeNode *root) {
  if (!head)
    return true;
  if (!root)
    return false;
  return head->val == root->val && (findSubPath(head->next, root->left) ||
                                    findSubPath(head->next, root->right));
}

bool isSubPath(struct ListNode *head, struct TreeNode *root) {
  if (!root)
    return false;
  return findSubPath(head, root) || isSubPath(head, root->left) ||
         isSubPath(head, root->right);
}

int main() {
  struct ListNode *head = listnode_create(1);
  head->next = listnode_create(4);
  head->next->next = listnode_create(2);
  head->next->next->next = listnode_create(6);
  struct TreeNode *root = treenode_create(1);
  root->left = treenode_create(4);
  root->right = treenode_create(4);
  root->left->right = treenode_create(2);
  root->right->left = treenode_create(2);
  root->left->right->left = treenode_create(1);
  root->right->left->left = treenode_create(6);
  root->right->left->right = treenode_create(8);
  root->right->left->right->left = treenode_create(1);
  root->right->left->right->right = treenode_create(3);
  printf("%d\n", isSubPath(head, root)); // expect: 1
}
