#pragma once

#include "lib/uthash/src/uthash.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct two_d_arr {
  int row_size;
  int *col_size;
  int **arr;
};

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct Node {
  int val;
  int numChildren;
  struct Node **children;
};

struct two_d_arr *two_d_arr_init(int row_size, int col_size,
                                 int arr[row_size][col_size]);
void two_d_arr_free(struct two_d_arr *obj);

struct ListNode *listnode_create(int val);
struct ListNode *listnode_build(int *vals, int size);
void listnode_print(struct ListNode *head);
void listnode_free(struct ListNode *head);

struct TreeNode *treenode_create(int val);
struct TreeNode *treenode_build(int *vals, int size);
void treenode_print(struct TreeNode *root);
void treenode_free(struct TreeNode *root);

struct Node *node_create(int val, int numChildren);
void node_print(struct Node *root, int depth);
void node_free(struct Node *root);

#define IS_ARRAY(value)                                                        \
  (!__builtin_types_compatible_p(typeof((value)), typeof(&(value)[0])))

#define ARRAY_SIZE(array)                                                      \
  (__builtin_choose_expr(IS_ARRAY((array)),                                    \
                         sizeof((array)) / sizeof((array)[0]), (void)0))
