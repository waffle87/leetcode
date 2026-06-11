// 3558. Number of Ways to Assign Edge Weights I
#include "leetcode.h"

/*
 * there is an undirected tree with 'n' nodes labeed from 1 to 'n', rooted at
 * node 1. the tree is represented by a 2d integer array 'edges' of length 'n -
 * 1' where 'edges[i] = [ui, vi]' indicates that there is an edge between nodes
 * 'ui' and 'vi'. initially, all edges have a weight of 0. you must assign each
 * edge a weight of either 1 or 2. the cost of a path between any two nodes 'u'
 * and 'v' is the total weight of all edges in the path connecting them. select
 * any one node 'x'at the maximum depth. return the number of ways to assign
 * edge weights in the path from node 1 to 'x' such that its total cost is odd.
 * since the answer may be large, return it modulo 10^9 + 7. note: ignore all
 * edges not in the path from node 1 to 'x'.
 */

struct node {
  int val;
  struct node *next;
};

struct graph {
  struct node **heads;
  int size;
};

void add_edge(struct graph *g, int u, int v) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->val = v;
  n->next = g->heads[u];
  g->heads[u] = n;
}

int qpow(int x, int y) {
  static int mod = 1e9 + 7;
  long long res = 1, base = x;
  while (y) {
    if (y & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    y >>= 1;
  }
  return (int)res;
}

int dfs(struct graph *g, int x, int f) {
  int max_depth = 0;
  struct node *curr = g->heads[x];
  while (curr) {
    int y = curr->val;
    if (y != f)
      max_depth = fmax(max_depth, dfs(g, y, x) + 1);
    curr = curr->next;
  }
  return max_depth;
}

int assignEdgeWeights(int **edges, int edgesSize, int *edgesColSize) {
  int n = edgesSize + 1;
  struct graph g = {(struct node **)calloc(n + 1, sizeof(struct node *)),
                    n + 1};
  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0], v = edges[i][1];
    add_edge(&g, u, v);
    add_edge(&g, v, u);
  }
  int max_depth = dfs(&g, 1, 0);
  int ans = qpow(2, max_depth - 1);
  for (int i = 0; i <= n; i++) {
    struct node *curr = g.heads[i];
    while (curr) {
      struct node *tmp = curr;
      curr = curr->next;
      free(tmp);
    }
  }
  free(g.heads);
  return ans;
}

int main() {
  int e1i[1][2] = {{1, 2}}, e2i[4][2] = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  int r1 = assignEdgeWeights(e1->arr, e1->row_size, e1->col_size);
  int r2 = assignEdgeWeights(e2->arr, e2->row_size, e2->col_size);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
