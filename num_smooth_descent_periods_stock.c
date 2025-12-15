// 2110. Number of Smooth Descent Periods of a Stock
#include "leetcode.h"

/*
 * you are given an integer array 'prices' representing the daily price history
 * of a stock where 'prices[i]' is the stock price on the i'th day. a smooth
 * descent period of a stock consists of one or more contiguous days such that
 * the price on each day is lower than the price on the peceding day by
 * exactly 1. the first day of the period is exempted from this rule. return the
 * number of smooth descent periods.
 */

long long getDescentPeriods(int *prices, int pricesSize) {
  int dp = 1;
  long long ans = 1;
  for (int i = 1; i < pricesSize; i++) {
    dp = prices[i] == prices[i - 1] - 1 ? dp + 1 : 1;
    ans += dp;
  }
  return ans;
}

int main() {
  int p1[] = {3, 2, 1, 4}, p2[] = {8, 6, 7, 7}, p3[] = {1};
  printf("%lld\n", getDescentPeriods(p1, ARRAY_SIZE(p1))); // expect: 7
  printf("%lld\n", getDescentPeriods(p2, ARRAY_SIZE(p2))); // expect: 4
  printf("%lld\n", getDescentPeriods(p3, ARRAY_SIZE(p3))); // expect: 1
}
