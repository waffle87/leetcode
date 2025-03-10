#include "leetcode.h"

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    int k = costs.size();
    vector<int> dp(k + 1, -1);
    sort(costs.begin(), costs.end());
    return dfs(dp, costs, coins, 0, k);
  }

private:
  int dfs(vector<int> &dp, vector<int> &nums, int coins, int i, int k) {
    if (coins <= 0)
      return 0;
    if (i == k - 1) {
      if (nums[i] <= coins)
        return 1;
      else
        return 0;
    }
    if (dp[i] != -1)
      return dp[i];
    int y = 0, n = 0;
    if (nums[i] <= coins)
      y = 1 + dfs(dp, nums, coins - nums[i], i + 1, k);
    n = dfs(dp, nums, coins, i + 1, k);
    return dp[i] = max(y, n);
  }
};

int main() {
  Solution obj;
  vector<int> costs1 = {1, 3, 2, 4, 1}, costs2 = {10, 6, 8, 7, 7, 8},
              costs3 = {1, 6, 3, 1, 2, 5};
  cout << obj.maxIceCream(costs1, 7) << endl;  // expect: 4
  cout << obj.maxIceCream(costs2, 5) << endl;  // expect: 0
  cout << obj.maxIceCream(costs3, 20) << endl; // expect: 6
}
