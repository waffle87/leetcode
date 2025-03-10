// 2289. Steps to Make Array Non-decreasing
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums'. in one step, remofe all elements
 * 'nums[i]' where 'nums[i - 1] > nums[i]' for all '0 < i < nums.size()'. return
 * the number of steps performed until 'nums' becomes non-decreasing
 */

class Solution {
public:
  int totalSteps(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    vector<int> stack, dp(n);
    for (int i = n - 1; i >= 0; --i) {
      while (!stack.empty() && nums[i] > nums[stack.back()]) {
        dp[i] = max(++dp[i], dp[stack.back()]);
        stack.pop_back();
        ans = max(ans, dp[i]);
      }
      stack.push_back(i);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11}, n2 = {4, 5, 7, 7, 13};
  printf("%d\n", obj.totalSteps(n1)); // expect: 3
  printf("%d\n", obj.totalSteps(n2)); // expect: 0
}
