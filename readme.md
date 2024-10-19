## leetcode
This repository contains my Leetcode solutions for [user 0x6A73](https://leetcode.com/u/0x6A73).
the daily challenge is solved in both C and Python3, but there are also
some problems solved in C++ and Rust.

### notes
[`leetcode.h`](leetcode.h) contains various includes, standard leetcode
structs (`ListNode`, `TreeNode`), and some helpful macros, like
calculating the size of a C array using `builtin` functions.
```c
#define IS_ARRAY(value)                                                        \
  (!__builtin_types_compatible_p(typeof((value)), typeof(&(value)[0])))

#define ARRAY_SIZE(array)                                                      \
  (__builtin_choose_expr(IS_ARRAY((array)),                                    \
                         sizeof((array)) / sizeof((array)[0]), (void)0))
// ...
int res = func(arr, ARRAY_SIZE(arr));
```

[`leetcode.c`](leetcode.c) has helpful functions to fill `ListNode` and
`TreeNode` data structures with provided data, and also print data
returned by such functions. For example, see the following `main` functions.

**ListNode data type**

![image](https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png)
```c
int main() {
  // head = [0,3,1,0,4,5,2,0]
  struct ListNode *head = listnode_create(0);
  head->next = listnode_create(3);
  head->next->next = listnode_create(1);
  head->next->next->next = listnode_create(0);
  head->next->next->next->next = listnode_create(4);
  head->next->next->next->next->next = listnode_create(5);
  head->next->next->next->next->next->next = listnode_create(2);
  head->next->next->next->next->next->next->next = listnode_create(0);
  struct ListNode *res = func(head);
  listnode_print(res);
}
```

**TreeNode data type**

![image](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)
```c
int main() {
  // root = [3,9,20,null,null,15,7]
  struct TreeNode *root = treenode_create(3);
  root->left = treenode_create(9);
  root->right = treenode_create(20);
  root->right->left = treenode_create(15);
  root->right->right = treenode_create(7);
  struct TreeNode *res = func(root);
  treenode_print(res);
}
```

Also functions to aid in working with 2D C arrays:
```c
int func(int **edges, int edgesSize, int *edgesColSize);

int main() {
  // edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
  int edges_input[6][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
  struct two_d_arr edges;
  two_d_arr_init(&edges, 6, 2, edges_input);
  int res = func(edges.arr, edges.row_size, edges.col_size);
  two_d_arr_free(&edges);
}
```
