#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
  }

  vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
    vector<vector<int>> result;
    if (start == nums.size())
      return result;
    int avgVal = target / k;
    if (nums[start] > avgVal || avgVal > nums.back())
      return result;
    if (k == 2)
      return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i) {
      if (i == start || nums[i - 1] != nums[i]) {
        for (vector<int> &subset :
             kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
          result.push_back({nums[i]});
          result.back().insert(end(result.back()), begin(subset), end(subset));
        }
      }
    }
    return result;
  }

  vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> result;
    int low = start, high = nums.size() - 1;
    while (low < high) {
      int currSum = nums[low] + nums[high];
      if (currSum < target || (low > start && nums[low] == nums[low - 1]))
        ++low;
      else if (currSum > target ||
               (high < nums.size() - 1 && nums[high] == nums[high + 1]))
        --high;
      else
        result.push_back({nums[low++], nums[high--]});
    }
    return result;
  }
};

int main() {}
