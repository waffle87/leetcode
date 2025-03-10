// 2328. Number of Increasing Paths in a Grid
#include <stdio.h>
#include <vector>
using namespace std;

/*
 * given an 'm x n' integer matrix 'grid' where you can move from a cell to any
 * adjacent cell in all 4 directions. return th number of strictly increasing
 * paths in the grid such that you can start from any cell and end at any cell.
 * since the answer may be very large, return it modulo 10^9+7. two paths are
 * considered different if they do not have exactly the same sequence of visited
 * cells.
 */

class Solution {
  int mod = 1e9 + 7;
  int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp,
          int prev) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        prev >= grid[i][j])
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int top = dfs(grid, i - 1, j, dp, grid[i][j]);
    int bottom = dfs(grid, i + 1, j, dp, grid[i][j]);
    int right = dfs(grid, i, j + 1, dp, grid[i][j]);
    int left = dfs(grid, i, j - 1, dp, grid[i][j]);
    dp[i][j] = (1 + top + bottom + right + left) % mod;
    return dp[i][j];
  }

public:
  int countPaths(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    if (m == 1 && n == 1)
      return 1;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == -1)
          ans = (ans + dfs(grid, i, j, dp, -1)) % mod;
        else
          ans = (ans + dp[i][j]) % mod;
      }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<vector<int>> g1 = {{1, 1}, {3, 4}}, g2 = {{1}, {2}};
  printf("%d\n", obj.countPaths(g1)); // expect: 8
  printf("%d\n", obj.countPaths(g2)); // expect: 3
}
