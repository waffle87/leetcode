// 1140. Stone Game II
#include "leetcode.h"

/*
 * alice and bob continue their games with piles of stones. there are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones 'piles[i]'. the objective of the game is to end with the most stones.
 * alice and bob take turns, with alice starting first. initiall, 'M = 1'. on
 * each player's turn, that player can take all the stones on the 'X' remaining
 * piles, where '1 <= X <= 2M'. then, we set 'M = max(M, X)'. the game continues
 * until all the stones have been take. assuming alice and bob play optimally,
 * return maximum stones alice can get.
 */

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int n = piles.size();
    vvd dp(n + 1, vector<int>(n + 1, 0));
    vector<int> sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
      sum[i] = sum[i + 1] + piles[i];
    for (int i = 0; i <= n; i++)
      dp[i][n] = sum[i];
    for (int i = n - 1; i >= 0; i--)
      for (int j = n - 1; j >= 1; j--)
        for (int k = 1; k <= 2 * j && i + j <= n; j++)
          dp[i][j] = max(dp[i][j], sum[i] - dp[i + k][max(j, k)]);
    return dp[0][1];
  }
};

int main() {
  Solution obj;
  vector<int> p1 = {2, 7, 9, 4, 4};
  vector<int> p2 = {1, 2, 3, 4, 5, 100};
  printf("%d\n", obj.stoneGameII(p1)); // expect: 10
  printf("%d\n", obj.stoneGameII(p2)); // expect: 104
}
