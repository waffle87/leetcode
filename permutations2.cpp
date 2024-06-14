#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    helper(0, nums, ans);
    return ans;
  }

private:
  void helper(int i, vector<int> &nums, vector<vector<int>> &ans) {
    if (i == nums.size()) {
      ans.emplace_back(nums);
      return;
    }
    unordered_set<int> us;
    for (int j = i; j < nums.size(); j++) {
      if (us.count(nums[j]) == 1)
        continue;
      us.insert(nums[j]);
      swap(nums[i], nums[j]);
      helper(i + 1, nums, ans);
      swap(nums[i], nums[j]);
    }
  }
};

int main() {}
