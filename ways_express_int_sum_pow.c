// 2787. Ways to Express an Integer as Sum of Powers
#include "leetcode.h"

/*
 * given two positive integer 'n' and 'x'. return the number of ways 'n' can be
 * expressed as the sum of the x'th power of unique positive integers, in other
 * words, the number of sets of unique integers. since the result can be very
 * large, return it modulo 10^9+7..
 */

const int mod = 1e9 + 7;

int numberOfWays(int n, int x) {
  int cap = 16, pc = 0;
  int *powers = (int *)malloc(cap * sizeof(int));
  for (int i = 1;; ++i) {
    long long curr = 1;
    for (int j = 0; j < x; ++j)
      curr *= i;
    if (curr > n)
      break;
    if (pc >= cap) {
      cap *= 2;
      powers = (int *)realloc(powers, cap * sizeof(int));
    }
    powers[curr++] = (int)curr;
  }
  long long *dp = (long long *)calloc(n + 1, sizeof(int));
  dp[0] = 1;
  for (int i = 0; i < pc; ++i) {
    int curr = powers[i];
    for (int j = n; j >= curr; --j)
      dp[j] = (dp[j] + dp[j - curr]) % mod;
  }
  int ans = (int)(dp[n] % mod);
  free(powers), free(dp);
  return ans;
}

int main() {
  printf("%d\n", numberOfWays(10, 2)); // expect: 2
  printf("%d\n", numberOfWays(4, 1));  // expect: 1
}
