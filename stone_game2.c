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

int stoneGameII(int *piles, int pilesSize) {
  int **dp = (int **)malloc(pilesSize * sizeof(int *));
  for (int i = 0; i < pilesSize; i++)
    dp[i] = (int *)calloc(pilesSize + 1, sizeof(int));
  int *suffix = (int *)malloc(pilesSize * sizeof(int));
  suffix[pilesSize - 1] = piles[pilesSize - 1];
  for (int i = pilesSize - 2; i >= 0; i--)
    suffix[i] = suffix[i + 1] + piles[i];
  for (int i = pilesSize - 1; i >= 0; i--)
    for (int j = 1; j <= pilesSize; j++) {
      if (i + 2 * j >= pilesSize)
        dp[i][j] = suffix[i];
      else
        for (int k = 1; k <= 2 * j; k++)
          dp[i][j] = fmax(dp[i][j], suffix[i] - dp[i + k][(int)fmax(j, k)]);
    }
  int ans = dp[0][1];
  for (int i = 0; i < pilesSize; i++)
    free(dp[i]);
  free(dp);
  free(suffix);
  return ans;
}

int main() {
  int p1[] = {2, 7, 9, 4, 4};
  int p2[] = {1, 2, 3, 4, 5, 100};
  int r1 = stoneGameII(p1, ARRAY_SIZE(p1));
  int r2 = stoneGameII(p2, ARRAY_SIZE(p2));
  printf("%d\n", r1);
  assert(r1 == 10);
  printf("%d\n", r2);
  assert(r2 == 104);
}
