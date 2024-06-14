// 518. Coin Change II
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'coins' representing cons of different denominations
 * and an integer 'amount' representing a total amount of money. return the
 * number of combinations that make up the amount. if that amount of money
 * cannot be made up by any combination the coins, return 0. you may assume that
 * you have an infinite number of each kind of coin. the answer is guaranteed to
 * fit into a signed 32-bit integer.
 */

int change(int amount, int *coins, int coins_size) {
  if (!coins_size) {
    if (!amount)
      return 1;
    return 0;
  }
  int *dp = (int *)calloc(amount + 1, sizeof(int));
  dp[0] = 1;
  for (int i = 0; i < coins_size; i++)
    for (int j = coins[i]; j < amount + 1; j++)
      dp[j] += dp[j - coins[i]];
  return dp[amount];
}

int main() {
  int c1[] = {1, 2, 5}, c2[] = {2}, c3[] = {10};
  printf("%d\n", change(5, c1, 3));  // expect: 4
  printf("%d\n", change(3, c2, 1));  // expect: 0
  printf("%d\n", change(10, c3, 1)); // expect: 1
}
