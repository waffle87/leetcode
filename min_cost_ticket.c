// 983. Minimum Cost For Tickets
#include "leetcode.h"

/*
 * you have planned some train traveling one year in advance. the days of the
 * year in which you will travel are given as an integer array 'days'. each day
 * is an integer 1 - 365. train tickets are sold in three different ways: 1 day
 * pass sold for 'costs[0]' dollars 7 day pass sold for 'costs[1]' dollars 30
 * day pass sold for 'costs[2]' dollars the passes allow that many days of
 * consecutive travel. return mininum number of dollars you need to travel every
 * day in the given list of days.
 */

int mincostTickets(int *days, int daysSize, int *costs, int costsSize) {
  int dp[366] = {0}, idx = 0;
  for (int i = 1; i <= 365; ++i)
    if (idx < daysSize && i == days[idx]) {
      int one = dp[i - 1] + costs[0];
      int seven = dp[i - 7 > 0 ? i - 7 : 0] + costs[1];
      int thirty = dp[i - 30 > 0 ? i - 30 : 0] + costs[2];
      dp[i] = one < seven      ? one < thirty ? one : thirty
              : seven < thirty ? seven
                               : thirty;
      ++idx;
    } else
      dp[i] = dp[i - 1];
  return dp[365];
}

int main() {
  int d1[] = {1, 4, 6, 7, 8, 20},
      d2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  int c1[] = {2, 7, 15}, c2[] = {2, 7, 15};
  printf("%d\n",
         mincostTickets(d1, ARRAY_SIZE(d1), c1, ARRAY_SIZE(c1))); // expect: 11
  printf("%d\n",
         mincostTickets(d2, ARRAY_SIZE(d2), c1, ARRAY_SIZE(c2))); // expect: 17
}
