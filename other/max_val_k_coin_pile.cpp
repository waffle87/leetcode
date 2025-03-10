// 2218. Maximum Value of K Coins From Piles
#include "leetcode.h"

/*
 * there are 'n' piles of coins on a table. each pile consists of a positive
 * number of coins of assorted denominations. in one move you can choose any
 * coin on top of a pile remove it and add it to your wallet. given a list of
 * 'piles' where 'piles[i]' is a list of integers denoting the composition of
 * the i'th pile from top to bottom, and a positive integer 'k', return the
 * maximum total values of coins you can have in your wallet if you choose
 * exactly 'k' coins optimally.
 */

class Solution {
public:
  int maxValueOfCoins(vvd & piles, int k) {
    int n = piles.size(), m[1001][2001] = {};
    memset(m, -1, sizeof(m));
    function<int(int, int)> dp = [&](int i, int j) {
      if (m[i][j] != -1)
        return m[i][j];
      if (i == n)
        return 0;
      int ans = dp(i + 1, j), sum = 0;
      for (int k = 1; k <= j && k <= piles[i].size(); ++k) {
        sum += piles[i][k - 1];
        ans = max(ans, dp(i + 1, j - k) + sum);
      }
      return m[i][j] = ans;
    };
    return dp(0, k);
  }
};

int main() {
  Solution obj;
  vvd
      p1 = {{1, 100, 3}, {7, 8, 9}},
      p2 = {{100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}};
  printf("%d\n", obj.maxValueOfCoins(p1, 2)); // expect: 101
  printf("%d\n", obj.maxValueOfCoins(p2, 7)); // expect: 706
}
