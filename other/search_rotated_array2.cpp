// 81. Search in Rotated Sorted Array II
#include "leetcode.h"

/*
 * there is an integer array 'nums' sorted in non-decreasing order (not
 * necessarily with distinct values). before being passed to your function,
 * 'nums' is rotated at an unknown pivot index 'k(0 <= k < nums.length)' such
 * that the resulting array is '[nums[k], nums[k + 1], ..., nums[n - 1],
 * nums[0], nums[1], ..., nums[k - 1]]' (0-indexed). for example
 * '[0,1,2,4,4,4,5,6,6,7]' might be rotated at a pivot index 5 and become
 * '[4,5,6,6,7,0,1,2,4,4]'. given the array 'nums' after the rotation and an
 * integer 'target', return true if 'target' is in 'nums' of 'false' if it is
 * not in 'nums'. you must decrease the overall operation steps as much as
 * possible.
 */

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return true;
      if (nums[left] == nums[mid] && nums[right] == nums[mid])
        left++, right--;
      else if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && nums[mid] > target)
          right = mid - 1;
        else
          left = mid + 1;
      } else {
        if (nums[mid] < target && nums[right] >= target)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  printf("%d\n", obj.search(nums, 0)); // expect: 1
  printf("%d\n", obj.search(nums, 3)); // expect: 0
}
