// 837. New 21 Game
#include "leetcode.h"

/*
 * alice plays the following game, loosely based on the card game "21". alice
 * starts with 0 points and draws numbers while she has less than 'k' points.
 * during each draw, she gains an integer number of points randomly from range
 * '[1, maxPts]', where 'maxPts' is an integer. each draw is independent and
 * the outcomes have equal posibilities. alice stops drawing numbers when she
 * gets 'k' or more points. return the probability that alice has 'n' or fewer
 * points. answers within 10^-5 of the actual answer are considered accepted
 */

double new21Game(int n, int k, int maxPts) {
  if (!k || n >= k + maxPts)
    return 1.0;
  double *dp = (double *)malloc((n + 1) * sizeof(double));
  dp[0] = 1.0;
  double sum = 1.0, ans = 0.0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = sum / maxPts;
    if (i < k)
      sum += dp[i];
    else
      ans += dp[i];
    if (i - maxPts >= 0)
      sum -= dp[i - maxPts];
  }
  free(dp);
  return ans;
}

int main() {
  printf("%f\n", new21Game(10, 1, 10));  // expect: 1.00000
  printf("%f\n", new21Game(6, 1, 10));   // expect: 0.60000
  printf("%f\n", new21Game(21, 17, 10)); // expect: 0.73278
}
