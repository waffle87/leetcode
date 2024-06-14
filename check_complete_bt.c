// 958. Check Completeness of a Binary Tree
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * given 'root' of binary tree, determine if it is a complete binary tree. in a
 * completely filled binary tree, every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. it can have between 1 and 2^h nodes inclusive at the last level h.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct {
  struct TreeNode *queue_arr[200];
  int begin;
  int end;
} queue;

int is_queue_empty(queue *tmp) { return tmp->begin == -1 ? 1 : 0; }

int is_queue_full(queue *tmp) { return tmp->end == 199 ? 1 : 0; }

void enqueue(queue *tmp, struct TreeNode *element) {
  if (is_queue_full(tmp))
    return;
  tmp->queue_arr[++(tmp->end)] = element;
  if (tmp->begin == -1)
    tmp->begin = 0;
  // return;
}

struct TreeNode *dequeue(queue *tmp) {
  if (is_queue_empty(tmp))
    return NULL;
  struct TreeNode *res = tmp->queue_arr[tmp->begin];
  if (tmp->begin == tmp->end) {
    tmp->begin = -1;
    tmp->end = -1;
  } else
    ++(tmp->begin);
  return res;
}

bool isCompleteTree(struct TreeNode *root) {
  int *arr = (int *)malloc(sizeof(int) * 200), arr_idx = 0;
  struct TreeNode *tmp_ptr = root;
  queue tmp_q;
  tmp_q.begin = -1;
  tmp_q.end = -1;
  enqueue(&tmp_q, tmp_ptr);
  bool match = true, no_child = false;
  while (!is_queue_empty(&tmp_q)) {
    tmp_ptr = dequeue(&tmp_q);
    if (tmp_ptr == NULL) {
      no_child = true;
      continue;
    }
    if (no_child == true && tmp_ptr != NULL) {
      match = false;
      break;
    }
    if (tmp_ptr->left != NULL && tmp_ptr->right != NULL) {
      enqueue(&tmp_q, tmp_ptr->left);
      enqueue(&tmp_q, tmp_ptr->right);
    } else if (tmp_ptr->left != NULL && tmp_ptr->right == NULL) {
      enqueue(&tmp_q, tmp_ptr->left);
      enqueue(&tmp_q, NULL);
    } else if (tmp_ptr->left == NULL && tmp_ptr->right != NULL) {
      match = false;
      break;
    } else {
      enqueue(&tmp_q, NULL);
      enqueue(&tmp_q, NULL);
    }
  }
  return match;
}
