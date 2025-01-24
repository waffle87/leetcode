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
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> g(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < graph[i].size(); j++) {
        g[graph[i][j]].push_back(i);
        dp[i]++;
      }
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!dp[i])
        q.push(i);
    vector<int> ans;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ans.push_back(u);
      for (int v : g[u])
        if (!--dp[v])
          q.push(v);
    }
    sort(ans.begin(), ans.end());
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
