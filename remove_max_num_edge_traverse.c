// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
#include "leetcode.h"

/*
 * alice and bob have an undirected graph of 'n' nodes and three
 * types of edges:
 * type1: can be traversed by alice only
 * type2: can be traversed by bob only
 * type3: can be traversed by both alice and bob
 * given an array of 'edges' where 'edges{i} = {typei, ui, vi}'
 * represents a bidirectional edge of type 'typei' between nodes
 * 'ui' and 'vi', find the maximum number of edges you can remove
 * so that after removing the edges, the graph can still be fully
 * traversed by alice and bob if starting from any node, they can
 * reach all other nodes. return the maximum number of edges you
 * can remove, or return -1 if alice and bob cannot traverse graph
 */

int find(int *n, int target) {
  return n[target] < 0 ? target : (n[target] = find(n, n[target]));
}

int connect(int *n, int x, int y) {
  int a = find(n, x), b = find(n, y);
  if (a == b)
    return 0;
  if (n[a] > n[b])
    n[a] = b;
  else if (n[b] > n[a])
    n[b] = a;
  else {
    n[a] = b;
    n[b]--;
  }
  return 1;
}

int maxNumEdgesToRemove(int n, int **edges, int edgesSize, int *edgesColSize) {
  int e = 0, f = 0, g = 0, b = n, c = n, d = n;
  int *p = (int *)malloc(n * sizeof(*p));
  int *q = (int *)malloc(n * sizeof(*q));
  int *r = (int *)malloc(n * sizeof(*r));
  for (int i = 0; i < n; ++i)
    p[i] = q[i] = r[i] = -1;
  for (int i = 0; i < edgesSize; i++) {
    int t = edges[i][0], u = edges[i][1] - 1, v = edges[i][2] - 1;
    if (t != 1) {
      e++;
      b -= connect(p, u, v);
    }
    if (t != 2) {
      f++;
      d -= connect(q, u, v);
    }
    if (t == 3) {
      g++;
      d -= connect(r, u, v);
    }
  }
  free(p), free(q), free(r);
  return b > 1 || c > 1 ? -1 : e + f - g + b + c - d - n;
}

int main() {
  int e1[6][3] = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3},
                  {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
  int e2[4][3] = {{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}};
  int e3[3][3] = {{3, 2, 3}, {1, 1, 2}, {2, 3, 4}};
  int ecs1[] = {6, 6, 6}, ecs2[] = {4, 4, 4}, ecs3[] = {3, 3, 3};
  printf("%d\n", maxNumEdgesToRemove(4, (int **)e1, ARRAY_SIZE(e1),
                                     (int *)ARRAY_SIZE(e1[0]))); // expect: 2
  printf("%d\n", maxNumEdgesToRemove(4, (int **)e2, ARRAY_SIZE(e2),
                                     (int *)ARRAY_SIZE(e2[0]))); // expect: 0
  printf("%d\n", maxNumEdgesToRemove(4, (int **)e3, ARRAY_SIZE(e3),
                                     (int *)ARRAY_SIZE(e3[0]))); // expect: -1
}
