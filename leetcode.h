#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>
#include "lib/uthash/src/uthash.h"

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
#endif //__cplusplus

#define IS_ARRAY(value)                                                        \
  (!__builtin_types_compatible_p(typeof((value)), typeof(&(value)[0])))

#define ARRAY_SIZE(array)                                                      \
  (__builtin_choose_expr(IS_ARRAY((array)),                                    \
                         sizeof((array)) / sizeof((array)[0]), (void)0))

