// 279. Perfect Squares
#include "leetcode.h"

/*
 * given an integer 'n', return the least number of perfect square numbers that
 * sum to 'n'. a perfect square is an integer that is the square of an integer;
 * in other words, it is the product of some integer with itself. for example,
 * 1,4,9,16 are perfect squares while 3 and 11 are not.
 */

int numSquares(int n) {
  int *dp = (int *)malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; i++)
    dp[i] = INT_MAX;
  dp[0] = INT_MAX;
  if (n > 0)
    dp[1] = 1;
  if (n > 1)
    dp[2] = 2;
  if (n > 2)
    dp[3] = 3;
  if (n > 3)
    dp[4] = 1;
  int k, tmp;
  for (int i = 5; i <= n; i++) {
    k = sqrt(i);
    if (k * k == i) {
      dp[i] = 1;
      continue;
    }
    for (int j = 1; j <= k; j++) {
      tmp = j * j;
      if (dp[tmp] + dp[i - tmp] < dp[i])
        dp[i] = dp[tmp] + dp[i - tmp];
    }
  }
  int ans = dp[n];
  free(dp);
  return ans;
}

int main() {
  printf("%d\n", numSquares(12)); // expect: 3
  printf("%d\n", numSquares(13)); // expect: 2
}
