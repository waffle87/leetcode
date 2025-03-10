// 1568. Minimum Number of Days to Disconnect Island
#include "leetcode.h"

/*
 * you are given an 'm * n' binary grid where 1 represents land and 0 represents
 * water. an island is a maximal 4 directionally horizontal or vertical
 * connected group of 1's. the grid is said to be connected if we have exactly
 * one island otherwise it is disconnected. in one day, we are allowed to change
 * any single land cell 1 into a water cell 0. return the minimum number of days
 * to disconnect the grid.
 */

class Solution {
public:
  int minDays(vector<vector<int>> &grid) {
    int islands = cnt_islands(grid), n = grid.size(), m = grid[0].size();
    if (islands > 1 || !islands)
      return 0;
    else
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (grid[i][j]) {
            grid[i][j] = 0;
            islands = cnt_islands(grid);
            grid[i][j] = 1;
            if (islands > 1 || !islands)
              return 1;
          }
    return 2;
  }

private:
  vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
  void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis) {
    int n = grid.size(), m = grid[0].size();
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 and ny >= 0 and nx < n and ny < m and !vis[nx][ny] and
          grid[nx][ny])
        dfs(nx, ny, grid, vis);
    }
  }
  int cnt_islands(vector<vector<int>> &grid) {
    int res = 0, n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!vis[i][j] && grid[i][j]) {
          dfs(i, j, grid, vis);
          res++;
        }
    return res;
  }
};

int main() {
  Solution obj;
  vvd g1 = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, g2 = {{1, 1}};
  printf("%d\n", obj.minDays(g1)); // expect: 2
  printf("%d\n", obj.minDays(g2)); // expect: 2
}
