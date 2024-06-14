// 1319. Number of Operations to Make Network Connected
#include "leetcode.h"

class Solution {
public:
  int makeConnected(int n, vvd(int) & connections) {
    if (connections.size() < n - 1)
      return -1;
    vvd(int) adj(n);
    for (auto v : connections) {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }
    vector<bool> visited(n, false);
    int comp = 0;
    for (int i = 0; i < n; i++)
      if (!visited[i]) {
        dfs(adj, visited, i);
        comp++;
      }
    return comp - 1;
  }

private:
  void dfs(vvd(int) & adj, vector<bool> &visited, int src) {
    visited[src] = true;
    for (int i : adj[src])
      if (!visited[i])
        dfs(adj, visited, i);
  }
};

int main() {
  Solution obj;
  vvd(int) c1 = {{0, 1}, {0, 2}, {1, 2}};
  vvd(int) c2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  vvd(int) c3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  printf("%d\n", obj.makeConnected(4, c1));
  printf("%d\n", obj.makeConnected(6, c2));
  printf("%d\n", obj.makeConnected(6, c3));
}
