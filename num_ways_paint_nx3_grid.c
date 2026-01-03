// 1411. Number of Ways to Paint N × 3 Grid
#include "leetcode.h"

/*
 * you have a 'grid' of size 'n x 3' and you want to paint each cell of the grid
 * with exactly one of the three colours: red, yellow, or green while making
 * sure that no two adjacent cells have the same colour. given 'n' the number of
 * rows of the grid, return the number of ways you can paint this 'grid'. as the
 * answer may grow large, the answer must be computer modulo 10e9 + 7.
 */

int numOfWays(int n) {
  long a1 = 6, a2 = 6, b1, b2, mod = 1e9 + 7;
  for (int i = 1; i < n; ++i) {
    b1 = a1 * 3 + a2 * 2;
    b2 = a1 * 2 + a2 * 2;
    a1 = b1 % mod;
    a2 = b2 % mod;
  }
  return (a1 + a2) % mod;
}

int main() {
  printf("%d\n", numOfWays(1));    // expect: 12
  printf("%d\n", numOfWays(5000)); // expect: 30228214
}
