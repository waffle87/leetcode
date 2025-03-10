// 459. Repeated Substring Pattern
#include "leetcode.h"

/*
 * given a string 's', check if it can be constructed by taking a substring of
 * it and appending multiple copies of the substring together.
 */

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int i = 1, j = 0, n = s.size();
    vector<int> dp(n + 1, 0);
    while (i < n) {
      if (s[i] == s[j])
        dp[++i] = ++j;
      else if (!j)
        i++;
      else
        j = dp[j];
    }
    return dp[n] && dp[n] % (n - dp[n]) == 0;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.repeatedSubstringPattern("abab"));         // expect: 1
  printf("%d\n", obj.repeatedSubstringPattern("aba"));          // expect: 0
  printf("%d\n", obj.repeatedSubstringPattern("abcabcabcabc")); // expect: 1
}
