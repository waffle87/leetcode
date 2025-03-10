#include "leetcode.h"

class Solution {
public:
  int numTrees(int n) {
    if (n == 1)
      return 1;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        int k = i - 1 - j;
        dp[i] += (dp[j] * dp[k]);
      }
    }
    return dp[n];
  }
};

int main() {
  Solution obj;
  cout << obj.numTrees(3);
}
