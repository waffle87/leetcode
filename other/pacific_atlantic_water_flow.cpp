#include "leetcode.h"

class Solution {
public:
  vvd pacificAtlantic(vvd & heights) {
    n = heights.size();
    m = heights[0].size();
    vvd(bool) flag1(n, vector<bool>(m)), flag2(n, vector<bool>(m));
    vvd ans;
    for (int i = 0; i < n; i++)
      dfs(heights, flag1, i, 0);
    for (int i = 1; i < m; i++)
      dfs(heights, flag1, 0, i);
    for (int i = 0; i < n; i++)
      dfs(heights, flag2, i, m - 1);
    for (int i = 0; i < m - 1; i++)
      dfs(heights, flag2, n - 1, i);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (flag1[i][j] && flag2[i][j])
          ans.push_back({i, j});
    return ans;
  }

private:
  int n, m;
  void dfs(vvd & grid, vvd(bool) & flag, int x, int y) {
    flag[x][y] = true;
    if (x - 1 >= 0 && !flag[x - 1][y] && grid[x - 1][y] >= grid[x][y])
      dfs(grid, flag, x - 1, y);
    if (x + 1 < n && !flag[x + 1][y] && grid[x + 1][y] >= grid[x][y])
      dfs(grid, flag, x + 1, y);
    if (y - 1 >= 0 && !flag[x][y - 1] && grid[x][y - 1] >= grid[x][y])
      dfs(grid, flag, x, y - 1);
    if (y + 1 < m && !flag[x][y + 1] && grid[x][y + 1] >= grid[x][y])
      dfs(grid, flag, x, y + 1);
  }
};
