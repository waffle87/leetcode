#include "leetcode.h"

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 10001);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
      for (int jumpLen = 1; jumpLen <= nums[i]; jumpLen++)
        dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);
    return dp[0];
  }
};

int main() {}
