// 1482. Minimum Number of Days to Make m Bouquets
#include "leetcode.h"

/*
 * given an integer array 'bloomDay', an integer 'm', and an integer 'k'. you
 * want to make 'm' bouquets. to make a bouquet, you need to use 'k' adjacent
 * flowers from the garden. the garden consists of 'n' flowers, the i'th flower
 * will bloom in the 'bloomDay[i]' and then can be used in exactly one bouquet.
 * return the minimum number of days you need to wait to be able to make 'm'
 * bouquets from the garden. if it is impossible to make 'm' bouquets, return -1
 */

int helper(int *bloomDay, int bloomDaySize, int day, int k) {
  int cnt_bloom = 0, cnt = 0;
  for (int i = 0; i < bloomDaySize; i++) {
    if (bloomDay[i] <= day) {
      cnt++;
      if (cnt == k) {
        cnt_bloom++;
        cnt = 0;
      }
    } else
      cnt = 0;
  }
  return cnt_bloom;
}

int minDays(int *bloomDay, int bloomDaySize, int m, int k) {
  int i, j, min_day = INT_MAX, max_day = INT_MIN;
  for (int i = 0; i < bloomDaySize; i++) {
    min_day = fmin(min_day, bloomDay[i]);
    max_day = fmax(max_day, bloomDay[i]);
  }
  int left = min_day, right = max_day, mid, num_bloom;
  while (left + 1 < right) {
    mid = (left + right) / 2;
    num_bloom = helper(bloomDay, bloomDaySize, mid, k);
    if (num_bloom >= m)
      right = mid;
    else
      left = mid + 1;
  }
  num_bloom = helper(bloomDay, bloomDaySize, left, k);
  if (num_bloom >= m)
    return left;
  num_bloom = helper(bloomDay, bloomDaySize, right, k);
  if (num_bloom >= m)
    return right;
  return -1;
}

int main() {
  int bd1[] = {1, 10, 3, 10, 2}, bd2[] = {1, 10, 3, 10, 2},
      bd3[] = {7, 7, 7, 7, 12, 7, 7};
  printf("%d\n", minDays(bd1, ARRAY_SIZE(bd1), 3, 1)); // expect: 3
  printf("%d\n", minDays(bd2, ARRAY_SIZE(bd2), 3, 2)); // expect: -1
  printf("%d\n", minDays(bd3, ARRAY_SIZE(bd3), 2, 3)); // expect: 2
}
