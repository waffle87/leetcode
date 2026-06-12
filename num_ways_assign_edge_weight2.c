// 3559. Number of Ways to Assign Edge Weights II
#include "leetcode.h"

/*
 * there is an undirected tree with 'n' nodes labeled from 1 to 'n', rooted at
 * node 1. the tree is represented by a 2d integer array 'edges' of length 'n -
 * 1', where 'edges[i] = [ui, vi]' indicates that there is an edge between nodes
 * 'ui' and 'vi'. return an array 'answer' where 'answer[i]' is the number of
 * valid assignments for 'queries[i]'. since the answer may be very large, apply
 * modulo 10^9+7 to each 'answer[i]'.
 */

struct node {
  int val;
  struct node *next;
};

void add_edge(struct node **adj, int u, int v) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->val = v;
  node->next = adj[u];
  adj[u] = node;
}

int lca(int u, int v, int **up, int *depth, int log) {
  if (depth[u] < depth[v]) {
    int temp = u;
    u = v;
    v = temp;
  }
  int diff = depth[u] - depth[v];
  for (int k = 0; k < log; k++) {
    if ((diff >> k) & 1)
      u = up[k][u];
  }
  if (u == v)
    return u;
  for (int k = log - 1; k >= 0; k--)
    if (up[k][u] != up[k][v]) {
      u = up[k][u];
      v = up[k][v];
    }
  return up[0][u];
}

int *assignEdgeWeights(int **edges, int edgesSize, int *edgesColSize,
                       int **queries, int queriesSize, int *queriesColSize,
                       int *returnSize

) {
  int n = edgesSize + 1, mod = 1e9 + 7;
  struct node **adj = (struct node **)calloc(n + 1, sizeof(struct node *));
  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0], v = edges[i][1];
    add_edge(adj, u, v);
    add_edge(adj, v, u);
  }
  int *depth = (int *)calloc(n + 1, sizeof(int));
  int *parent = (int *)calloc(n + 1, sizeof(int));
  int *vis = (int *)calloc(n + 1, sizeof(int));
  int *queue = (int *)malloc((n + 1) * sizeof(int));
  int front = 0, back = 0;
  queue[back++] = 1;
  vis[1] = 1;
  while (front < back) {
    int node = queue[front++];
    for (struct node *cur = adj[node]; cur != NULL; cur = cur->next) {
      int neighbour = cur->val;
      if (!vis[neighbour]) {
        vis[neighbour] = 1;
        depth[neighbour] = depth[node] + 1;
        parent[neighbour] = node;
        queue[back++] = neighbour;
      }
    }
  }
  int log = 1;
  while ((1 << log) <= n)
    log++;
  int **up = (int **)malloc(log * sizeof(int *));
  for (int k = 0; k < log; k++)
    up[k] = (int *)calloc(n + 1, sizeof(int));
  for (int v = 0; v <= n; v++)
    up[0][v] = parent[v];
  for (int k = 1; k < log; k++)
    for (int v = 0; v <= n; v++)
      up[k][v] = up[k - 1][up[k - 1][v]];
  int *pow2 = (int *)malloc((n + 1) * sizeof(int));
  pow2[0] = 1;
  for (int i = 1; i <= n; i++)
    pow2[i] = (long long)pow2[i - 1] * 2 % mod;
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; i++) {
    int u = queries[i][0], v = queries[i][1];
    int ancestor = lca(u, v, up, depth, log);
    int dist = depth[u] + depth[v] - 2 * depth[ancestor];
    ans[i] = dist ? pow2[dist - 1] : 0;
  }
  return ans;
}

int main() {
  int e1i[1][2] = {{1, 2}};
  int q1i[2][2] = {{1, 1}, {1, 2}};
  int e2i[4][2] = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  int q2i[3][2] = {{1, 4}, {3, 4}, {2, 5}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int rs1, r1[] = {0, 1}, rs2, r2[] = {2, 1, 4};
  int *aew1 = assignEdgeWeights(e1->arr, e1->row_size, e1->col_size, q1->arr,
                                q1->row_size, q1->col_size, &rs1);
  int *aew2 = assignEdgeWeights(e2->arr, e2->row_size, e2->col_size, q2->arr,
                                q2->row_size, q2->col_size, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", aew1[i]);
    assert(aew1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", aew2[i]);
    assert(aew2[i] == r2[i]);
  }
  printf("\n");
  free(aew1);
  free(aew2);
  two_d_arr_free(e1);
  two_d_arr_free(q1);
  two_d_arr_free(e2);
  two_d_arr_free(q2);
}
