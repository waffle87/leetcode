#include "leetcode.h"

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    if (!rows)
      return 0;
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    function<int(int, int)> dfs = [&](int x, int y) {
      if (dp[x][y])
        return dp[x][y];
      vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
      for (auto &dir : dirs) {
        int x2 = x + dir[0], y2 = y + dir[1];
        if (x2 < 0 || x2 >= rows || y2 < 0 || y2 >= cols)
          continue;
        if (matrix[x2][y2] <= matrix[x][y])
          continue;
        dp[x][y] = max(dp[x][y], dfs(x2, y2));
      }
      return ++dp[x][y];
    };
    int ans = 0;
    for (int i = 0; i < rows; ++i)
      for (int j = 0; i < cols; ++j)
        ans = max(ans, dfs(i, j));
    return ans;
  }
};

int main() {}
