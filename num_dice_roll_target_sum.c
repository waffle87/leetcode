// 1155. Number of Dice Rolls With Target Sum
#include "leetcode.h"

/*
 * you have 'n' dice and die has 'k' faces numbered 1 to 'k'. given three
 * integers 'n', 'k', and 'target', return the number of possible ways to roll
 * the dice so the sum of the face up numbers equals 'target'. since the answer
 * may be too large, return it modulo 10e9+7
 */

int numRollsToTarget(int n, int k, int target) {
  int mod = 1e9 + 7;
  int **dp = malloc((n + 1) * sizeof(int *));
  for (int i = 0; i <= n; i++)
    dp[i] = calloc(target + 1, sizeof(int));
  for (int i = 1; i <= target; i++) {
    if (i > k)
      break;
    dp[1][i] = 1;
  }
  for (int i = 2; i <= n; i++)
    for (int j = i; j <= target; j++) {
      if (j > i * k)
        break;
      int sum = 0;
      for (int m = 1; m <= k; m++) {
        if (j - m < 0)
          break;
        sum = (sum + dp[i - 1][j - m] % mod);
      }
      dp[i][j] = sum;
    }
  return dp[n][target];
}

int main() {
  printf("%d\n", numRollsToTarget(1, 6, 3));     // expect: 1
  printf("%d\n", numRollsToTarget(2, 6, 7));     // expect: 6
  printf("%d\n", numRollsToTarget(30, 30, 500)); // expect: 222616187
}
