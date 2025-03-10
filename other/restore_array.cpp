// 1416. Restore The Array
#include "leetcode.h"

/*
 * a progamme was supposed to print an array of integers. the programme forgot
 * to print whitespace and the array is printing as a string of digits 's' and
 * all we know is that all integers in the array were in the range [1, k] and
 * there are no leading zeros in the array. given the string 's' and the integer
 * 'k', return the number of possible arrays that can be printed as 's' using
 * the mentioned programme. return modulo 10^9+7
 */

class Solution {
public:
  int numberOfArrays(string s, int k) {
    vector<int> dp(s.size() + 1);
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '0')
        continue;
      for (long sz = 1, n = 0; i + sz <= s.size(); ++sz) {
        n = n * 10 + s[i + sz - 1] - '0';
        if (n > k)
          break;
        dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
      }
    }
    return dp[0];
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.numberOfArrays("1000", 10000)); // expect: 1
  printf("%d\n", obj.numberOfArrays("1000", 10));    // expect: 0
  printf("%d\n", obj.numberOfArrays("1317", 2000));  // expect: 8
}
