#include "leetcode.h"

class Solution {
public:
  int countSubstrings(string s) {
    this->s = s;
    int ans = 0, n = s.size();
    dp.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++)
        ans += helper(i, j, s);
    return ans;
  }

private:
  vector<vector<int>> dp;
  // string s = "abc";
  int helper(int l, int r, string s) {
    if (l > r || l == r)
      return 1;
    if (dp[l][r] != -1)
      return dp[l][r];
    if (s[l] != s[r])
      return dp[l][r] = 0;
    if (helper(l + 1, r - 1, s))
      return dp[l][r] = 1;
    return dp[l][r] = 0;
  }
};

int main() {}
