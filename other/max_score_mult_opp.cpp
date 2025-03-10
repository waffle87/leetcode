#include "leetcode.h"

class Solution {
public:
  int maximumScore(vector<int> &nums, vector<int> &multipliers) {
    n = nums.size();
    m = multipliers.size();
    memset(memo, -1, sizeof(memo));
    return dp(0, 0, nums, multipliers);
  }

private:
  int m, n, memo[1000][1000];
  int dp(int l, int i, vector<int> &nums, vector<int> &multipliers) {
    if (i == m)
      return 0;
    if (memo[l][i] != -1)
      return memo[l][i];
    int pickLeft =
        dp(l + 1, i + 1, nums, multipliers) + nums[l] * multipliers[i];
    int pickRight = dp(l, i + 1, nums, multipliers) +
                    nums[n - (i - l) - 1] * multipliers[i];
    return memo[l][i] = max(pickLeft, pickRight);
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3}, multipliers = {3, 2, 1};
  cout << obj.maximumScore(nums, multipliers);
}
