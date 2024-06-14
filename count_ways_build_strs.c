// 2466. Count Ways To Build Good Strings
#include <stdio.h>
#include <stdlib.h>

/*
 * given the integers 'zero, one, low, and high', we can construct a string by
 * starting with an empty string, and then at each step perform either of the
 * following opperations:
 * - append the character 0 'zero' times
 * - append the character 1 'one' times
 * this can be performed any number of times. a good string is a string
 * constructed by the above process having a length between 'low' and 'high'
 * (inclusive). return the number of different good strings that can be
 * constructed. return modulo 10^9+7.
 */

int countGoodStrings(int low, int high, int zero, int one) {
  int mod = 1e9 + 7;
  int *dp = calloc(high + 1, sizeof(int));
  long long ans = 0;
  dp[0] = 1;
  for (int i = 1; i <= high; i++) {
    if (i >= one)
      dp[i] = (dp[i] + dp[i - one]) % mod;
    if (i >= zero)
      dp[i] = (dp[i] + dp[i - zero]) % mod;
    if (i >= low)
      ans = (ans + dp[i]) % mod;
  }
  return ans;
}

int main() {
  printf("%d\n", countGoodStrings(3, 3, 1, 1)); // expect: 8
  printf("%d\n", countGoodStrings(2, 3, 1, 2)); // expect: 5
}
