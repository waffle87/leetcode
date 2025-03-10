// 749. Contain Virus
#include "leetcode.h"

class Cluster {
public:
  set<pair<int, int>> c;
  set<pair<int, int>> uc;
  int w_cnt = 0;
};

class Solution {
public:
  int containsVirus(vvd & isInfected) {
    int n = isInfected.size(), m = isInfected[0].size(), ans = 0;
    while (1) {
      vvd(bool) vis(n, vector<bool>(m));
      auto cmp = [](const Cluster &A, const Cluster &B) {
        return A.uc.size() < B.uc.size();
      };
      priority_queue<Cluster, vector<Cluster>, decltype(cmp)> pq(cmp);
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!vis[i][j] && isInfected[i][j] == 1) {
            Cluster c;
            dfs(isInfected, i, j, vis, c);
            pq.push(c);
          }
      if (pq.size() == 0)
        break;
      Cluster k = pq.top();
      pq.pop();
      for (auto x : k.c)
        isInfected[x.first][x.second] = -1;
      ans += k.w_cnt;
      while (!pq.empty()) {
        Cluster k1 = pq.top();
        pq.pop();
        for (auto x : k1.uc)
          isInfected[x.first][x.second] = 1;
      }
    }
    return ans;
  }

private:
  void dfs(vvd & grid, int i, int j, vvd(bool) & vis, Cluster &cl) {
    if (i == grid.size() || i < 0 || j < 0 || j == grid[0].size() ||
        vis[i][j] || grid[i][j] == -1)
      return;
    if (grid[i][j] == 0) {
      cl.w_cnt++;
      cl.uc.insert({i, j});
      return;
    }
    cl.c.insert({i, j});
    vis[i][j] = true;
    dfs(grid, i + 1, j, vis, cl); // above
    dfs(grid, i - 1, j, vis, cl); // below
    dfs(grid, i, j + 1, vis, cl); // right
    dfs(grid, i, j - 1, vis, cl); // left
  }
};

int main() {
  Solution obj;
  vvd isInfected1 = {{0, 1, 0, 0, 0, 0, 0, 1},
                          {0, 1, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0}};
  vvd isInfected2 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vvd isInfected3 = {{1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {1, 0, 1, 0, 1, 1, 1, 1, 1},
                          {1, 1, 1, 0, 0, 0, 0, 0, 0}};
  cout << obj.containsVirus(isInfected1) << endl; // expect: 10
  cout << obj.containsVirus(isInfected2) << endl; // expect: 4
  cout << obj.containsVirus(isInfected3) << endl; // expect: 13
}
