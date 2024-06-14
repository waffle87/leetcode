// 109. Convert Sorted List to Binary Search Tree
#include <stdlib.h>

/*
 * given 'head' of a singly linked list where elements are sorted in ascending
 * order convert it to a height balanced binary search tree. meaning the depth
 * of two sub- trees of every node never differs by more than one.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int list_len(struct ListNode *head) {
  struct ListNode *tmp = head;
  int cnt = 0;
  while (tmp)
    cnt++, tmp = tmp->next;
  return cnt;
}

struct TreeNode *sortedArrayToBST(int *nums, int n) {
  if (n <= 0)
    return NULL;
  struct TreeNode *root = malloc(sizeof(struct TreeNode));
  if (n == 1) {
    root->val = nums[0];
    root->left = NULL;
    root->right = NULL;
  } else {
    root->val = nums[n / 2];
    root->left = sortedArrayToBST(nums, n / 2);
    root->right = sortedArrayToBST(&nums[n / 2 + 1], n - 1 - n / 2);
  }
  return root;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
  int n = list_len(head);
  if (n == 0)
    return NULL;
  int *nums = malloc(n * sizeof(int));
  struct ListNode *tmp = head;
  for (int i = 0; i < n; i++) {
    nums[i] = tmp->val;
    tmp = tmp->next;
  }
  return sortedArrayToBST(nums, n);
}
