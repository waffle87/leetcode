// 1140. Stone Game II
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

int stoneGameII(int *piles, int piles_size) {
  int n = piles_size;
  int *sum = malloc((n + 1) * sizeof(int));
  int **dp = malloc((n + 1) * sizeof(int *));
  for (int i = 0; i <= n; i++)
    dp[i] = calloc(n + 1, sizeof(int));
  sum[n] = 0;
  for (int i = n - 1; i >= 0; i--)
    sum[i] = sum[i + 1] + piles[i];
  for (int i = 0; i < n; ++i)
    dp[i][n] = sum[i];
  for (int i = n - 1; i >= 0; i--)
    for (int m = n - 1; m >= 1; m--)
      for (int x = 1; x <= 2 * m && i + x <= n; ++x)
        dp[i][m] = fmax(dp[i][m], sum[i] - dp[i + x][(int)fmax(m, x)]);
  int ans = dp[0][1];
  for (int i = 0; i <= n; i++)
    free(dp[i]);
  free(dp);
  free(sum);
  return ans;
}

int main() {
  int p1[] = {2, 7, 9, 4, 4};
  int p2[] = {1, 2, 3, 4, 5, 100};
  printf("%d\n", stoneGameII(p1, 5)); // expect: 10
  printf("%d\n", stoneGameII(p2, 6)); // expect: 104
}
