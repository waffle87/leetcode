#include "leetcode.h"

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
  }

private:
  int helper(vector<int> &nums, int l, int r) {
    if (l > r)
      return INT_MIN;
    int m = l + (r - l) / 2, mL = 0, mR = 0;
    int lMax = helper(nums, l, m - 1);
    int rMax = helper(nums, m + 1, r);
    for (int i = m - 1, sum = 0; i >= l; i--) {
      sum += nums[i];
      mL = max(sum, mL);
    }
    for (int i = m + 1, sum = 0; i <= r; i++) {
      sum += nums[i];
      mR = max(sum, mR);
    }
    return max(max(lMax, rMax), mL + mR + nums[m]);
  }
};

int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution obj;
  cout << obj.maxSubArray(nums);
}
