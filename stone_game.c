// 877. Stone Game
#include "leetcode.h"

/*
 * alice and bob play a game with piles of stones. there are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones 'piles[i]'. the objective of the game is to end with the most stones.
 * the total number of stones across all piles isodd, so there are no ties.
 * alice and bob take turns, with alice starting first. each turn a player takes
 * the entire pile of stones either from the beginning or from the end of the
 * row. this continues until there are no more piles left, at which point the
 * person with the most stones wins. assuming alice and bob play optimally,
 * return 'true' if alice wins the game, or 'false' if bob wins.
 */

bool stoneGame(int *piles, int piles_size) {
  int **dp = (int **)malloc(sizeof(int *) * piles_size);
  int **sum = (int **)malloc(sizeof(int *) * piles_size);
  for (int i = 0; i < piles_size; i++) {
    dp[i] = (int *)malloc(sizeof(int) * piles_size);
    sum[i] = (int *)malloc(sizeof(int) * piles_size);
    for (int j = 0; j < piles_size; j++)
      if (i == j) {
        dp[i][j] = piles[i];
        sum[i][j] = piles[i];
      }
  }
  for (int l = 2; l <= piles_size; ++l)
    for (int i = 0; i <= piles_size; ++i) {
      int j = i + l - 1;
      sum[i][j] = sum[i][j - 1] + piles[j];
      dp[i][j] = sum[i][j] - fmin(dp[i][j - 1], dp[i + 1][j]);
    }
  bool ans = (dp[0][piles_size - 1] * 2 > sum[0][piles_size - 1]);
  for (int i = 0; i < piles_size; i++)
    free(dp[i]), free(sum[i]);
  free(dp), free(sum);
  return ans;
}

int main() {
  int p1[] = {5, 3, 4, 5}, p2[] = {3, 7, 2, 3};
  printf("%d\n", stoneGame(p1, ARRAY_SIZE(p1))); // expect: 1
  printf("%d\n", stoneGame(p2, ARRAY_SIZE(p2))); // expect: 1
}
