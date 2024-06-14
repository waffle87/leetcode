// 343. Integer Break
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer 'n', break it into the sum of 'k' positive integers, where
 * 'k >= 2' and maximise the product of those integers. return the maximum
 * product you can get
 */

int integerBreak(int n) {
  int *dp = (int *)malloc((n + 1) * sizeof(int));
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  int max = INT_MIN, half, val, a, b;
  for (int i = 3; i <= n; i++) {
    half = i / 2;
    for (int j = 1; j <= half; j++) {
      a = (dp[j] > j) ? dp[j] : j;
      b = (dp[i - j] > (i - j)) ? dp[i - j] : (i - j);
      val = a * b;
      if (val > max)
        max = val;
    }
    dp[i] = max;
  }
  int ans = dp[n];
  free(dp);
  return ans;
}

int main() {
  printf("%d\n", integerBreak(2));  // expect: 1 (2 = 1 + 1, 1 * 1 = 1)
  printf("%d\n", integerBreak(10)); // expect: 36 (10 = 3 + 3 + 4, 3 * 3 * 4)
}
