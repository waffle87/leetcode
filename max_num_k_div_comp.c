// 2872. Maximum Number of K-Divisible Components
#include "leetcode.h"

/*
 * there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1'. you are
 * given the integer 'n' and a 2d integer array 'edges' of length 'n - 1', where
 * 'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
 * and 'b_i' in the tree. you are also given a 0-indexed integer array 'values'
 * of length 'n' where 'values[i]' is the value associated with the i'th node
 * and an integer 'k'. a valid split of the tree is obtained by removing any set
 * of edges, possibly empty, from the tree such that the resulting components
 * all have values thatare divisible by 'k', where the value of a connected
 * component is the sum of the values of its node. return the maximum number of
 * components in any valid split
 */

struct vec {
  int *arr;
  int size;
};

void push(struct vec *a, int val) {
  a->arr = (int *)realloc(a->arr, (a->size + 1) * sizeof(int));
  a->arr[a->size] = val;
  ++a->size;
}

int dfs(int node, int parent, struct vec *adj, int *vals, int k, int *matches,
        int n) {
  int sum = 0, neighbour = adj[node].size;
  for (int i = 0; i < neighbour; ++i) {
    int n_node = adj[node].arr[i];
    if (n_node == parent)
      continue;
    sum += dfs(n_node, node, adj, vals, k, matches, n);
  }
  sum += vals[node];
  sum %= k;
  if (!sum)
    ++(*matches);
  return sum;
}

int maxKDivisibleComponents(int n, int **edges, int edgesSize,
                            int *edgesColSize, int *values, int valuesSize,
                            int k) {
  struct vec *adj = (struct vec *)malloc(n * sizeof(struct vec));
  for (int i = 0; i < n; ++i)
    adj[i] = (struct vec){(int *)malloc(0 * sizeof(int)), 0};
  for (; edgesSize; ++edges, --edgesSize) {
    int first = (*edges)[0], second = (*edges)[1];
    push(adj + first, second);
    push(adj + second, first);
  }
  int matches = 0;
  dfs(0, -1, adj, values, k, &matches, n);
  return matches;
}

int main() {
  int e1i[4][2] = {{0, 2}, {1, 2}, {1, 3}, {2, 4}}, v1[] = {1, 8, 1, 4, 4};
  int e2i[6][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}},
      v2[] = {3, 0, 6, 1, 5, 2, 1};
  struct two_d_arr *e1 = two_d_arr_init(4, 2, e1i);
  struct two_d_arr *e2 = two_d_arr_init(6, 2, e2i);
  printf("%d\n", maxKDivisibleComponents(5, e1->arr, e1->row_size, e1->col_size,
                                         v1, ARRAY_SIZE(v1), 6)); // expect: 2
  printf("%d\n", maxKDivisibleComponents(7, e2->arr, e2->row_size, e2->col_size,
                                         v2, ARRAY_SIZE(v2), 3)); // expect: 2
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
