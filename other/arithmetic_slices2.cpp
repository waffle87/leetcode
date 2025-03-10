#include "leetcode.h"

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    unordered_map<int, vector<int>> num_idx;
    vvd dp(nums.size(), vector<int>(nums.size()));
    int ans = 0;
    for (auto i = 0; i < nums.size(); ++i)
      num_idx[nums[i]].push_back(i);
    for (auto i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; j++) {
        auto prev = 2l * nums[j] - nums[i];
        if (prev < INT_MIN || prev > INT_MAX)
          continue;
        auto it = num_idx.find(prev);
        if (it != end(num_idx)) {
          for (auto k : it->second) {
            if (k >= j)
              break;
            dp[i][j] += dp[j][k] + 1;
          }
        }
        ans += dp[i][j];
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 4, 6, 8, 10};
  cout << obj.numberOfArithmeticSlices(nums);
}
