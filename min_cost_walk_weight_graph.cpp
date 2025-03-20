// 3108. Minimum Cost Walk in Weighted Graph
#include "leetcode.h"

/*
 * there is an undirected weighted graph with 'n' vertices labeled from 0 to 'n
 * - 1'. you are given the integer 'n' and an array 'edges', where 'edges[i] =
 * [u_i, v_i, w_i]' indicates that there is an edge between vertices 'u_i' and
 * 'v_i' with a weight of 'w_i'. a walk on the graph is a sequence of vertices
 * and edges. the walk starts and ends with a vertex, and each edge connects the
 * vertex that comes before it and the vertex that comes after it. it's
 * important to note that a walk may visit the same edge or vertex more than
 * once. return the array 'answer' where 'answer[i]' denotes the minimum cost of
 * a walk for query 'i'.
 */

class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &query) {
    vector<vector<int>> adj(n);
    vector<int> cnt(n, (1 << 30) - 1);
    for (vector<int> e : edges) {
      int u = e[0], v = e[1], k = e[2];
      adj[u].push_back(v);
      adj[v].push_back(u);
      cnt[u] &= k;
      cnt[v] &= k;
    }
    queue<int> q;
    vector<int> group(n, -1);
    for (int i = 0; i < n; i++) {
      if (group[i] == -1) {
        group[i] = i;
        q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          cnt[i] &= cnt[u];
          for (int v : adj[u]) {
            if (group[v] == -1) {
              group[v] = i;
              q.push(v);
            }
          }
        }
      }
    }
    vector<int> ans;
    for (vector<int> qs : query) {
      int s = qs[0], t = qs[1];
      if (s == t)
        ans.push_back(0);
      else
        ans.push_back(group[s] == group[t] ? cnt[group[s]] : -1);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd e1 = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}}, q1 = {{0, 3}, {3, 4}};
  vvd e2 = {{0, 2, 7}, {0, 1, 15}, {1, 2, 6}, {1, 2, 1}}, q2 = {{1, 2}};
  vector<int> mc1 = obj.minimumCost(5, e1, q1);
  vector<int> mc2 = obj.minimumCost(3, e2, q2);
  for (auto i : mc1)
    printf("%d ", i); // expect: 1 -1
  printf("\n");
  for (auto i : mc2)
    printf("%d ", i); // expect: 0
  printf("\n");
}
