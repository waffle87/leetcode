// 1690. Stone Game VII
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * alice and bob take turns playing a game, with alice starting first. there are
 * 'n' stones arranged in a row. on each player's turn, they can remove either
 * the leftmost stone or the rightmost stone from the row and receive points
 * equal to the sum of the remaining stones' values in the row. the winner is
 * the one with the higher score when there are no stones left to remove. bob
 * found that he will always lose this game (poor bob, he always loses), so he
 * decided to minimise the socre's difference. alice'goal is to maximise the
 * difference in score. given an array of integers 'stones' where 'stones[i]'
 * represents the value of the i'th stone from the left, return the difference
 * in alice and bob's score if they both play optimally.
 */

int stoneGameVII(int *stones, int stones_size) {
  int n = stones_size;
  bool even = !n % 2 ? true : false;
  int **dp = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    dp[i] = malloc(n * sizeof(int));
    dp[i][i] = 0;
  }
  int *sum = malloc((n + 1) * sizeof(int));
  sum[0] = 0;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + stones[i - 1];
  for (int k = 2; k <= n; k++)
    for (int i = 0; i <= n - k; i++) {
      int j = i + k - 1;
      if (even && !k % 2 || !even && k % 2)
        dp[i][j] = fmax(dp[i + 1][j] + sum[j + 1] - sum[i + 1],
                        dp[i][j - 1] + sum[j] - sum[i]);
      else
        dp[i][j] = fmin(dp[i + 1][j] - (sum[j + 1] - sum[i + 1]),
                        dp[i][j - 1] - (sum[j] - sum[i]));
    }
  int ans = dp[0][n - 1];
  for (int i = 0; i < n; i++)
    free(dp[i]);
  free(dp), free(sum);
  return ans;
}

int main() {
  int s1[] = {5, 3, 1, 4, 2}, s2[] = {7, 90, 5, 1, 100, 10, 10, 2};
  printf("%d\n", stoneGameVII(s1, 5)); // expect: 6
  printf("%d\n", stoneGameVII(s2, 8)); // expect: 122
}
