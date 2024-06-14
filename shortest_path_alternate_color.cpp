// 1129. Shortest Path with Alternating Colors
#include "leetcode.h"

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vvd(int) & redEdges,
                                       vvd(int) & blueEdges) {
    vector<int> ans(n, -1), v1(n, 0), v2(n, 0);
    vector<vector<pair<int, int>>> vvp(n);
    queue<pair<int, int>> qp;
    for (auto &it : redEdges)
      vvp[it[0]].push_back({it[1], 1});
    for (auto &it : blueEdges)
      vvp[it[0]].push_back({it[1], 2});
    ans[0] = 0, v1[0] = 1, v2[0] = 1;
    int tmp = 1;
    for (auto &it : vvp[0]) {
      qp.push(it);
      if (ans[it.first] == -1)
        ans[it.first] = tmp;
    }
    while (!qp.empty()) {
      int len = qp.size();
      tmp++;
      for (int i = 0; i < len; ++i) {
        auto val = qp.front();
        qp.pop();
        if (val.second == 1)
          v1[val.first] = 1;
        else
          v2[val.first] = 1;
        for (auto &it : vvp[val.first]) {
          if (val.second == 1 && (v2[it.first] || it.second == 1))
            continue;
          if (val.second == 2 && (v1[it.first] || it.second == 2))
            continue;
          qp.push(it);
          if (ans[it.first] == -1)
            ans[it.first] = tmp;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) re1 = {{0, 1}, {1, 2}}, be1 = {};
  vvd(int) re2 = {{0, 1}}, be2 = {{2, 1}};
  for (auto i : obj.shortestAlternatingPaths(3, re1, be1))
    cout << i << ' '; // expect: 0 1 -1
  cout << endl;
  for (auto i : obj.shortestAlternatingPaths(3, re2, be2))
    cout << i << ' '; // expect: 0 1 -1
}
