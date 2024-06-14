#include "leetcode.h"
#define lli long long int

class Solution {
public:
  int countOrders(int n) {
    lli mod = 1e9 + 7;
    vector<lli> dp(n + 2);
    dp[1] = 1;
    dp[2] = 6;
    for (lli i = 3; i <= n; i++) {
      lli x = 2 * i - 1;
      lli combs = x * (x + 1) / 2;
      dp[i] = (dp[i - 1] * combs) % mod;
    }
    return dp[n];
  }
};

int main() {
  Solution obj;
  cout << obj.countOrders(2);
}
