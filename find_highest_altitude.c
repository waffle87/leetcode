// 1732. Find the Highest Altitude
#include "leetcode.h"

/*
 * there is a biker going on a road trip. the road trip consists of 'n + 1'
 * points at different altitudes. the biker starts his trip on point 0 with
 * altitude 0. given an integer array 'ain' of length 'n' where 'gain[i]' is the
 * net gain in altidude between points 'i' and 'i + 1' for all '0 <= i < n'.
 * return the highest altitude of a point
 */

int largestAltitude(int *gain, int gainSize) {
  int ans = 0, sum = 0;
  for (int i = 0; i < gainSize; i++) {
    sum += gain[i];
    int diff = sum - ans;
    ans += diff & ~(diff >> 0x1F);
  }
  return ans;
}

int main() {
  int g1[] = {-5, 1, 5, 0, -7};
  int g2[] = {-4, -3, -2, -1, 4, 3, 2};
  int r1 = largestAltitude(g1, ARRAY_SIZE(g1));
  int r2 = largestAltitude(g2, ARRAY_SIZE(g2));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 0);
}
