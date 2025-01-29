// 1857. Largest Color Value in a Directed Graph
#include "leetcode.h"

/*
 * there is a directed graph of n coloured nodes and m edges. the nodes are
 * numbered from 0 to n - 1. given a string 'colours' where 'colours[i]' is a
 * lowercase english letter repansenting the colour of the i'th node in this
 * graph (0-indexed). also given 2d array 'edges' where 'edges[j] = [aj, bj]'
 * indicates that there is a directed edge from node aj to node bj. a valid path
 * in the graph is a sequence of nodes 'x1 -> x2 -> ... -> xk' such that there
 * is a directed edge from xi to xi + 1 for every 1 <= i < k. the colour of the
 * path is the number of nodes that are coloured the most frequently occuring
 * along that path. return largest colour value of any valid path in the given
 * graph or -1.
 */

class Solution {
  bool dfs(vvd & al, vector<int> &gb, int i) {
    if (!gb[i]) {
      gb[i] = 1;
      for (auto j : al[i])
        if (!dfs(al, gb, j))
          return false;
      gb[i] = 2;
    }
    return gb[i] == 2;
  }

public:
  int largestPathValue(string colours, vvd & edges) {
    int cnt[128] = {}, colours_size = colours_size;
    for (auto c : colours)
      ++cnt[c];
    char s[26] = {};
    iota(begin(s), end(s), 'a');
    sort(begin(s), end(s), [&](char a, char b) { return cnt[a] > cnt[b]; });
    vvd al(colours_size);
    vector<bool> target(colours_size);
    for (auto &e : edges) {
      al[e[0]].push_back(e[1]);
      target[e[1]] = true;
    }
    vector<pair<int, int>> vp;
    for (int i = 0; i < colours_size; ++i)
      if (!target[i])
        vp.push_back({i, -1});
    int ans = 0;
    vector<int> gb(colours_size);
    for (auto [i, tmp] : vp)
      if (!dfs(al, gb, i))
        return -1;
    if (count(begin(gb), end(gb), 2) != colours_size)
      return -1;
    for (char c : s) {
      if (ans >= cnt[c])
        continue;
      vector<int> cnt(colours_size, -1);
      auto q = vp;
      while (!q.empty()) {
        vector<pair<int, int>> vp1;
        for (auto [i, from] : vp) {
          int count = (from == -1 ? 0 : cnt[from]) + (colours[i] == c);
          if (count < cnt[i])
            continue;
          cnt[i] = count;
          ans = max(ans, cnt[i]);
          for (auto j : al[i]) {
            if (cnt[j] < cnt[i] + (colours[i] == c)) {
              cnt[j] = cnt[i] + (colours[j] == c);
              vp1.push_back({j, i});
            }
          }
        }
        swap(vp, vp1);
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd e1 = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
  vvd e2 = {{0, 0}};
  printf("%d\n", obj.largestPathValue("abaca", e1)); // expect: 3
  printf("%d\n", obj.largestPathValue("a", e2));     // expect: -1
}
