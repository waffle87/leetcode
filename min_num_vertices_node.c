// 1557. Minimum Number of Vertices to Reach All Nodes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a directed acyclic graph, with 'n' vertices numbered from 0 to 'n - 1',
 * and an array 'edges', where 'edges[i] = [fromi, toi]' representes a directed
 * edge from node 'fromi' to node 'toi'. find the smallest set of vertices from
 * which all nodes in the graph are reachale. it's guaranteed that a unique
 * solution exists. notice you cano return the vertices in any order.
 */

int *findSmallestSetOfVertices(int n, int **edges, int edges_size,
                               int *edges_col_size, int *return_size) {
  int cnt = n;
  bool *node = calloc(n, sizeof(bool));
  for (int i = 0; i < edges_size; i++) {
    if (!node[edges[i][1]]) {
      node[edges[i][1]] = 1;
      cnt--;
    }
  }
  int *ans = malloc(cnt * sizeof(int));
  int a_idx = 0;
  for (int i = 0; i < n; i++) {
    if (!node[i]) {
      ans[a_idx] = i;
      a_idx++;
    }
  }
  free(node);
  *return_size = cnt;
  return ans;
}

int main() {
  int e1[5][2] = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  int e2[5][2] = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
  int ecs[] = {5}, rs[] = {};
  int *t1 = findSmallestSetOfVertices(6, e1, 5, ecs, rs);
  int *t2 = findSmallestSetOfVertices(3, e2, 5, ecs, rs);
  for (int i = 0; i < 5; i++)
    printf("%d ", t1[i]); // expect: 0 3
  printf("\n");
  for (int i = 0; i < 5; i++)
    printf("%d ", t2[i]); // expect: 0 2 3
}
