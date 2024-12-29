// 1639. Number of Ways to Form a Target String Given a Dictionary
#include "leetcode.h"

/*
 * you are given a list of strings of the same length 'words' and a string
 * 'target'. your task is to form 'target' using the given 'words'. notice that
 * you can use multiple characters from the same string in 'words' provided the
 * conditions above are met. return the number of ways to from 'target' from
 * 'words'. since the answer may be too large, return it modulo 10^9+7
 */

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    int n = target.length(), mod = 1e9 + 7;
    vector<long> ans(n + 1);
    ans[0] = 1;
    for (int i = 0; i < words[0].length(); ++i) {
      vector<int> cnt(26);
      for (auto &w : words)
        cnt[w[i] - 'a']++;
      for (int j = n - 1; j >= 0; --j)
        ans[j + 1] += ans[j] * cnt[target[j] - 'a'] % mod;
    }
    return ans[n] % mod;
  }
};

int main() {
  Solution obj;
  vector<string> s1 = {"acca", "bbbb", "caca"}, s2 = {"abba", "baab"};
  string t1 = "aba", t2 = "bab";
  printf("%d\n", obj.numWays(s1, t1)); // expect: 6
  printf("%d\n", obj.numWays(s2, t2)); // expect: 4
}
