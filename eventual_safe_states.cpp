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

class Solution {
  unordered_set<int> cycle_nodes, safe_nodes;
  bool dfs(const vvd(int) & graph, int i, unordered_set<int> visited) {
    if (safe_nodes.find(i) != safe_nodes.end())
      return true;
    if (cycle_nodes.find(i) != cycle_nodes.end())
      return false;
    if (visited.find(i) != visited.end()) {
      cycle_nodes.insert(i);
      return false;
    }
    visited.insert(i);
    for (int node : graph[i])
      if (!dfs(graph, node, visited)) {
        cycle_nodes.insert(i);
        return false;
      }
    safe_nodes.insert(i);
    return true;
  }

public:
  vector<int> eventualSafeNodes(vvd(int) & graph) {
    vector<int> ans;
    unordered_set<int> visited;
    for (int i = 0; i < graph.size(); i++)
      if (dfs(graph, i, visited))
        ans.push_back(i);
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  vvd(int) g2 = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
  for (auto i : obj.eventualSafeNodes(g1))
    printf("%d ", i); // expect: 2 4 5 6
  printf("\n");
  for (auto i : obj.eventualSafeNodes(g2))
    printf("%d ", i); // expect: 4
  printf("\n");
}
