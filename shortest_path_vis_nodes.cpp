// 847. Shortest Path Visiting All Nodes
#include "leetcode.h"

/*
 * you have an undirected, connected graph of 'n' nodes labeled from 0 to 'n -
 * 1'. you are given an array 'graph' where 'graph[i]' is a list of all the
 * nodes connected with node 'i' by an edge. return the length of the shortest
 * path that visits every node. you may start and stop any any node. you may
 * revisit nodes multiple times and you may reused edges.
 */

class Solution {
public:
  class tuple {
  public:
    int node;
    int mask;
    int cost;
    tuple(int node, int mask, int cost) {
      this->node = node;
      this->mask = mask;
      this->cost = cost;
    }
  };

  int shortestPathLength(vvd(int) & graph) {
    int n = graph.size();
    queue<tuple> q;
    set<pair<int, int>> vis;
    int all = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
      int mask_val = 1 << i;
      tuple curr(i, mask_val, 1);
      q.push(curr);
      vis.insert({i, mask_val});
    }
    while (!q.empty()) {
      tuple curr = q.front();
      q.pop();
      if (curr.mask == all)
        return curr.cost - 1;
      for (auto adj : graph[curr.node]) {
        int both_vis = curr.mask;
        both_vis = both_vis | (1 << adj);
        tuple node(adj, both_vis, curr.cost + 1);
        if (vis.find({adj, both_vis}) == vis.end()) {
          vis.insert({adj, both_vis});
          q.push(node);
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{1, 2, 3}, {0}, {0}},
           g2 = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
  printf("%d\n", obj.shortestPathLength(g1)); // expect: 4
  printf("%d\n", obj.shortestPathLength(g2)); // expect: 4
}
