// 3652. Best Time to Buy and Sell Stock using Strategy
#include "leetcode.h"

/*
 * you are given two integer arrays 'prices' and 'strategy' where 'prices[i]' is
 * the price of a given stock, and 'strategy[i]' represents a trading action
 * taken: -1 indicates buying one unit of the stock, 0 indicates holding the
 * stock, 1 indicates selling one unit of the stock. you are also given an even
 * integer 'k' and may perform at most one modification to 'strategy'. the
 * profit is defined as the sum of 'strategy[i] * prices[i]' across all days.
 * return the maximum possible profit you can achieve.
 */

long long maxProfit(int *prices, int pricesSize, int *strategy,
                    int strategySize, int k) {
  long long ans = 0, new = 0;
  for (int i = 0; i < pricesSize; ++i)
    ans += prices[i] * strategy[i];
  for (int i = k / 2; i < k; ++i)
    new += prices[i];
  for (int i = k; i < pricesSize; ++i)
    new += prices[i] * strategy[i];
  ans = fmax(ans, new);
  for (int i = 0; i < pricesSize - k; ++i) {
    int base = i + k;
    new += prices[base - k] * strategy[base - k];
    new -= prices[base - (k / 2)];
    new += prices[base] * (1 - strategy[base]);
    ans = fmax(ans, new);
  }
  return ans;
}

int main() {
  int p1[] = {4, 2, 8}, s1[] = {-1, 0, 1};
  int p2[] = {5, 4, 3}, s2[] = {1, 1, 0};
  printf("%lld\n",
         maxProfit(p1, ARRAY_SIZE(p1), s1, ARRAY_SIZE(s1), 2)); // expect: 10
  printf("%lld\n",
         maxProfit(p2, ARRAY_SIZE(p2), s2, ARRAY_SIZE(s2), 2)); // expect: 9
}
