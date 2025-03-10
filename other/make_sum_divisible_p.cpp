// 1590. Make Sum Divisible by P
#include "leetcode.h"

/*
 * given an array of positive integers 'nums', remove the smallest subarray
 * (possibly empty) such that the sum of the remaining elements is divisible by
 * 'p'. it is not allowed to remove the whole array. return the length of the
 * smallest subarray that you need to remove, or -1 if it is impossible. a
 * subarray is defined as a contiguous block of elements in the array.
 */

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    int n = nums.size(), ans = n, req = 0, curr = 0;
    for (auto i : nums)
      req = (req + i) % p;
    unordered_map<int, int> dp = {{0, -1}};
    for (int i = 0; i < n; i++) {
      curr = (curr + nums[i]) % p;
      dp[curr] = i;
      int need = (curr - req + p) % p;
      if (dp.count(need))
        ans = min(ans, i - dp[need]);
    }
    return ans < n ? ans : -1;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {3, 1, 4, 2}, n2 = {6, 3, 5, 2}, n3 = {1, 2, 3};
  printf("%d\n", obj.minSubarray(n1, 6)); // expect: 1
  printf("%d\n", obj.minSubarray(n2, 9)); // expect: 2
  printf("%d\n", obj.minSubarray(n3, 3)); // expect: 0
}
