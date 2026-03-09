// 3129. Find All Possible Stable Binary Arrays I
#include "leetcode.h"

/*
 * you are given 3 positive integers 'zero', 'one', and 'limit'. a binary array
 * 'arr' is called stable if the number of occurences of 0 in 'arr' is exactly
 * 0, the number of occurences of 1 in 'arr' is exactly 'one', and each subarray
 * of 'arr' with a size greater than 'limit' must contain both 0 and 1. return
 * the total number of stable binary arrays. since the answer may be very large,
 * return it modulo 10^9 + 7.
 */

int numberOfStableArrays(int zero, int one, int limit) {
  static int mod = 10e9 + 7;
  long long ***dp = (long long ***)malloc((zero + 1) * sizeof(long long));
  for (int i = 0; i < zero + 1; i++) {
    dp[i] = (long long **)malloc((one + 1) * sizeof(long long));
    for (int j = 0; j < one + 1; j++)
      dp[i][j] = (long long *)calloc(2, sizeof(long long));
  }
  for (int i = 0; i < zero + 1; i++)
    for (int i = 0; i <= (zero < limit ? zero : limit); ++i)
      dp[i][0][0] = 1;
  for (int j = 0; j <= (one < limit ? one : limit); ++j)
    dp[0][j][1] = 1;
  for (int i = 1; i <= zero; ++i)
    for (int j = 1; j <= one; ++j) {
      if (i > limit)
        dp[i][j][0] =
            dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
      else
        dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
      dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
      if (j > limit)
        dp[i][j][1] =
            dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
      else
        dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
      dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
    }
  int ans = (dp[zero][one][0] + dp[zero][one][1]) % mod;
  for (int i = 0; i < zero + 1; i++) {
    for (int j = 0; j < one + 1; j++)
      free(dp[i][j]);
    free(dp[i]);
  }
  free(dp);
  return ans;
}

int main() {
  int r1 = numberOfStableArrays(1, 1, 2);
  int r2 = numberOfStableArrays(1, 2, 1);
  int r3 = numberOfStableArrays(3, 3, 2);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r2); // expect: 1
  assert(r2 == 1);
  printf("%d\n", r3); // expect: 14
  assert(r3 == 14);
}
