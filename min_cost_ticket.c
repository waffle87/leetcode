// 983. Minimum Cost For Tickets
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * you have planned some train traveling one year in advance. the days of the
 * year in which you will travel are given as an integer array 'days'. each day
 * is an integer 1 - 365. train tickets are sold in three different ways: 1 day
 * pass sold for 'costs[0]' dollars 7 day pass sold for 'costs[1]' dollars 30
 * day pass sold for 'costs[2]' dollars the passes allow that many days of
 * consecutive travel. return mininum number of dollars you need to travel every
 * day in the given list of days.
 */

#define MIN(a, b, c)                                                           \
  ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

bool find_item(int *days, int days_size, int target) {
  int left = 0, right = days_size - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (days[mid] == target)
      return true;
    if (days[mid] > target)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return false;
}

int mincostTickets(int *days, int days_size, int *costs, int costs_size) {
  int arr_size = days[days_size - 1] + 30;
  int *dp = calloc(arr_size, sizeof(int));
  for (int i = 30; i < arr_size; i++) {
    if (find_item(days, days_size, i - 29) == false)
      dp[i] = dp[i - 1];
    else
      dp[i] = MIN(dp[i - 1] + costs[0], dp[i - 7] + costs[i],
                  dp[i - 30] + costs[2]);
  }
  int ans = dp[arr_size - 1];
  free(dp);
  return ans;
}

int main() {
  int d1[] = {1, 4, 6, 7, 8, 20},
      d2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  int c1[] = {2, 7, 15};
  printf("%d\n", mincostTickets(d1, 6, c1, 3));  // expect: 11
  printf("%d\n", mincostTickets(d2, 12, c1, 3)); // expect: 11
}
