#include "leetcode.h"

class Solution {
public:
  int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
    const int n = scores.size();
    vector<vector<int>> adj(n);
    for (const vector<int> &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    for (vector<int> &a : adj) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pqpvg;
      for (int v : a) {
        int score = scores[v];
        if (pqpvg.size() < 3 || pqpvg.top().first < score) {
          pqpvg.push({score, v});
          if (pqpvg.size() > 3)
            pqpvg.pop();
        }
      }
      a.resize(pqpvg.size());
      for (int i = a.size() - 1; i >= 0; --i) {
        a[i] = pqpvg.top().second;
        pqpvg.pop();
      }
    }
    int ans = -1;
    for (const vector<int> &edge : edges) {
      int u = edge[0], v = edge[1], base = scores[u] + scores[v];
      for (int x : adj[u]) {
        if (x == v)
          continue;
        for (int y : adj[v]) {
          if (y == u || x == y)
            continue;
          ans = max(ans, base + scores[x] + scores[y]);
        }
      }
    }
    return ans;
  }
};
