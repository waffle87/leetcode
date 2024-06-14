#include "leetcode.h"

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans = 0;
    n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j])
          ans = max(ans, helper(i, j, grid));
    return ans;
  }

private:
  int n = 0, m = 0;
  int helper(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j])
      return 0;
    grid[i][j] = 0;
    return 1 + helper(i - 1, j, grid) + helper(i, j - 1, grid) +
           helper(i + 1, j, grid) + helper(i, j + 1, grid);
  }
};
