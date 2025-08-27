## Leetcode

This repository contains my Leetcode solutions for [user 0x6A73](https://leetcode.com/u/0x6A73). Generally, the daily challenge is solved in both C and Python3.

### Notes

The [`leetcode.h`](leetcode.h) header file contains various includes, standard Leetcode structs (`ListNode`, `TreeNode`), and some helpful macros, like calculating the size of a C array using `builtin` functions.
```c
#define IS_ARRAY(value)                                                        \
  (!__builtin_types_compatible_p(typeof((value)), typeof(&(value)[0])))

#define ARRAY_SIZE(array)                                                      \
  (__builtin_choose_expr(IS_ARRAY((array)),                                    \
                         sizeof((array)) / sizeof((array)[0]), (void)0))

// foo.c
int arr[] = {1, 2, 3};
int foo = func(arr, ARRAY_SIZE(arr));
```

The [`leetcode.c`](leetcode.c) file has helpful functions to fill `ListNode` and `TreeNode` data structures with provided data, and also print data returned by such functions. For examples, see the following `main` functions.

#### `ListNode` data type

![image](https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png)

```c
int main() {
    int input[] = {0, 3, 1, 0, 4, 5, 2, 0};
    struct ListNode *head = listnode_build(input, ARRAY_SIZE(input));
    listnode_print(head);
}
```

#### `TreeNode` data type

![image](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

```c
int main() {
    int input[] = {3, 9, 20, -1, -1, 15, 7};
    // note: -1 denotes a 'null' leaf. if a problem's input depends on
    // this value, use treenode_create() to individually create each node
    struct TreeNode *root = treenode_build(input, ARRAY_SIZE(input));
    treenode_print(root);
}
```

#### 2D Array Helpers

```c
int func(int **edges, int edgesSize, int *edgesColSize);

int main() {
  // edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
  int edges_input[6][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
  struct two_d_arr *edges = two_d_arr_init(ARRAY_SIZE(edges_input), ARRAY_SIZE(edges_input[0]), edges_input);
  int res = func(edges.arr, edges.row_size, edges.col_size);
  two_d_arr_free(edges);
}
```
