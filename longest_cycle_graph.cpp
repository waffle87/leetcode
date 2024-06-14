// 2360. Longest Cycle in a Graph
#include "leetcode.h"

/*
 * given a directed graph of 'n' nodes numbered from 0 to n - 1, where each node
 * has at most one outgoing edge. the graph is represented with a given
 * 0-indexed array 'edges' of size n, indicating that there is a directed edge
 * from node i to node edges[i]. if there is no outgoing edge from node i, then
 * edges[i] == -1. return length of longest cycle in the graph. if no cycle
 * exists, return -1. a cycle path starts at same node.
 */

class Solution {
public:
  int longestCycle(vector<int> &edges) {
    vector<bool> vis(edges.size(), 0);
    for (int i = 0; i < edges.size(); i++) {
      if (vis[i])
        continue;
      vector<int> store;
      dfs(edges, i, vis, store);
    }
    return max_len;
  }

private:
  int max_len = -1;
  void dfs(vector<int> &edges, int si, vector<bool> &vis, vector<int> &store) {
    if (si == -1)
      return;
    if (vis[si]) {
      int cnt = -1;
      for (int i = 0; i < store.size(); i++) {
        if (store[i] == si) {
          cnt = i;
          break;
        }
      }
      if (cnt == -1)
        return;
      int size = store.size() - cnt;
      max_len = max(max_len, size);
      return;
    }
    vis[si] = true;
    store.push_back(si);
    dfs(edges, edges[si], vis, store);
    return;
  }
};

int main() {
  Solution obj;
  vector<int> e1 = {3, 3, 4, 2, 3};
  vector<int> e2 = {2, -1, 3, 1};
  printf("%d\n", obj.longestCycle(e1));
  printf("%d\n", obj.longestCycle(e2));
}
