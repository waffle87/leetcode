// 802. Find Eventual Safe States
#include "leetcode.h"

/*
 * there is a directed graph of 'n' nodes with each node labeled from 0 to n
 * - 1. the graph is represented by a 0-indexed 2d integer array 'graph' where
 * 'graph[i]' is an integer array of nodes adjacent to node 'i', meaning there
 * is an edge from node 'i' to each node in 'graph[i]'. a node is a terminal
 * node if there are no outgoing edges. a node is a safe node if every possible
 * path starting from that node leads to a terminal node ( or another safe
 * node). return an array containing all the safe nodes of the graph. the answer
 * should be sorted in ascending order.
 */

bool dfs(int **graph, int graphSize, int *graphColSize, int *vis, int node) {
  if (vis[node] == 1)
    return true;
  if (vis[node] == 2)
    return false;
  vis[node] = 2;
  for (int i = 0; i < graphColSize[node]; i++)
    if (!dfs(graph, graphSize, graphColSize, vis, graph[node][i]))
      return false;
  vis[node] = 1;
  return true;
}

int *eventualSafeNodes(int **graph, int graphSize, int *graphColSize,
                       int *returnSize) {
  int n = graphSize, idx = 0;
  int *vis = (int *)calloc(n, sizeof(int));
  int *ans = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    if (dfs(graph, graphSize, graphColSize, vis, i)) {
      ans[idx] = i;
      idx++;
    }
  free(vis);
  *returnSize = idx;
  ans = (int *)realloc(ans, idx * sizeof(int));
  return ans;
}

int main() {
  int g1i[7][2] = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}}, rs1;
  int g2i[5][4] = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}}, rs2;
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int *esn1 = eventualSafeNodes(g1->arr, g1->row_size, g1->col_size, &rs1);
  int *esn2 = eventualSafeNodes(g2->arr, g2->row_size, g2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", esn1[i]); // expect: 2 4 5 6
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", esn2[i]); // expect: 4
  printf("\n");
  free(esn2), free(esn2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
