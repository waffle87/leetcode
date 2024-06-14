#include "leetcode.h"

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; ++i) {
      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum3 = nums[i] + nums[left] + nums[right];
        if (abs(ans - target) > abs(sum3 - target))
          ans = sum3;
        if (sum3 == target)
          break;
        if (sum3 > target)
          --right;
        else
          ++left;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {-1, 2, 1, -4};
  int target = 1;
  cout << obj.threeSumClosest(nums, target);
}
