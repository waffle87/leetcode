// 2706. Buy Two Chocolates
#include "leetcode.h"

/*
 * given an integer array 'prices' representing the prices of various chocolates
 * in a store. you are also given a single integer 'money', which represents
 * your initial amount of money. you must buy exactly two chooclates in such a
 * way that you still have some non-negative money. you would to minimise the
 * sum of the prices of the two chocolates you buy. return the amount of money
 * you will have leftover after buying the two chocolates. if there is no way
 * for you to buy two chocolates without ending up in debt, return 'money'. note
 * that the leftover must be non-negative.
 */

int buyChoco(int *prices, int prices_size, int money) {
  int min1 = INT_MAX, min2 = INT_MAX, min1_idx = 0;
  for (int i = 0; i < prices_size; i++)
    if (prices[i] < min1) {
      min1 = prices[i];
      min1_idx = i;
    }
  int ans = money;
  if (ans - min1 <= 0)
    return money;
  ans -= min1;
  for (int i = 0; i < prices_size; i++) {
    if (i == min1_idx)
      continue;
    if (prices[i] < min2)
      min2 = prices[i];
  }
  if (ans - min2 < 0)
    return money;
  ans -= min2;
  return ans;
}

int main() {
  int p1[] = {1, 2, 2}, p2[] = {3, 2, 3};
  printf("%d\n", buyChoco(p1, ARRAY_SIZE(p1), 3)); // expect: 0
  printf("%d\n", buyChoco(p2, ARRAY_SIZE(p2), 3)); // expect: 3
}
