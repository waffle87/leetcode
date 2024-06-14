// 2369. Check if There is a Valid Partition For The Array
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums', you have to partition the array into
 * one or more contiguous subarrays. we call a partition of the array valid if
 * each of the obtained subarrays satisfies one of the following conditions
 * - the subarray consists of exactly 2 equal elements. for example, the
 * subarray '[2,2]' is good.
 * - the subarray consists of exactly 3 equal elements. for example, the
 * subarray '[4,4,4]' is good.
 * - the subarray consists of exactly 3 consecutive increasing elements, that
 * is, the difference between adjacent elements is 1. for example, the subarray
 * '[3,4,5]' is good, but the subarray '[1,3,5]' is not. return true if the
 * array has at least one valid partition. otherwise, return false.
 */

class Solution {
  bool solve(vector<int> &nums, int i, vector<int> &dp) {
    if (nums.size() == i)
      return true;
    if (dp[i] != -1)
      return dp[i];
    if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
      if (solve(nums, i + 2, dp))
        return true;
      if (i + 2 < nums.size() && nums[i] == nums[i + 2])
        if (solve(nums, i + 3, dp))
          return true;
    }
    if (i + 2 < nums.size() && nums[i] == nums[i + 1] - 1 &&
        nums[i] == nums[i + 2] - 2)
      if (solve(nums, i + 3, dp))
        return true;
    return !dp[i];
  }

public:
  bool validPartition(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return solve(nums, 0, dp);
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {4, 4, 4, 5, 6}, n2 = {1, 1, 1, 2};
  printf("%d\n", obj.validPartition(n1)); // expect: 1
  printf("%d\n", obj.validPartition(n2)); // expect: 0
}
