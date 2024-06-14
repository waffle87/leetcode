// 837. New 21 Game
#include "leetcode.h"

/*
 * alice plays the following game, loosely based on the card game "21". alice
 * starts with 0 points and draws numbers while she has less than 'k' points.
 * during each draw, she gains an integer number of points randomly from range
 * '[1, max_pts]', where 'max_pts' is an integer. each draw is independent and
 * the outcomes have equal posibilities. alice stops drawing numbers when she
 * gets 'k' or more points. return the probability that alice has 'n' or fewer
 * points. answers within 10^-5 of the actual answer are considered accepted
 */

class Solution {
public:
  double new21Game(int n, int k, int max_pts) {
    if (!k || n >= k + max_pts)
      return 1.0;
    vector<double> dp(n + 1);
    dp[0] = 1.0;
    double sum = 1.0, ans = 0.0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = sum / max_pts;
      if (i < k)
        sum += dp[i];
      else
        ans += dp[i];
      if (i - max_pts >= 0)
        sum -= dp[i - max_pts];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  printf("%f\n", obj.new21Game(10, 1, 10));  // expect: 1.00000
  printf("%f\n", obj.new21Game(6, 1, 10));   // expect: 0.60000
  printf("%f\n", obj.new21Game(21, 17, 10)); // expect: 0.73278
}
