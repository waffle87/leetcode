#include "leetcode.h"

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int minJump = 0;
    for (int i = nums.size() - 2; i >= 0; i--) {
      minJump++;
      if (nums[i] >= minJump)
        minJump = 0;
    }
    if (minJump == 0)
      return true;
    else
      return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {2, 3, 1, 1, 4}, nums2 = {3, 2, 1, 0, 4};
  testBool(obj.canJump(nums1)); // true
  testBool(obj.canJump(nums2)); // false
}
