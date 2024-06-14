#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<bool> vi(n, false);
    vector<int> disc(n, 0), low(n, 0), parent(n, -1);
    vector<vector<int>> g(n, vector<int>()), ans;
    for (auto &p : connections) {
      g[p.front()].push_back(p.back());
      g[p.back()].push_back(p.front());
    }
    for (int i = 0; i < n; ++i) {
      if (vi[i])
        continue;
      helper(i, vi, disc, low, parent, g, ans);
    }
    return ans;
  }

private:
  void helper(int u, vector<bool> &vi, vector<int> &disc, vector<int> &low,
              vector<int> &parent, vector<vector<int>> &g,
              vector<vector<int>> &ans) {
    static int time = 0;
    vi[u] = true;
    disc[u] = low[u] = ++time;
    for (int i : g[u]) {
      if (!vi[i]) {
        parent[i] = u;
        helper(i, vi, disc, low, parent, g, ans);
        low[u] = min(low[u], low[i]);
        if (low[i] > disc[u])
          ans.push_back({u, i});
      } else if (i != parent[u])
        low[u] = min(low[u], disc[i]);
    }
  }
};

int main() {}
