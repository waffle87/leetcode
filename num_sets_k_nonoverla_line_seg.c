// 1621. Number of Sets of K Non-Overlapping Line Segments
#include "leetcode.h"

/*
 * given 'n' points on a 1d plane, where the i'th point is at 'x = i', find the
 * number of ways we can draw exactly 'k' non-overlapping line segments such
 * that each segment covers two or more points. the endpoints of each segmment
 * must have integeral coordinates. the 'k' line segments do not have to cover
 * all 'n' points, and they are allowed to share endpoints. return the number of
 * ways we can draw 'k' non-overlapping segments. since the answer can be very
 * large, return it modulo 10^9+7.
 */

static int mod = 1e9 + 7;

long quick_pow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if ((b & 1))
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

int numberOfSets(int n, int k) {
  int m = 2 * k;
  long numer = 1, denom = 1;
  for (int i = 1; i <= m; i++) {
    numer = (numer * (n + k - i)) % mod;
    denom = (denom * i) % mod;
  }
  return (int)((numer * quick_pow(denom, mod - 2)) % mod);
}

int main() {
  int r1 = numberOfSets(4, 2);
  int r2 = numberOfSets(3, 1);
  int r3 = numberOfSets(30, 7);
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 796297179);
}
