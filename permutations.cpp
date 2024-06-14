#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    int idx = 0;
    helper(nums, ans, idx);
    return ans;
  }

private:
  void helper(vector<int> &nums, vector<vector<int>> &ans, int idx) {
    if (idx >= nums.size()) {
      ans.push_back(nums);
      return;
    }
    for (int i = idx; i < nums.size(); i++) {
      swap(nums[idx], nums[i]);
      helper(nums, ans, idx + 1);
      swap(nums[idx], nums[i]);
    }
  }
};

int main() {}
