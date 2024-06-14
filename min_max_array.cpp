// 2439. Minimize Maximum of Array
#include "leetcode.h"

/*
 * given a 0-indexed array 'nums' comprising of n unsigned integers. ine one
 * operation you must choose an integer 'i' such that '1 <= i < n' and 'nums[i]
 * > 0'. decrease 'nums[i]' by 1 or increase 'nums[i]' by 1. return minimum
 * possible value of the max integer 'nums' after performing any number of
 * operations.
 */

class Solution {
  bool valid(vector<int> &nums, int mid) {
    long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum > (long)mid * (i + 1))
        return false;
    }
    return true;
  }

public:
  int minimizeArrayValue(vector<int> &nums) {
    int left = 0, right = *max_element(nums.begin(), nums.end()), ans = 0;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (valid(nums, mid)) {
        ans = mid;
        right = mid - 1;
      } else
        left = mid + 1;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {3, 7, 1, 6}, n2 = {10, 1};
  printf("%d\n", obj.minimizeArrayValue(n1)); // expect: 5
  printf("%d\n", obj.minimizeArrayValue(n2)); // expect: 10
}
