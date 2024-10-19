#include "lib/uthash/src/uthash.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

#ifdef __cplusplus
#include <bits/stdc++.h>
using namespace std;

#define vvd(data) vector<vector<data>>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Node {
public:
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val) { val = _val; }
  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
#else //__cplusplus

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

void two_d_arr_init(struct two_d_arr *obj, int row_size, int col_size,
                    int arr[row_size][col_size]);
void two_d_arr_free(struct two_d_arr *obj);

struct ListNode *listnode_create(int val);
void listnode_print(struct ListNode *head);
void listnode_free(struct ListNode *head);

struct TreeNode *treenode_create(int val);
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
#endif
