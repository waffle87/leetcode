#include "leetcode.h"

/*
 * given: 0-indexed integer array
 * bad pair: (i, j) if
 * i < j && j - i != nums[j] - nums[i]
 */

class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    long long ans = 0;
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); ++i) {
      ans += (long long)i - um[nums[i] - i];
      ++um[nums[i] - i];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {4, 1, 3, 3}, nums2 = {1, 2, 3, 4, 5};
  cout << obj.countBadPairs(nums1) << endl; // expect: 5
  cout << obj.countBadPairs(nums2) << endl; // expect: 0
}
