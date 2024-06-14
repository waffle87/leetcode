// 1971. Find if Path Exists in Graph
#include "leetcode.h"

/*
 * there is a bidirectional graph with 'n' vertices where each vertex is labeled
 * from 0 to 'n - 1' inclusive. the edges in the graph are rpresented as a 2d
 * integer array 'edges', where each 'edgies[i] = [ui, vi]', denotes a
 * bidirectional edge between vertex 'ui' and vertex 'vi'. every vertex pair is
 * connected by at most one edge, and no vertex has an edge to itself.
 */

bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source,
               int destination) {
  if (source == destination)
    return 1;
  bool vis_map[n], stk_map[n];
  for (int i = 0; i < n; i++) {
    stk_map[i] = 0;
    vis_map[i] = 0;
  }
  int stk[n];
  uint pt = -1;
  stk[++pt] = source;
  stk_map[source] = 1;
  while (pt != -1) {
    while (vis_map[stk[pt]])
      pt--;
    vis_map[stk[pt]] = 1;
    int top = stk[pt--];
    stk_map[top] = 0;
    for (int i = 0; i < edgesSize; i++)
      for (int j = 0; j < *edgesColSize; j++)
        if (edges[i][j] == top) {
          int vertex = edges[i][*edgesColSize - j - 1];
          if (vertex == destination)
            return 1;
          if (!vis_map[vertex] && !stk_map[vertex]) {
            stk[++pt] = vertex;
            stk_map[vertex] = 1;
          }
          edges[i][j] = n;
          edges[i][*edgesColSize - j - 1] = n;
          break;
        }
  }
  return vis_map[destination];
}
