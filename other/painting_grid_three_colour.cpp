// 1931. Painting a Grid With Three Different Colors
#include "leetcode.h"

/*
 * given two integers 'm' and 'n'. consider an 'm x n' grid where each cell is
 * initially white. you can painteach cell red, green, or blue. all cells must
 * be painted. return the number of ways to colour the grid with no two adjacent
 * cells having the same colour.
 */

class Solution {
  int memo[1000][1024] = {};
  vector<int> nei_memo[1024] = {};
  int m, n, mod = 1e9 + 7;
  int dp(int c, int prev) {
    if (c == n)
      return 1;
    if (memo[c][prev])
      return memo[c][prev];
    int res = 0;
    for (int nei : neighbours(prev))
      res = (res + dp(c + 1, nei)) % mod;
    return memo[c][prev] = res;
  }
  vector<int> neighbours(int prev) {
    if (!nei_memo[prev].empty())
      return nei_memo[prev];
    dfs(0, prev, 0, nei_memo[prev]);
    return nei_memo[prev];
  }
  void dfs(int r, int prev, int curr, vector<int> &out) {
    if (r == m) {
      out.push_back(curr);
      return;
    }
    for (int i = 0; i <= 3; i++)
      if (get_colour(prev, r) != i && (!r || get_colour(curr, r - 1) != i))
        dfs(r + 1, prev, set_colour(curr, r, i), out);
  }
  int get_colour(int mask, int pos) { return (mask >> (2 * pos)) & 3; }
  int set_colour(int mask, int pos, int colour) {
    return mask | (colour << (2 * pos));
  }

public:
  int colorTheGrid(int m, int n) {
    this->m = m;
    this->n = n;
    return dp(0, 0);
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.colorTheGrid(1, 1)); // expect: 3
  printf("%d\n", obj.colorTheGrid(1, 2)); // expect: 6
  printf("%d\n", obj.colorTheGrid(5, 5)); // expect: 580986
}
