// 790. Domino and Tromino Tiling
#include "leetcode.h"

/*
 * you have two types of tiles: a '2 x 1' domino shape and a tromino shape. you
 * may rotate these shapes. given an integer 'n', return the number of ways to
 * tile a '2 x n' board. since the answer may be very large, return it modulo
 * 10^9+7. in a tiling, every square must be tiled by a tile. two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.
 */

int numTilings(int n) {
  static int mod = 1e9 + 7;
  if (n <= 2)
    return n;
  int x = 1, y = 2, z = 5, m;
  for (int i = 4; i <= n; ++i) {
    m = (2LL * z + x) % mod;
    x ^= y ^= x ^= y;
    y ^= z ^= y ^= z;
    z ^= m ^= z ^= m;
  }
  return z;
}

int main() {
  printf("%d\n", numTilings(3)); // expect: 5
  printf("%d\n", numTilings(1)); // expect: 1
}
