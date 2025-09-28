// 461. Hamming Distance
#include "leetcode.h"

/*
 * the hamming distance between two integers is the number of positions at which
 * the corresponding bits are different. given two integers 'x' and 'y', return
 * the hamming distance between them.
 */

int hammingDistance(int x, int y) {
  int ans = 0, n = x ^ y;
  while (n) {
    ++ans;
    n &= n - 1;
  }
  return ans;
}

int main() {
  printf("%d\n", hammingDistance(1, 4)); // expect: 2
  printf("%d\n", hammingDistance(3, 1)); // expect: 1
}
