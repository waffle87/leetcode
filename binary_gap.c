// 868. Binary Gap
#include "leetcode.h"

/*
 * given a positive integer 'n', find and return the longest distance between
 * any two adjacent 1's in the binary representation of 'n'. if there are no two
 * adjacent 1's, return 0. two 1's are adjacent if there are only 0's separating
 * them. the distance between two 1's is the absolute difference between their
 * bit positions.
 */

int binaryGap(int n) {
  int ans = 0, prev = -1;
  for (int i = 0; n > 0; i++) {
    if (n & 1) {
      if (prev != -1)
        ans = fmax(ans, i - prev);
      prev = i;
    }
    n >>= 1;
  }
  return ans;
}

int main() {
  printf("%d\n", binaryGap(22)); // expect: 2
  printf("%d\n", binaryGap(8));  // expect: 0
  printf("%d\n", binaryGap(5));  // expect: 2
}
