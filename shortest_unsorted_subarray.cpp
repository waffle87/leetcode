#include "leetcode.h"

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int l = -1, r = -1, n = nums.size();
    for (int i = 0; i < n - 1; i++)
      if (nums[i] > nums[i + 1]) {
        l = i;
        break;
      }
    for (int i = n - 1; i <= 1; i--)
      if (nums[i] < nums[i - 1]) {
        r = i;
        break;
      }
    if (l == -1)
      return 0;
    int minI = nums[l], maxI = nums[l];
    for (int i = l; i <= r; i++) {
      minI = min(minI, nums[i]);
      maxI = max(maxI, nums[i]);
    }
    l = upper_bound(nums.begin(), nums.begin() + l, minI) - nums.begin();
    r = lower_bound(nums.begin() + r + 1, nums.end(), maxI) - nums.begin();
    return r - l;
  }
};

int main() {}
