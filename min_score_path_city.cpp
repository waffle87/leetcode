// 2492. Minimum Score of a Path Between Two Cities
#include "leetcode.h"

class Solution {
public:
  int minScore(int n, vvd(int) & roads) {
    unordered_map<int, unordered_map<int, int>> graph;
    for (auto r : roads)
      graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];
    unordered_set<int> vis;
    function<int(int)> dfs;
    dfs = [&](int n) -> int {
      int res = INT_MAX;
      vis.insert(n);
      for (auto [adj, scr] : graph[n]) {
        if (!vis.count(adj))
          res = min(res, dfs(adj));
        res = min(res, scr);
      }
      return res;
    };
    return dfs(1);
  }
};

int main() {
  Solution obj;
  vvd(int) r1 = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
  vvd(int) r2 = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
  printf("%d\n", obj.minScore(4, r1)); // expect: 5
  printf("%d\n", obj.minScore(4, r2)); // expect: 2
}
