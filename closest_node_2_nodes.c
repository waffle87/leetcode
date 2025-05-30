// 2359. Find Closest Node to Given Two Nodes
#include "leetcode.h"

/*
 * you are given a directed graph of 'n' nodes numbered from 0 to 'n - 1', where
 * each node has at most one outgoing edge. the graph is represented with a
 * given 0-indexed array 'edges' of size 'n', indicating that there is a
 * directed edge from node 'i' to node 'edges[i]'. if there is no outgoing edge
 * from 'i' then 'edges[i] == -1'. you are also given two integers 'node1' and
 * 'node2'. return the indes of the node that can be reached from both 'node1'
 * and 'node2' such that the maximum between the distance from 'node1' to that
 * node and from 'node2' to that node is minimised
 */

void dfs(int node, int dist, int *edge, int *n) {
  while (node != -1 && n[node] == -1) {
    n[node] = dist++;
    node = edge[node];
  }
}

int closestMeetingNode(int *edges, int edgesSize, int node1, int node2) {
  int ans = -1, dist = INT_MAX;
  int *n1 = (int *)malloc(edgesSize * sizeof(int));
  int *n2 = (int *)malloc(edgesSize * sizeof(int));
  for (int i = 0; i < edgesSize; i++) {
    n1[i] = -1;
    n2[i] = -1;
  }
  dfs(node1, 0, edges, n1);
  dfs(node2, 0, edges, n2);
  for (int i = 0; i < edgesSize; ++i)
    if (fmin(n1[i], n2[i]) >= 0 && fmax(n1[i], n2[i]) < dist) {
      dist = fmax(n1[i], n2[i]);
      ans = i;
    }
  free(n1);
  free(n2);
  return ans;
}

int main() {
  int e1[] = {2, 2, 3, -1}, e2[] = {1, 2, -1};
  printf("%d\n", closestMeetingNode(e1, ARRAY_SIZE(e1), 0, 1)); // expect: 2
  printf("%d\n", closestMeetingNode(e2, ARRAY_SIZE(e2), 0, 2)); // expect: 2
}
