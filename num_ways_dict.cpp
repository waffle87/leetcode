// 1639. Number of Ways to Form a Target String Given a Dictionary
#include "leetcode.h"

class Solution {
  int dp[1001][1001] = {};
  int dfs(vvd(int) cnt, string target, int i, int j) {
    if (j >= target.size())
      return 1;
    if (!dp[i][j]) {
      dp[i][j] = 1;
      for (int k = i; k + (target.size() - j) <= cnt.size(); ++k)
        if (cnt[k][target[j] - 'a'])
          dp[i][j] =
              ((long)cnt[k][target[j] - 'a'] * dfs(cnt, target, k + 1, j + 1) +
               dp[i][j]) %
              1000000007;
    }
    return dp[i][j] - 1;
  }

public:
  int numWays(vector<string> &words, string target) {
    vvd(int) cnt(words[0].size(), vector<int>(26));
    for (auto w : words)
      for (auto i = 0; i < w.size(); ++i)
        ++cnt[i][w[i] - 'a'];
    return dfs(cnt, target, 0, 0);
  }
};

int main() {
  Solution obj;
  vector<string> s1 = {"acca", "bbbb", "caca"}, s2 = {"abba", "baab"};
  string t1 = "aba", t2 = "bab";
  printf("%d\n", obj.numWays(s1, t1)); // expect: 6
  printf("%d\n", obj.numWays(s2, t2)); // expect: 4
}
