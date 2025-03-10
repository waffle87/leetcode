// 2707. Extra Characters in a String
#include "leetcode.h"

/*
 * you are given a 0-indexed string 's' and a dictionary of words 'dictionary'.
 * you have to break 's' into one or more non-overlapping substrings that each
 * substring is present in 'dictionary'. there may be some extra characters in
 * 's' which are not present in any of the substrings. return the minimum number
 * of extra characters left over if you break up 's' optimally
 */

class Solution {
  int mod = 1e7 + 7;
  int hash_func(string s) {
    int res = 0;
    for (auto i : s)
      res = (res * 27 + i - 'a' + 1) % mod;
    return res;
  }
  int min_cost(int l, vector<int> &dp, string s, unordered_set<int> &d) {
    if (l == s.size())
      return 0;
    if (dp[l] != -1)
      return dp[l];
    int res = 1 + min_cost(l + 1, dp, s, d), curr = 0;
    for (int i = l; i < s.size(); i++) {
      curr = (curr * 27 + s[i] - 'a' + 1) % mod;
      if (d.find(curr) != d.end())
        res = min(res, min_cost(i + 1, dp, s, d));
    }
    return dp[l] = res;
  }

public:
  int minExtraChar(string s, vector<string> &dictionary) {
    unordered_set<int> d;
    for (auto i : dictionary)
      d.insert(hash_func(i));
    vector<int> dp(s.size(), -1);
    return min_cost(0, dp, s, d);
  }
};

int main() {
  Solution obj;
  string s1 = "leetscode", s2 = "sayhelloworld";
  vector<string> d1 = {"leet", "code", "leetcode"}, d2 = {"hello", "world"};
  printf("%d\n", obj.minExtraChar(s1, d1)); // expepct: 1
  printf("%d\n", obj.minExtraChar(s2, d2)); // expepct: 3
}
