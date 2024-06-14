#include "leetcode.h"

class Solution {
public:
  int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n,
              int target) {
    int INF = 1000000;
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(target + 1, vector<int>(n, INF)));
    for (int i = 1; i <= n; i++) {
      if (houses[0] == i)
        dp[0][1][i - 1] = 0;
      else if (!houses[0])
        dp[0][1][i - 1] = cost[0][i - 1];
    }
    for (int i = 1; i < m; i++) {
      for (int k = 1; k <= min(target, i + 1); k++) {
        for (int j = 1; j <= n; j++) {
          if (houses[i] && j != houses[i])
            continue;
          int same = dp[i - 1][k][j - 1];
          int diff = INF;
          for (int r = 1; r <= n; r++)
            if (r != j)
              diff = min(diff, dp[i - 1][k - 1][r - 1]);
          int paintCost = cost[i][j - 1] * int(!houses[i]);
          dp[i][k][j - 1] = min(same, diff) + paintCost;
        }
      }
    }
    int ans = *min_element(dp.back().back().begin(), dp.back().back().end());
    return (ans < INF) ? ans : -1;
  }
};
