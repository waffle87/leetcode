// 2685. Count the Number of Complete Components
#include "leetcode.h"

/*
 * you are given an integer 'n'. there is an undirected graph with 'n' vertices,
 * numbered from 0 to 'n - 1'. you are given a 2d integer array 'edges' where
 * 'edges[i] = [a_i, b_i]' denotes that there exists an undirected edge
 * connecting vertices 'a_i' and 'b_i'. return the number of complete connected
 * components of the graph. a connected component is a subgraph of a graph in
 * which there exists a path between any two vertices and no vertex of the
 * subgraph shares an edge with a vertex outside of the subgraph. a connected
 * component is said to be complete if there exists an edge between every pair
 * of its vertices
 */

struct disjoint_set {
  int *parent;
  int *node_cnt;
  int *edge_cnt;
};

int get_root(struct disjoint_set *set, int node) {
  if (set->parent[node] == node)
    return node;
  return set->parent[node] = get_root(set, set->parent[node]);
}

int countCompleteComponents(int n, int **edges, int edgesSize,
                            int *edgesColSize) {
  int cnt = 0;
  struct disjoint_set *set =
      (struct disjoint_set *)malloc(sizeof(struct disjoint_set));
  set->parent = (int *)malloc(n * sizeof(int));
  set->node_cnt = (int *)malloc(n * sizeof(int));
  set->edge_cnt = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    set->parent[i] = i;
    set->node_cnt[i] = 1;
  }
  for (int i = 0; i < edgesSize; i++) {
    int root, descendant;
    if (get_root(set, edges[i][0]) < get_root(set, edges[i][1])) {
      root = set->parent[edges[i][0]];
      descendant = set->parent[edges[i][1]];
    } else {
      root = set->parent[edges[i][1]];
      descendant = set->parent[edges[i][0]];
    }
    if (root == descendant) {
      set->edge_cnt[root]++;
      continue;
    }
    set->edge_cnt[root] += 1 + set->edge_cnt[descendant];
    set->node_cnt[root] += set->node_cnt[descendant];
    set->parent[descendant] = root;
  }
  for (int i = 0; i < n; i++)
    if (set->parent[i] == i)
      if (set->edge_cnt[i] == (set->node_cnt[i] * (set->node_cnt[i] - 1)) / 2)
        cnt++;
  free(set->parent);
  free(set->node_cnt);
  free(set->edge_cnt);
  free(set);
  return cnt;
}

int main() {
  int e1i[4][2] = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
  int e2i[5][2] = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  int r1 = countCompleteComponents(6, e1->arr, e1->row_size, e1->col_size);
  int r2 = countCompleteComponents(6, e2->arr, e2->row_size, e2->col_size);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 1);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
