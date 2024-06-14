// 662. Maximum Width of Binary Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given 'root' of binary tree, return the maximum width of the
 * given tree. the maximum width of a tree is the maximum width
 * among all levels. the width of one level is defined as the
 * length between the end-nodes (the leftmost and rightmost non
 * null nodes), where the null nodes between the end-nodes that
 * would be present in a complete binary tree extending down to
 * that level are also counted into the length calculation.
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef enum {
  QUEUELINK_OK,
  QUEUELINK_EMPTY,
  QUEUELINK_FULL,
  QUEUELINK_ERROR = 0xFF
} queue_link;

#define QUEUELINK_DEFINE(type)                                                 \
  typedef struct _queuelink_node_##type##_t {                                  \
    struct _queuelink_node_##type##_t *next;                                   \
    type value;                                                                \
  } queuelink_node_##type##_t;                                                 \
  typedef struct _queuelink_struct##type##_t {                                 \
    queuelink_node_##type##_t *head;                                           \
    queuelink_node_##type##_t *tail;                                           \
    int count;                                                                 \
  } queuelink_##type##_t;                                                      \
  queuelink_er_em offer_queuelink_##type(queuelink_##type##_t *queuelink,      \
                                         type *tdata) {                        \
    if (tdata == NULL)                                                         \
      return QUEUELINK_ERROR;                                                  \
    queuelink_node_##type##_t *node = (queuelink_node_##type##_t *)malloc(     \
        sizeof(queuelink_node_##type##_t));                                    \
    node->next = NULL;                                                         \
    memcpy(&node->value, tdata, sizeof(type));                                 \
    if (queuelink->head == NULL) {                                             \
      queuelink->head = node;                                                  \
      queuelink->tail = node;                                                  \
    } else {                                                                   \
      queuelink->tail->next = node;                                            \
      queuelink->tail = node;                                                  \
    }                                                                          \
    queuelink->count++;                                                        \
    return QUEUELINK_OK;                                                       \
  }                                                                            \
  queuelink_er_em poll_queuelink_##type(queuelink_##type##_t *queuelink,       \
                                        type *rdata) {                         \
    if (queuelink->head == NULL)                                               \
      return QUEUELINK_EMPTY;                                                  \
    memcpy(rdata, &queuelink->head->value, sizeof(type));                      \
    queuelink_node_##type##_t *tmp = queuelink->head;                          \
    queuelink->head = queuelink->head->next;                                   \
    free(tmp);                                                                 \
    queuelink->count--;                                                        \
    return QUEUELINK_OK;                                                       \
  }                                                                            \
  inline int get_queuelink_size_##type(queuelink_##type##_t *queuelink_) {     \
    return queuelink_->count;                                                  \
  }

typedef struct TreeNode node_data;
QUEUELINK_DEFINE(node_data);

int widthOfBinaryTree(struct TreeNode *root) {
  queuelink_node_data_t q = {.head = NULL, .tail = NULL, .count = 0};
  offer_queuelink_node_data(&q, root);
  long left = 0, right = 0;
  node_data tmp;
  int ans = 0;
  while (1) {
    int counts = get_queuelink_size_node_data(&q);
    if (!counts)
      break;
    for (int i = 0; i < counts; i++) {
      poll_queuelink_node_data(&q, &tmp);
      if (!i)
        left = tmp.val;
      right = tmp.val;
      if (tmp.left != NULL) {
        tmp.left->val = tmp.val * 2L;
        offer_queuelink_node_data(&q, tmp.left);
      }
      if (tmp.right != NULL) {
        tmp.right->val = tmp.val * 2L + 1;
        offer_queuelink_node_data(&q, tmp.right);
      }
      int tmp_ans = right - left + 1;
      if (ans < tmp_ans)
        ans = tmp_ans;
    }
  }
  return ans;
}
