#include "leetcode.h"

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int m = amount + 1;
    vector<int> dp(amount + 1, m);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
      for (int j = 0; j < coins.size(); j++)
        if (coins[j] <= i)
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  Solution obj;
  cout << obj.coinChange(coins, amount);
}
