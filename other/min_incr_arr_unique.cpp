// 945. Minimum Increment to Make Array Unique
#include "leetcode.h"

/*
 * given an integer array 'nums'. in one move, you can pick an index 'i' where
 * '0 <= i  < nums.length' and increment 'nums[i]' by 1. return the minimum
 * number of moves to make every value in 'nums' unique. the test cases are
 * generated so that the answer fits in a 32-bit integer.
 */

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    if (n < 2)
      return 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i)
      if (nums[i] <= nums[i - 1]) {
        ans += nums[i - 1] + 1 - nums[i];
        nums[i] = nums[i - 1] + 1;
      }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2, 2}, n2 = {3, 2, 1, 2, 1, 7};
  printf("%d\n", obj.minIncrementForUnique(n1)); // expect: 1
  printf("%d\n", obj.minIncrementForUnique(n2)); // expect: 6
}
