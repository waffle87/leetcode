// 2493. Divide Nodes Into the Maximum Number of Groups
#include "leetcode.h"

/*
 * you are given a positive integer 'n' representing the number of nodes in an
 * undirected graph. the nodes are labeled from 1 to 'n'. you are also given a
 * 2d integer array 'edges', where 'edges[i] = [a_i, b_i]' indicates that there
 * is a bidirectional edge between nodes 'a_i' and 'b_i'. divide the nodes of
 * the graph into 'm' groups such that each node in the graph belongs to exactly
 * one group, and for every pair of nodes in the graph that are connected by an
 * edge '[a_i, b_i]', then '|y - x| = 1'. return the maximum number of groups
 * into which you can divide the nodes. return -1 if it is impossible.
 */

class Solution {
public:
  int magnificentSets(int n, vector<vector<int>> &edges) {
    vector<int> vis(n);
    vector<vector<int>> graph(n), group;
    for (auto e : edges) {
      graph[e[0] - 1].push_back(e[1] - 1);
      graph[e[1] - 1].push_back(e[0] - 1);
    }
    for (int i = 0; i < n; ++i)
      if (!vis[i]) {
        vis[i] = true;
        stack<int> stk;
        stk.push(i);
        group.push_back({i});
        while (stk.size()) {
          auto u = stk.top();
          stk.pop();
          for (auto &v : graph[u])
            if (!vis[v]) {
              vis[v] = vis[u] + 1;
              stk.push(v);
              group.back().push_back(v);
            } else if ((vis[u] & 1) == (vis[v] & 1))
              return -1;
        }
      }
    auto bfs = [&](int x) {
      int res = 0;
      vector<bool> vis(n);
      vis[x] = true;
      queue<int> q;
      q.push(x);
      for (; q.size(); ++res)
        for (int size = q.size(); size; --size) {
          auto u = q.front();
          q.pop();
          for (auto &v : graph[u])
            if (!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
        }
      return res;
    };
    int ans = 0;
    for (auto &g : group) {
      transform(g.begin(), g.end(), g.begin(), bfs);
      ans += *max_element(g.begin(), g.end());
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd e1 = {{1, 2}, {1, 4}, {1, 5}, {2, 6}, {2, 3}, {4, 6}};
  vvd e2 = {{1, 2}, {2, 3}, {3, 1}};
  printf("%d\n", obj.magnificentSets(6, e1)); // expect: 4
  printf("%d\n", obj.magnificentSets(3, e2)); // expect: -1
}
