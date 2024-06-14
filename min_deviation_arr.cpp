// 1675. Minimize Deviation in Array
#include "leetcode.h"

/*
 * the deviation of the array is the maximum difference between any two elements
 * in the array. return minimum deviation the array can have after performing
 * 'nums' ops.
 */

class Solution {
public:
  int minimumDeviation(vector<int> nums) {
    int ans = INT_MAX, min_nums = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      nums[i] = nums[i] % 2 ? nums[i] * 2 : nums[i];
      min_nums = min(min_nums, nums[i]);
    }
    make_heap(begin(nums), end(nums));
    while (nums[0] % 2 == 0) {
      ans = min(ans, nums[0] - min_nums);
      min_nums = min(min_nums, nums[0] / 2);
      pop_heap(begin(nums), end(nums));
      nums.back() /= 2;
      push_heap(begin(nums), end(nums));
    }
    return min(ans, nums[0] - min_nums);
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2, 3, 4}, n2 = {4, 1, 5, 20, 3}, n3 = {2, 10, 8};
  cout << obj.minimumDeviation(n1) << endl; // expect: 1
  cout << obj.minimumDeviation(n2) << endl; // expect: 3
  cout << obj.minimumDeviation(n3) << endl; // expect: 3
}
