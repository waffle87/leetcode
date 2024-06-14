// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
#include <stdio.h>

/*
 * given three integers 'n, m, k'. consider the following algorithm to find the
 * maximum element of an array of positive integers [image] you should build the
 * array 'arr' which has the following properties:
 * - 'arr' has exactly 'n' integers
 * - '1 <= arr[i] < m' where '(0 <= i < n)'
 * - after applying the mentioned algorithm to 'arr', the value 'search_cost' is
 * equal to 'k' return the number of ways to build the array 'arr' under the
 * mentioned conditions. as the answer may grow larger than a signed 32-bit
 * integer, the answer must be computed modulo 10^9+7
 */

int numOfArrays(int n, int m, int k) {
  int mod = 1e9 + 7, dp[m][k + 1];
  if (!k)
    return 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < k + 1; k++)
      dp[i][j] = 0;
  for (int i = 0; i < m; i++)
    dp[i][1] = 1;
  for (int i = 1; i < n; i++)
    for (int j = m - 1; j >= 0; j--)
      for (int l = 1; l < k + 1; l++) {
        dp[j][l] *= j + 1;
        dp[j][l] %= mod;
        for (int n = 0; n < j; n++) {
          dp[j][l] += dp[n][l - 1];
          dp[j][l] %= mod;
        }
      }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans += dp[i][k];
    ans %= mod;
  }
  return ans;
}

int main() {
  printf("%d\n", numOfArrays(2, 3, 1)); // expect: 6
  printf("%d\n", numOfArrays(5, 2, 3)); // expect: 0
  printf("%d\n", numOfArrays(9, 1, 1)); // expect: 1
}
