// 3343. Count Number of Balanced Permutations
#include "leetcode.h"

/*
 * you are given a string 'num'. a string of digits is called balanced if the
 * sum of the digits at even indices is equal to the sum of the digits at odd
 * indices. return the number of distinct permutations of 'num' that are
 * balanced. since the answer may be very large, return it modulo 10e9+7. a
 * permutation is a rearrangement of all the characters of a string.
 */

static int mod = 1e9 + 7;

long long mod_exp(long long base, long long exp) {
  long long res = 1;
  base %= mod;
  while (exp) {
    if (exp & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

int countBalancedPermutations(char *num) {
  int n = strlen(num), freq[10] = {0};
  for (int i = 0; i < n; i++)
    freq[num[i] - '0']++;
  int even_cnt = (n + 1) / 2, odd_cnt = n - even_cnt, sum = 0;
  for (int i = 0; i < 10; i++)
    sum += i * freq[i];
  if (sum & 1)
    return 0;
  int target = sum / 2, max = n;
  long long *fac = (long long *)malloc((max + 1) * sizeof(long long));
  long long *ifac = (long long *)malloc((max + 1) * sizeof(long long));
  fac[0] = 1;
  for (int i = 1; i <= max; i++)
    fac[i] = (fac[i - 1] * i) % mod;
  ifac[max] = mod_exp(fac[max], mod - 2);
  for (int i = max - 1; i >= 0; i--)
    ifac[i] = (ifac[i + 1] * (i + 1)) % mod;
  long long dp[11][42][730] = {{{0}}};
  dp[0][0][0] = 1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j <= even_cnt; j++) {
      for (int k = 0; k <= target; k++) {
        if (!dp[i][j][k])
          continue;
        int curr = freq[i];
        for (int l = 0; l <= curr; l++) {
          if (j + l > even_cnt)
            break;
          int ns = k + i * l;
          if (ns > target)
            break;
          long long coef = (ifac[l] * ifac[curr - l]) % mod;
          dp[i + 1][j + l][ns] =
              (dp[i + 1][j + l][ns] + dp[i][j][k] * coef) % mod;
        }
      }
    }
  }
  long long ans = dp[10][even_cnt][target];
  ans = (ans * fac[even_cnt]) % mod;
  ans = (ans * fac[odd_cnt]) % mod;
  free(fac);
  free(ifac);
  return (int)ans;
}

int main() {
  char *n1 = "123", *n2 = "112", *n3 = "12345";
  printf("%d\n", countBalancedPermutations(n1)); // expect: 2
  printf("%d\n", countBalancedPermutations(n2)); // expect: 1
  printf("%d\n", countBalancedPermutations(n3)); // expect: 0
}
