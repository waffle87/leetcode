// 712. Minimum ASCII Delete Sum for Two Strings
#include "leetcode.h"

/*
 * given two strings 's1' and 's2', return the lowest ascii sum of the deleted
 * characters to make two strings equal
 */

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size(), sum1 = 0, sum2 = 0;
    int dp[n + 1][m + 1];
    for (int i = 0; i < n; i++)
      sum1 += s1[i];
    for (int i = 0; i < m; i++)
      sum2 += s2[i];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
        if (!i || !j)
          dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    int ans = dp[n][m];
    return sum1 + sum2 - 2 * ans;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.minimumDeleteSum("sea", "eat"));     // expect: 231
  printf("%d\n", obj.minimumDeleteSum("delete", "leet")); // expect: 403
}
