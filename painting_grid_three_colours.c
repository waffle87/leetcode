// 1931. Painting a Grid With Three Different Colors
#include "leetcode.h"

/*
 * you are given two integers 'm' and 'n'. consider an 'm x n' grid where each
 * cell is initially white. you can paint each cell red, green, or blue. all
 * cells must be painted. return the number of ways to colour the grid with no
 * two adjacent cells having the same colour. since the answer can be very
 * large, return it modulo 10^9+7.
 */

int colorTheGrid(int m, int n) {
  const int mod = 1e9 + 7;
  int max_mask = 1;
  for (int i = 0; i < m; ++i)
    max_mask *= 3;
  int states[48], s = 0;
  for (int i = 0; i < max_mask; ++i) {
    int curr = i, prev = -1;
    bool valid = true;
    for (int j = 0; j < m; ++j) {
      int dir = curr % 3;
      if (dir == prev) {
        valid = false;
        break;
      }
      prev = dir;
      curr /= 3;
    }
    if (valid)
      states[s++] = i;
  }
  int compat[48][48], compat_size[48];
  for (int i = 0; i < s; ++i)
    compat_size[i] = 0;
  for (int i = 0; i < s; ++i)
    for (int j = 0; j < s; ++j) {
      int x = states[i], y = states[j];
      bool valid = true;
      for (int k = 0; k < m; ++k) {
        if (x % 3 == y % 3) {
          valid = false;
          break;
        }
        x /= 3;
        y /= 3;
      }
      if (valid)
        compat[i][compat_size[i]++] = j;
    }
  int dp[48], copy[48];
  for (int i = 0; i < s; ++i)
    dp[i] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < s; ++j)
      copy[j] = 0;
    for (int j = 0; j < s; ++j) {
      int dir = dp[j];
      if (dir)
        for (int k = 0; k < compat_size[j]; ++k) {
          int new = compat[j][k];
          copy[new] = (copy[new] + dir) % mod;
        }
    }
    for (int j = 0; j < s; ++j)
      dp[j] = copy[j];
  }
  long long ans = 0;
  for (int i = 0; i < s; ++i)
    ans = (ans + dp[i]) % mod;
  return (int)ans;
}

int main() {
  printf("%d\n", colorTheGrid(1, 1)); // expect: 3
  printf("%d\n", colorTheGrid(1, 2)); // expect: 6
  printf("%d\n", colorTheGrid(5, 5)); // expect: 580986
}
