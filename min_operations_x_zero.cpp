#include "leetcode.h"

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    unordered_map<int, int> left;
    int ans = INT_MAX;
    for (auto i = 0, sum = 0; i < nums.size() && sum <= x; ++i) {
      left[sum] = i;
      sum += nums[i];
    }
    for (int i = nums.size() - 1, sum = 0; i >= 0 && sum <= x; --i) {
      auto it = left.find(x - sum);
      if (it != end(left) && i + 1 >= it->second)
        ans = min(ans, (int)nums.size() - i - 1 + it->second);
      sum += nums[i];
    }
    return ans = INT_MAX ? -1 : ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 4, 2, 3};
  int x = 5;
  cout << obj.minOperations(nums, x);
}
