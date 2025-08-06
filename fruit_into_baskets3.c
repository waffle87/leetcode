// 3479. Fruits Into Baskets III
#include "leetcode.h"

/*
 * you are given two arrays of integers, 'fruits' and 'baskets', each of length
 * 'n', where 'fruits[i]' represents the quantity of the i'th type of fruit, and
 * 'baskets[j]' represents the capacity of the j'th basket. from left to right,
 * place the fruits according to these rules: each fruit type must be placed in
 * the leftmost available basket with a capacity greater than equal to the
 * quantity of that fruit type. return the number of fruit types that remain
 * unplaced after all possible allocations are made.
 */

struct node {
  int val;
  struct node *parent;
  struct node *left_child;
  struct node *right_child;
};

int tree_size(int n) {
  return 1 << (32 - __builtin_clz(n) +
               (__builtin_clz(n) + __builtin_clz(n) < 31));
}

int tree_init(struct node *tree, struct node *parent, int icurr, int *data,
              int left, int right) {
  struct node *curr = &tree[icurr];
  curr->parent = parent;
  if (left == right) {
    curr->left_child = 0;
    curr->right_child = 0;
    return curr->val = data[left];
  } else {
    int i_left_child = icurr * 2 + 1, i_right_child = i_left_child + 1,
        mid = (left + right) / 2;
    curr->left_child = &tree[i_left_child];
    curr->right_child = &tree[i_right_child];
    int val_left_child = tree_init(tree, curr, i_left_child, data, left, mid);
    int val_right_child =
        tree_init(tree, curr, i_right_child, data, mid + 1, right);
    return curr->val = fmax(val_left_child, val_right_child);
  }
}

void set_node_val(struct node *obj, int val) {
  obj->val = val;
  if (obj->parent) {
    struct node *curr = obj->parent;
    int new = fmax(curr->left_child->val, curr->right_child->val);
    if (new != obj->val)
      set_node_val(curr, new);
  }
}

struct node *left_node(struct node *tree, const int min) {
  struct node *curr = &tree[0];
  while (curr->left_child) {
    if (curr->left_child->val >= min)
      curr = curr->left_child;
    else
      curr = curr->right_child;
  }
  return curr;
}

int numOfUnplacedFruits(int *fruits, int fruitsSize, int *baskets,
                        int basketsSize) {
  int ans = 0, n = tree_size(basketsSize);
  struct node *tree = (struct node *)malloc(n * sizeof(struct node));
  tree_init(tree, (struct node *)0, 0, baskets, 0, basketsSize - 1);
  for (int i = 0; i < fruitsSize; i++) {
    if (tree[0].val >= fruits[i])
      set_node_val(left_node(tree, fruits[i]), 0);
    else
      ans++;
  }
  free(tree);
  return ans;
}

int main() {
  int f1[] = {4, 2, 5}, b1[] = {3, 5, 4};
  int f2[] = {3, 6, 1}, b2[] = {6, 4, 7};
  printf("%d\n", numOfUnplacedFruits(f1, ARRAY_SIZE(f1), b1,
                                     ARRAY_SIZE(b1))); // expect: 1
  printf("%d\n", numOfUnplacedFruits(f2, ARRAY_SIZE(f2), b2,
                                     ARRAY_SIZE(b2))); // expect: 0
}
