// 518. Coin Change II
#include "leetcode.h"

/*
 * given an integer array 'coins' representing cons of different denominations
 * and an integer 'amount' representing a total amount of money. return the
 * number of combinations that make up the amount. if that amount of money
 * cannot be made up by any combination the coins, return 0. you may assume that
 * you have an infinite number of each kind of coin. the answer is guaranteed to
 * fit into a signed 32-bit integer.
 */

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i : coins)
      for (int j = i; j <= amount; j++)
        dp[j] += dp[j - i];
    return dp[amount];
  }
};

int main() {
  Solution obj;
  vector<int> c1 = {1, 2, 5}, c2 = {2}, c3 = {10};
  printf("%d\n", obj.change(5, c1));  // expect: 4
  printf("%d\n", obj.change(3, c2));  // expect: 0
  printf("%d\n", obj.change(10, c3)); // expect: 1
}
