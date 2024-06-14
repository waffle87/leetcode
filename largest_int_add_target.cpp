#include "leetcode.h"

class Solution {
public:
  string largestNumber(vector<int> &cost, int target) {
    vector<int> dp(target + 1, -10000);
    dp[0] = 0;
    for (int i = 1; i <= target; ++i)
      for (int j = 0; j < 9; ++j)
        dp[i] = max(dp[i], i >= cost[j] ? 1 + dp[i - cost[j]] : -10000);
    if (dp[target] < 0)
      return "0";
    string ans = "";
    for (int i = 8; i >= 0; --i) {
      while (target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
        ans.push_back('1' + i);
        target -= cost[i];
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
  int target = 9;
  cout << obj.largestNumber(cost, target);
}
