// 704. Binary Search
#include "leetcode.h"

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size() - 1;
    int low = 0, high = n;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  printf("%d\n", obj.search(nums, 9)); // expect: 4
  printf("%d\n", obj.search(nums, 2)); // expect: -1
}
