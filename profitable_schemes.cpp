// 879. Profitable Schemes
#include "leetcode.h"

/*
 * there is a group of 'n' members, and a list of various crimes
 * they could commit. the i'th crime generates a 'profit[i]' and
 * requires 'group[i]' members to participate in it. if a member
 * participates in one crime, that member cannot participate in
 * another crime. a profitable scheme is any subset of these crimes
 * that generates at least 'min_profit', and the total number of
 * members participating in that subset of crimes is at most 'n'
 * return the number of schemes that can be chosen.
 */

struct scheme {
  int n;
  int min_profit;
  vector<int> group;
  vector<int> profit;
};

class Solution {
  vector<int> g, p;
  int mp, mod = 1e9 + 7, dp[101][101][101];
  int find(int id, int n, int total_profit) {
    if (id == p.size())
      return 0;
    if (dp[id][n][total_profit != -1])
      return dp[id][n][total_profit];
    int res = 0;
    if (n >= g[id]) {
      int new_profit = max(0, total_profit - p[id]);
      if (new_profit <= 0)
        res += (1 + find(id + 1, n - g[id], new_profit) % mod) % mod;
      else
        res += find(id + 1, n - g[id], new_profit) % mod;
    }
    res %= mod;
    res += find(id + 1, n, total_profit) % mod;
    res %= mod;
    return dp[id][n][total_profit] = res % mod;
  }

public:
  int profitableSchemes(int n, int min_profit, vector<int> &group,
                        vector<int> &profit) {
    mp = min_profit;
    p = profit;
    g = group;
    for (int i = 0; i < 101; i++)
      for (int j = 0; j < 101; j++)
        for (int k = 0; k < 101; k++)
          dp[i][j][k] = -1;
    int ans = find(0, n, mp) % mod;
    if (!mp)
      ans++;
    ans %= mod;
    return ans;
  }
};

int main() {
  Solution obj;
  scheme one = {.n = 5, .min_profit = 3, .group = {2, 2}, .profit = {2, 3}};
  scheme two = {
      .n = 10, .min_profit = 5, .group = {2, 3, 5}, .profit = {6, 7, 8}};
  printf("%d\n", obj.profitableSchemes(one.n, one.min_profit, one.group,
                                       one.profit)); // expect: 2
  printf("%d\n", obj.profitableSchemes(two.n, two.min_profit, two.group,
                                       two.profit)); // expect: 7
}
