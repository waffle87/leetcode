// 2699. Modify Graph Edge Weights
#include "leetcode.h"

/*
 * you are given an undirected weighted connected graph containing 'n' nodes
 * labeled from '0' to 'n - 1' and an integer array 'edges' where 'edges[i] =
 * [ai, bi, wi]' indicates that there is an edge between nodes 'ai' and 'bi'
 * with weight 'wi'. some edges have a weight of -1 ('wi = -1'), while other
 * have a positive weight ('wi > 0'). your task is to modify all edges with a
 * weight of -1 by assigning them positive integer values in the range '[1, 2 *
 * 10^9]' so that the shortest distance between the nodes 'source' and
 * 'destination' becomes equal to an integer 'target'. if there are multiple
 * modifications that make the shortest distance equal to 'target', any of them
 * are considered correct. return an array containing all edges in any order if
 * it is possible to make the shortest to equal 'target', or an empty array if
 * it is not possible
 */

class Solution {
  array<int, 2> bfs(vector<vector<array<int, 2>>> &adj,
                    vector<vector<int>> &edges, int source, int destination,
                    int target, bool modify) {
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    vector<int> dist(adj.size(), INT_MAX), mod_id(adj.size(), INT_MAX);
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty() && pq.top()[1] != destination) {
      auto [d, i] = pq.top();
      pq.pop();
      if (d != dist[i])
        continue;
      for (auto [j, edge_id] : adj[i]) {
        int w = edges[edge_id][2];
        if (modify || w != -1)
          if (dist[j] > d + max(1, w)) {
            mod_id[j] = w == -1 ? edge_id : mod_id[i];
            dist[j] = d + max(1, w);
            pq.push({d + max(1, w), j});
          }
      }
    }
    return {dist[destination], mod_id[destination]};
  }

public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges,
                                         int source, int destination,
                                         int target) {
    vector<vector<array<int, 2>>> adj(n);
    for (int i = 0; i < edges.size(); ++i) {
      adj[edges[i][0]].push_back({edges[i][1], i});
      adj[edges[i][1]].push_back({edges[i][0], i});
    }
    auto [dist, _] = bfs(adj, edges, source, destination, target, false);
    if (dist < target)
      return {};
    while (true) {
      auto [dist, mod_id] = bfs(adj, edges, source, destination, target, true);
      if (dist > target)
        return {};
      if (dist == target)
        break;
      edges[mod_id][2] = 1 + target - dist;
    }
    for (auto &e : edges)
      e[2] = e[2] == -1 ? 1 : e[2];
    return edges;
  }
};

int main() {
  Solution obj;
  vvd e1 = {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}},
           e2 = {{0, 1, -1}, {0, 2, 5}},
           e3 = {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, -1}};
  vvd mge1 = obj.modifiedGraphEdges(5, e1, 0, 1, 5),
           mge2 = obj.modifiedGraphEdges(3, e2, 0, 2, 6),
           mge3 = obj.modifiedGraphEdges(4, e3, 0, 2, 6);
  for (int i = 0; i < mge1.size(); i++)
    for (int j = 0; j < mge1[0].size(); j++)
      printf("%d ", mge1[i][j]); // expect: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
  printf("\n");
  for (int i = 0; i < mge2.size(); i++)
    for (int j = 0; j < mge2[0].size(); j++)
      printf("%d ", mge2[i][j]); // expect: []
  printf("\n");
  for (int i = 0; i < mge3.size(); i++)
    for (int j = 0; j < mge3[0].size(); j++)
      printf("%d ", mge3[i][j]); // expect: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
  printf("\n");
}
