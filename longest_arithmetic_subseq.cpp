// 1027. Longest Arithmetic Subsequence
#include "leetcode.h"

/*
 * given an array 'nums' of integers, return the length of the longest
 * arithmetic subsequence in 'nums'. note that
 * - a subsequence is an array that can be derived from another array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * - a sequence 'seq' is arithmetic if 'seq[i + 1] - seq[i]' are all the same
 * value (for '0 <= i < seq.len() - 1')
 */

class Solution {
public:
  int longestArithmeticSeqLength(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    vvd(int) dp(n, vector<int>(n, 1));
    for (int i = 1; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j) {
        for (int k = i - 1; k >= 0; k--)
          if (nums[i] - nums[k] == nums[j] - nums[i])
            dp[i][j] = max(dp[i][j], dp[k][i] + 1);
        ans = max(ans, dp[i][j]);
      }
    return ans + 1;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {3, 6, 9, 12}, n2 = {9, 4, 7, 2, 10},
              n3 = {20, 1, 15, 3, 10, 5, 8};
  printf("%d\n", obj.longestArithmeticSeqLength(n1)); // expect: 4
  printf("%d\n", obj.longestArithmeticSeqLength(n2)); // expect: 3
  printf("%d\n", obj.longestArithmeticSeqLength(n3)); // expect: 4
}
