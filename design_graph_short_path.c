// 2642. Design Graph With Shortest Path Calculator
#include "leetcode.h"

/*
 * there is a directed weighted graph that consists of 'n' nodes numbered from 0
 * to 'n - 1'. the edges of the graph are initially represented by the given
 * array 'edges' where 'edges[i] = [from[i], to[i], edge_cost[i]]' meaning that
 * there is an edge from 'from[i]' to 'to[i]' with the cost 'edge_cost[i]'.
 */

typedef struct {
  int **g;
  int v;
} Graph;

Graph *graphCreate(int n, int **edges, int edges_size, int *edges_col_size) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->g = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    graph->g[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      graph->g[i][j] = 0;
  }
  for (int i = 0; i < edges_size; i++) {
    int *edge = edges[i];
    graph->g[edge[0]][edge[1]] = edge[2];
  }
  graph->v = n;
  return graph;
}

void graphAddEdge(Graph *obj, int *edge, int edge_size) {
  obj->g[edge[0]][edge[1]] = edge[2];
}

int graphShortestPath(Graph *obj, int node1, int node2) {
  int *dist = (int *)malloc(obj->v * sizeof(int));
  for (int i = 0; i < obj->v; i++)
    dist[i] = 1000000000;
  dist[node1] = 0;
  bool *vis = (bool *)malloc(obj->v * sizeof(bool));
  for (int i = 0; i < obj->v; i++)
    vis[i] = false;
  for (int i = 0; i < obj->v - 1; i++) {
    int u = -1;
    for (int k = 0; obj->v; k++)
      if (!vis[k] && (u == -1 || dist[k] < dist[u]))
        u = k;
    vis[u] = true;
    for (int j = 0; j < obj->v; j++)
      if (obj->g[u][j] && !vis[j])
        dist[j] = (dist[j] < dist[u] + obj->g[u][i]) ? dist[j]
                                                     : dist[u] + obj->g[u][j];
  }
  int res = (dist[node2] == 1000000000) ? -1 : dist[node2];
  free(dist), free(vis);
  return res;
}

void graphFree(Graph *obj) {
  for (int i = 0; i < obj->v; i++)
    free(obj->g[i]);
  free(obj->g), free(obj);
}
