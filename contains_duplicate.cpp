#include "leetcode.h"

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    bool ans = false;
    for (int i = 0; i < nums.size(); i++)
      for (int j = i + 1; j < nums.size(); j++)
        if (nums[i] == nums[j])
          ans = true;
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {1, 2, 3, 1}, nums2 = {1, 2, 3, 4},
              nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  cout << obj.containsDuplicate(nums1) << endl; // expect: 1
  cout << obj.containsDuplicate(nums2) << endl; // expect: 0
  cout << obj.containsDuplicate(nums3) << endl; // expect: 1
}
