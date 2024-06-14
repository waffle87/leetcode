// 1732. Find the Highest Altitude
#include <limits.h>
#include <math.h>
#include <stdio.h>

/*
 * there is a biker going on a road trip. the road trip consists of 'n + 1'
 * points at different altitudes. the biker starts his trip on point 0 with
 * altitude 0. given an integer array 'ain' of length 'n' where 'gain[i]' is the
 * net gain in altidude between points 'i' and 'i + 1' for all '0 <= i < n'.
 * return the highest altitude of a point
 */

int largestAltitude(int *gain, int gain_size) {
  int ans = INT_MIN, pre_sum = 0;
  for (int i = 0; i < gain_size; i++) {
    ans = fmax(pre_sum, ans);
    pre_sum += gain[i];
  }
  if (pre_sum > ans)
    ans = pre_sum;
  return ans;
}

int main() {
  int g1[] = {-5, 1, 5, 0, -7}, g2[] = {-4, -3, -2, -1, 4, 3, 2};
  printf("%d\n", largestAltitude(g1, 5)); // expect: 1
  printf("%d\n", largestAltitude(g2, 7)); // expect: 0
}
