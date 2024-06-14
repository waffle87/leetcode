#include "leetcode.h"

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int ans = 0;
    unordered_set<int> us;
    for (int i = 0, j = 0, win = 0; j < nums.size(); j++) {
      while (us.find(nums[j]) != us.end()) {
        us.erase(nums[i]);
        win -= nums[i];
        i++;
      }
      us.insert(nums[j]);
      win += nums[j];
      ans = max(ans, win);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
  cout << obj.maximumUniqueSubarray(nums);
}
