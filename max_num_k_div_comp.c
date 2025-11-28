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

struct node {
  int val;
  struct node *next;
};

struct tree {
  struct node **adj;
  int *vals;
  int n;
  int ans;
};

struct node *node_init(int val) {
  struct node *obj = (struct node *)malloc(sizeof(struct node));
  obj->val = val;
  obj->next = NULL;
  return obj;
}

void add_edge(struct tree *obj, int u, int v) {
  struct node *n1 = node_init(v), *n2 = node_init(u);
  n1->next = obj->adj[u];
  obj->adj[u] = n1;
  n2->next = obj->adj[v];
  obj->adj[v] = n2;
}

long long dfs(int node, int *vals, bool *vis, struct tree *t, int k) {
  if (vis[node])
    return 0;
  vis[node] = true;
  long long sum = vals[node];
  struct node *neighbour = t->adj[node];
  while (neighbour) {
    sum += dfs(neighbour->val, vals, vis, t, k);
    neighbour = neighbour->next;
  }
  if (!(sum % k)) {
    t->ans++;
    return 0;
  }
  return sum;
}

int maxKDivisibleComponents(int n, int **edges, int edgesSize,
                            int *edgesColSize, int *values, int valuesSize,
                            int k) {
  struct tree t;
  t.n = n;
  t.vals = values;
  t.ans = 0;
  t.adj = (struct node **)malloc(n * sizeof(struct node *));
  for (int i = 0; i < n; i++)
    t.adj[i] = NULL;
  // memset(t.adj, NULL, n * sizeof(struct node));
  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0], v = edges[i][1];
    add_edge(&t, u, v);
  }
  bool *vis = (bool *)calloc(n, sizeof(bool));
  dfs(0, values, vis, &t, k);
  free(vis);
  for (int i = 0; i < n; i++) {
    struct node *tmp = t.adj[i];
    while (tmp) {
      struct node *del = tmp;
      tmp = tmp->next;
      free(del);
    }
  }
  free(t.adj);
  return t.ans;
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
