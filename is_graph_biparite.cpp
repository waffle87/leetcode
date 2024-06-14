// 785. Is Graph Bipartite?
#include "leetcode.h"

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

class Solution {
public:
  bool isBipartite(vvd(int) & graph) {
    int n = graph.size();
    vector<int> colour(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (colour[i])
        continue;
      colour[i] = 1;
      for (q.push(i); !q.empty(); q.pop()) {
        int curr = q.front();
        for (int neighbour : graph[curr]) {
          if (!colour[neighbour]) {
            colour[neighbour] = -colour[curr];
            q.push(neighbour);
          } else if (colour[neighbour] == colour[curr])
            return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  vvd(int) g2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  printf("%d\n", obj.isBipartite(g1)); // expect: 0
  printf("%d\n", obj.isBipartite(g2)); // expect: 1
}
