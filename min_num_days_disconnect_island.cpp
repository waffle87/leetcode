#include "leetcode.h"

class Solution {
public:
  int minDays(vector<vector<int>> &grid) {
    int islands = islandCount(grid);
    int n = grid.size(), m = grid[0].size();
    if (islands > 1 || islands == 0)
      return 0;
    else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j]) {
            grid[i][j] = 0;
            islands = islandCount(grid);
            grid[i][j] = 1;
            if (islands > 1 || islands == 1)
              return 1;
          }
        }
      }
    }
    return 2;
  }

private:
  vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
  void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis) {
    int n = grid.size(), m = grid[0].size();
    vis[x][y] = 1;
    for (int a = 0; a < 4; a++) {
      int nx = x + dx[a], ny = y + dy[a];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] &&
          grid[nx][ny])
        dfs(nx, nx, grid, vis);
    }
  }
  int islandCount(vector<vector<int>> &grid) {
    int count = 0, n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && grid[i][j]) {
          dfs(i, j, grid, vis);
        }
      }
    }
    return count;
  }
};
