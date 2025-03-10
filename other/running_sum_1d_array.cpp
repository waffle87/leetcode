#include "leetcode.h"

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> ans;
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++)
      count += nums[i], ans.push_back(count);
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution obj;
  obj.runningSum(nums);
}
