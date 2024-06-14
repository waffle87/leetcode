#include "leetcode.h"

class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] == target)
        ans = min(ans, abs(i - start));
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 5, start = 3;
  // expect 1
  cout << obj.getMinDistance(nums, target, start);
}
