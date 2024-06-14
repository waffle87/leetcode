// 934. Shortest Bridge
#include "leetcode.h"

/*
 * given an 'n x n' binary matrix grid where 1 represents land and 0 represents
 * water. an island is a 4 directionally connected group of 1's not connected to
 * any other 1's. there are exactly two islands in a 'grid'. you may change 0's
 * to 1's to connect the two islands to form one island. return the smallest
 * numbe of 0's you must flip to connect the two islands.
 */

class Solution {
  queue<pair<int, int>> qp;
  void dfs(vvd(int) & grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 2 || !grid[i][j])
      return;
    grid[i][j] = 2;
    qp.push({i, j});
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
  int bfs(vvd(int) & grid) {
    int d = 0, min_dist = INT_MAX;
    vvd(int) dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!qp.empty()) {
      int n = qp.size();
      while (n--) {
        auto a = qp.front();
        qp.pop();
        for (int h = 0; h < 4; h++) {
          int x = dir[h][0] + a.first;
          int y = dir[h][1] + a.second;
          if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
              grid[x][y])
            min_dist = min(min_dist, d);
          else if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                   !grid[x][y]) {
            qp.push({x, y});
            grid[x][y] = 2;
          }
        }
      }
      d++;
    }
    return min_dist;
  }

public:
  int shotestBridge(vvd(int) & grid) {
    bool flag = false;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] && !flag) {
          dfs(grid, i, j);
          qp.push({i, j});
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }
    return bfs(grid);
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{0, 1}, {1, 0}};
  vvd(int) g2 = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
  vvd(int) g3 = {{1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 1, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1}};
  printf("%d\n", obj.shotestBridge(g1)); // expect: 1
  printf("%d\n", obj.shotestBridge(g2)); // expect: 2
  printf("%d\n", obj.shotestBridge(g3)); // expect: 1
}
