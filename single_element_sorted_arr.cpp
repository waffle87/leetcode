// 540. Single Element in a Sorted Array
#include "leetcode.h"

/*
 * given a sorted array consisting of only integers where very element appears
 * exactly twice, except for one element which appears exactly once. return the
 * single element that appears only once. solution func must be o(ln) time and
 * o(1) space complexity.
 */

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int low = 0, high = nums.size() - 1, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if ((mid % 2 && nums[mid - 1] == nums[mid]) ||
          (!(mid % 2) && nums[mid] == nums[mid + 1]))
        low = mid + 1;
      else
        high = mid;
    }
    return nums[low];
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8},
              nums2 = {3, 3, 7, 7, 10, 11, 11};
  cout << obj.singleNonDuplicate(nums1) << endl; // expect: 2
  cout << obj.singleNonDuplicate(nums2) << endl; // expect: 10
}
