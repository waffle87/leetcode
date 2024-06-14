#include "leetcode.h"

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int target = 1; target <= n; target++) {
      int mmCount = INT_MAX;
      for (int num = 1; num <= sqrt(target); num++) {
        int sqNum = pow(num, 2), curr = 1 + dp[target - sqNum];
        mmCount = min(mmCount, curr);
      }
      dp[target] = mmCount;
    }
    return dp[n];
  }
};

int main() {
  Solution obj;
  cout << obj.numSquares(12);
}
