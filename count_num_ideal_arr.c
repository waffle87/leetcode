// 2338. Count the Number of Ideal Arrays
#include "leetcode.h"

/*
 * you are given two integers 'n' and 'maxValue' which are used to describe an
 * ideal array. a 0-indexed integer array 'arr' of length 'n' is considered
 * ideal if the following conditions hold true: every 'arr[i]' is a value from 1
 * to 'maxValue' for '0 <= i < n', and every 'arr[i]' is divisble by 'arr[i -
 * 1]'. return the number of distinct ideal arrays of length 'n'. since the
 * answer may be very large, return it modulo 10^9+7.
 */

int idealArrays(int n, int maxValue) {
  int cmb[10001][14] = {1}, cnt[10001][14] = {}, mod = 1e9 + 7;
  if (!cmb[1][1]) {
    for (int i = 1; i <= 10000; ++i)
      for (int j = 0; j < 14; ++j)
        cmb[i][j] = !j ? 1 : (cmb[i - 1][j - 1] + cmb[i - 1][j]) % mod;
    for (int i = 1; i <= 10000; ++i) {
      ++cnt[i][0];
      for (int j = 2 * i; j <= 10000; j += i)
        for (int k = 0; cnt[i][k]; ++k)
          cnt[j][k + 1] += cnt[i][k];
    }
  }
  int ans = 0;
  for (int i = 1; i <= maxValue; ++i)
    for (int j = 0; j < fmin(14, n) && cnt[i][j]; ++j)
      ans = (1LL * cnt[i][j] * cmb[n - 1][j] + ans) % mod;
  return ans;
}

int main() {
  printf("%d\n", idealArrays(2, 5)); // expect: 10
  printf("%d\n", idealArrays(5, 3)); // expect: 11
}
