// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
#include "leetcode.h"

/*
 * given integer 'n', there is undirected graph with 'n' nodes, numbered 0 to 'n
 * - 1' given 2d integer array 'edges' where 'edges[i] = [ai bi]' denotes that
 * there exists an undirected edge connecting nodes ai and bi. return number of
 * pairs of different nodes that are unreachable from each other
 */

class Solution {
public:
  long long countPairs(int n, vvd(int) & edges) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < edges.size(); i++) {
      m[edges[i][0]].push_back(edges[i][0]);
      m[edges[i][1]].push_back(edges[i][1]);
    }
    long long ans = ((long long)n * (n - 1)) / 2;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) {
        long long cnt = 0;
        dfs(i, m, cnt, vis);
        ans -= (cnt * (cnt - 1)) / 2;
      }
    }
    return ans;
  }

private:
  void dfs(int n, unordered_map<int, vector<int>> m, long long cnt,
           vector<int> vis) {
    vis[n] = 1;
    cnt++;
    for (auto i : m[n])
      if (vis[i] == 0)
        dfs(i, m, cnt, vis);
  }
};

int main() {
  Solution obj;
  vvd(int) e1 = {{0, 1}, {0, 2}, {1, 2}};
  vvd(int) e2 = {{0, 2}, {0, 5}, {2, 4}};
  printf("%lld\n", obj.countPairs(3, e1)); // expect: 0
  printf("%lld\n", obj.countPairs(7, e2)); // expect: 14
}
