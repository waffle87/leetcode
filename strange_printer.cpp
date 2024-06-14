// 664. Strange Printer
#include "leetcode.h"

/*
 * there is a strange printer with the following two special properties:
 * - the printer can only print a sequence of the same character each time
 * - at each turn, the printer can print new characters starting from and eding
 * at any place and will cover the origin existing characters given a string
 * 's', return the minimum number of turns the printer needed to print it.
 */

class Solution {
public:
  int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n));
    for (int i = n - 1; i >= 0; i--)
      for (int j = i; j < n; j++) {
        dp[i][j] = 1 + dp[i + 1][j];
        for (int k = i + 1; k <= j; k++)
          if (s[k] == s[i])
            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
      }
    return dp[0][n - 1];
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.strangePrinter("aaabbb")); // expect: 2
  printf("%d\n", obj.strangePrinter("aba"));    // expect: 2
}
