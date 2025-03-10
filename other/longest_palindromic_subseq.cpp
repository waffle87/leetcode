// 516. Longest Palindromic Subsequence
#include "leetcode.h"

/*
 * given string 's', find the longest palindromic susbsequences
 * of length in 's'. a subsequcnes is a sequence that can be derived
 * from another sequence by deleting some or no elements without
 * changing the order of the remaining elements
 */

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      vector<int> new_dp(n, 0);
      new_dp[i] = 1;
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j])
          new_dp[j] = 2 + dp[j - 1];
        else
          new_dp[j] = max(dp[j], new_dp[j - 1]);
      }
      dp = new_dp;
    }
    return dp[n - 1];
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.longestPalindromeSubseq("bbbab")); // expect: 4
  printf("%d\n", obj.longestPalindromeSubseq("cbbd"));  // expect: 2
}
