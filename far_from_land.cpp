#include "leetcode.h"

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    int ans = -1;
    if (grid.empty() || grid[0].empty())
      return ans;

    vector<vector<int>> gridValues(grid.size(),
                                   vector<int>(grid[0].size(), INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          q.push(make_pair(i, j));
          gridValues[i][j] = 0;
        }
      }
    }
    if (q.empty())
      return -1;
    vector<int> dx({0, 1, 0, -1}), dy({1, 0, -1, 0});
    while (!q.empty()) {
      auto pos = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x = pos.first + dx[i], y = pos.second + dy[i];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
          if (gridValues[x][y] == INT_MAX)
            q.push(make_pair(x, y));
          gridValues[x][y] =
              min(gridValues[x][y], gridValues[pos.first][pos.second] + 1);
        }
      }
    }
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 0)
          ans = max(ans, gridValues[i][j]);
    return ans;
  }
};
