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

int countCompleteComponents(int n, int **edges, int edgesSize,
                            int *edgesColSize) {
  int *vertices = (int *)calloc(n, sizeof(int));
  int *edge_cnt = (int *)calloc(n, sizeof(int));
  int *vert_cnt = (int *)calloc(n, sizeof(int));
  int group = 1, ans = 0;
  for (int i = 0; i < edgesSize; i++) {
    int v1 = edges[i][0];
    int v2 = edges[i][1];
    if (!(vertices[v1] + vertices[v2])) {
      vertices[v1] = vertices[v2] = group;
      edge_cnt[group] = 2;
      vert_cnt[group++] = 1;
    } else if (!vertices[v1]) {
      vertices[v1] = vertices[v2];
      ++edge_cnt[vertices[v2]];
      ++vert_cnt[vertices[v2]];
    } else if (!vertices[v2]) {
      vertices[v2] = vertices[v1];
      ++edge_cnt[vertices[v1]];
      ++vert_cnt[vertices[v1]];
    } else if (vertices[v1] == vertices[v2])
      ++vert_cnt[vertices[v1]];
    else {
      vert_cnt[vertices[v1]] += vert_cnt[vertices[v2]] + 1;
      edge_cnt[vertices[v1]] += edge_cnt[vertices[v2]];
      edge_cnt[vertices[v2]] = vert_cnt[vertices[v2]] = 0;
      for (int i = 0; i < n; i++)
        if (vertices[i] == vertices[v2])
          vertices[i] = vertices[v1];
    }
  }
  int connect_cnt = 0;
  for (int i = 1; i < group; i++) {
    int edges = edge_cnt[i], verts = vert_cnt[i];
    if (edges && (edges * (edges - 1) / 2 == verts))
      ++ans;
    connect_cnt += edges;
  }
  free(vert_cnt);
  free(edge_cnt);
  free(vertices);
  return ans + (n - connect_cnt);
}

int main() {
  int e1i[4][2] = {{0, 1}, {0, 2}, {1, 2}, {3, 4}},
      e2i[5][2] = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  printf("%d\n", countCompleteComponents(6, e1->arr, e1->row_size,
                                         e1->col_size)); // expect: 3
  printf("%d\n", countCompleteComponents(6, e2->arr, e2->row_size,
                                         e2->col_size)); // expect: 1
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
