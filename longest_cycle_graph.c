// 2360. Longest Cycle in a Graph
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a directed graph of 'n' nodes numbered from 0 to n - 1, where each node
 * has at most one outgoing edge. the graph is represented with a given
 * 0-indexed array 'edges' of size n, indicating that there is a directed edge
 * from node i to node edges[i]. if there is no outgoing edge from node i, then
 * edges[i] == -1. return length of longest cycle in the graph. if no cycle
 * exists, return -1. a cycle path starts at same node.
 */

typedef struct set {
  int cycle;
  int seq;
} set_t;

int longestCycle(int *edges, int edges_size) {
  int n = edges_size, ans = -1, run = 1;
  bool *visited = calloc(n, sizeof(bool));
  set_t **hash = calloc(n, sizeof(set_t *));
  for (int i = 0; i < n; i++) {
    if (edges[i] == -1 || visited[i])
      continue;
    int idx = -1, p = i;
    while (p != -1) {
      idx++;
      if (visited[p] == false) {
        hash[p] = malloc(sizeof(set_t));
        hash[p]->cycle = run;
        hash[p]->seq = idx;
        visited[p] = true;
      } else {
        if (hash[p]->cycle == run)
          ans = fmax(ans, idx - hash[p]->seq);
        break;
      }
      p = edges[p];
    }
    run++;
  }
  for (int i = 0; i < n; i++)
    if (hash[i] != NULL)
      free(hash[i]);
  free(hash);
  free(visited);
  return ans;
}

int main() {
  int e1[] = {3, 3, 4, 2, 3}, e2[] = {2, -1, 3, 1};
  printf("%d\n", longestCycle(e1, 5)); // expect: 3
  printf("%d\n", longestCycle(e2, 4)); // expect: -1
}
