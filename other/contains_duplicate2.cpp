#include "leetcode.h"

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
      if (um.count(nums[i]))
        if (abs(i - um[nums[i]]) <= k)
          return true;
      um[nums[i]] = i;
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 1};
  if (obj.containsNearbyDuplicate(nums, 3))
    cout << "true";
  else
    cout << "false";
}
