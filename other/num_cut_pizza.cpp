// 1444. Number of Ways of Cutting a Pizza
#include "leetcode.h"

/*
 * given rectangular pizza represented as a rows x cols matrix containing the
 * following characters 'A' an apple and '.' empty cell, and given integer 'k'.
 * you have to cut the pizza into 'k' pieces using 'k - 1' cuts.
 */

class Solution {
  void add(long &a, long &b) { a = (a + b) % (1e9 + 7); }

public:
  int ways(vector<string> &pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    vvd cnt(m + 1, vector<int>(n + 1));
    for (int i = m - 1; i >= 0; --i) {
      int s = 0;
      for (int j = n - 1; j >= 0; --j) {
        s += pizza[i][j] == 'A';
        cnt[i][j] = cnt[i + 1][j] + s;
      }
    }
    vvd(vector<long>) dp(m + 1, vvd(long)(n + 1, vector<long>(k + 1)));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j][1] = cnt[i][j] > 0;
        for (int p = 2; p <= k; ++p) {
          for (int q = i + 1; q < m; ++q) {
            if (cnt[i][j] == cnt[q][j])
              continue;
            if (cnt[q][j] == 0)
              break;
            add(dp[i][j][p], dp[q][j][p - 1]);
          }
          for (int q = j + 1; q < n; ++q) {
            if (cnt[i][j] == cnt[i][q])
              continue;
            if (cnt[i][q] == 0)
              break;
            add(dp[i][j][p], dp[i][q][p - 1]);
          }
        }
      }
    }
    return dp[0][0][k];
  }
};

int main() {
  Solution obj;
  vector<string> p1 = {"A..", "AAA", "..."};
  vector<string> p2 = {"A..", "AA.", "..."};
  vector<string> p3 = {"A..", "A..", "..."};
  printf("%d\n", obj.ways(p1, 3)); // expect: 3
  printf("%d\n", obj.ways(p2, 3)); // expect: 1
  printf("%d\n", obj.ways(p3, 1)); // expect: 1
}
