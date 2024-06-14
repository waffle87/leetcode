#include "leetcode.h"

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int tLeft = find(target, nums);
    if (tLeft == nums.size() || nums[tLeft] != target)
      return {-1, -1};
    return {tLeft, find(target + 1, nums, tLeft) - 1};
  }
  int find(int target, vector<int> arr, int left = 0) {
    int right = arr.size() - 1;
    while (left <= right) {
      int mid = left + right >> 1;
      if (arr[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left;
  }
};
