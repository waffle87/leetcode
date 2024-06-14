// 802. Find Eventual Safe States
#include <stdbool.h>
#include <stdlib.h>

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

bool dfs(int **graph, int graph_size, int *graph_col_size, int *visited,
         int node) {
  if (visited[node] == 1)
    return true;
  if (visited[node] == 2)
    return false;
  visited[node] = 2;
  for (int i = 0; i < graph_col_size[node]; i++)
    if (!dfs(graph, graph_size, graph_col_size, visited, graph[node][i]))
      return false;
  visited[node] = 1;
  return true;
}

int *eventualSafeNodes(int **graph, int graph_size, int *graph_col_size,
                       int *return_size) {
  int n = graph_size, a_idx = 0;
  int *visited = calloc(n, sizeof(int));
  int *ans = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    if (dfs(graph, graph_size, graph_col_size, visited, i)) {
      ans[a_idx] = i;
      a_idx++;
    }
  free(visited);
  *return_size = a_idx;
  ans = realloc(ans, a_idx * sizeof(int));
  return ans;
}
