// 785. Is Graph Bipartite?
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * there is an undirected graph with 'n' nodes, where each node is numbered
 * between 0 and 'n - 1'. you are given a 2d array 'graph' where 'graph[u]' is
 * an array of nodes that node 'u' is adjacent to. more formally, for each 'v'
 * in 'graph[u]', there is an undirected edge between node 'u' and node 'v'. the
 * graph has the following properties:
 * - there are no self-edges ('graph[u]' does not contain 'u')
 * - there are no parallel edges ('graph[u]' does not contain duplicate values)
 * - if 'v' is in 'graph[u]', then 'u' is in 'graph[v]' (the graph is
 * undirected)
 * - the graph may not be connected, meaning there may be two nodes 'u' and 'v'
 * such that there is no path between them a graph is bipartite if the nodes can
 * be partitioned into two independent sets 'A' and 'B' such that every edge in
 * the graph connects a node in set 'A' and a node in set 'B'. return true if
 * and only if the graph is bipartite.
 */

bool dfs(int **graph, int graph_size, int *graph_col_size, int *queue,
         int begin, int end, int *node, bool *paint) {
  int _end = end;
  for (int i = begin; i < end; i++) {
    int pos = queue[i];
    int colour = node[pos] ? 2 : 1;
    for (int j = 0; j < graph_col_size[pos]; j++) {
      int itr = graph[pos][j];
      if (node[itr] == node[pos])
        return false;
      else if (!paint[itr]) {
        node[itr] = colour;
        paint[itr] = true;
        queue[_end] = itr;
        _end++;
      }
    }
    if (!dfs(graph, graph_size, graph_col_size, queue, end, _end, node, paint))
      return false;
  }
  return true;
}

bool isBipartite(int **graph, int graph_size, int *graph_col_size) {
  int *node = calloc(graph_size, sizeof(int));
  bool *paint = calloc(graph_size, sizeof(int));
  int *queue = malloc(graph_size * sizeof(int));
  int idx = 0;
  for (int i = 0; i < graph_size; i++) {
    if (!paint[i]) {
      node[i] = 1;
      paint[i] = true;
      for (int j = 0; j < graph_col_size[i]; j++) {
        int itr = graph[i][j];
        if (node[itr] == node[i])
          return false;
        else if (!paint[itr]) {
          node[itr] = 2;
          paint[itr] = true;
          queue[idx] = itr;
          idx++;
        }
      }
      if (!dfs(graph, graph_size, graph_col_size, queue, 0, idx, node, paint))
        return false;
    }
  }
  return true;
}

int main() {
  int g1[][4] = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  int g2[][4] = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  int gcs[] = {};
  printf("%d\n", isBipartite(g1, 5, gcs)); // expect: 0
  printf("%d\n", isBipartite(g2, 5, gcs)); // expect: 1
}
