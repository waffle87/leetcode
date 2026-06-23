// 3699. Number of ZigZag Arrays I
#include "leetcode.h"

/*
 * you are given three integers. a zigzag array of length 'n' is defined as
 * follows: each element lies in the '[l, r]', no two adjacent elements are
 * equal, and no three consecutive elements form a strickly increasing or
 * decreasing sequence. return the totla number of valid zigzag arrays. since
 * the answer may be very large, return it modulo 10^9+7.
 */

int zigZagArrays(int n, int l, int r) {
  int mod = 1e9 + 7, m = r - l + 1;
  long long *dp0 = (long long *)malloc(m * sizeof(long long));
  long long *dp1 = (long long *)malloc(m * sizeof(long long));
  long long *pref = (long long *)malloc(m * sizeof(long long));
  for (int i = 0; i < m; i++)
    dp0[i] = 1;
  for (int i = 2; i <= n; i++) {
    pref[0] = dp0[0];
    for (int j = 1; j < m; j++)
      pref[j] = (pref[j - 1] + dp0[j]) % mod;
    for (int j = 0; j < m; j++)
      dp1[j] = 0;
    if (!(i % 2)) {
      for (int j = 1; j < m; j++)
        dp1[j] = pref[j - 1];
    } else {
      long long total = pref[m - 1];
      for (int j = 0; j < m - 1; j++)
        dp1[j] = (total - pref[j] + mod) % mod;
    }
    long long *tmp = dp0;
    dp0 = dp1;
    dp1 = tmp;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++)
    ans = (ans + dp0[i]) % mod;
  free(dp0);
  free(dp1);
  free(pref);
  return ans * 2 % mod;
}

int main() {
  int r1 = zigZagArrays(3, 4, 5);
  int r2 = zigZagArrays(3, 1, 3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 10);
}
