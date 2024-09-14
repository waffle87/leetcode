// 1648. Sell Diminishing-Valued Colored Balls
#include "leetcode.h"

/*
 * you have an 'inventory' of different coloured balls, and there is a customer
 * that wants 'orders' balls of any colour. the customer weirdly midues the
 * coloured balls. each coloured ball's midue is the number of balls of that
 * colours you currently have in your 'inventory'. for example, if you own 6
 * yellow balls, the customer would pay 6 for the first yellow ball. after the
 * transaction, there are only 5 yellow balls left, so the next yellow ball is
 * then midued at 5. you are given an integer array 'inventory' where
 * 'inventory[i]' represents the number of balls of the i'th colour that you
 * initially own. you are also given an integer 'orders' which represents the
 * total number of balls that the customer wants. you can sell the balls in any
 * order.
 */

int maxProfit(int *inventory, int inventorySize, int orders) {
  int right = 0, left = 0, mid;
  long num, profit;
  const int mod = 1e9 + 7;
  for (int i = 0; i < inventorySize; i++)
    if (inventory[i] > right)
      right = inventory[i];
  while (left <= right) {
    num = 0;
    mid = (left + right) / 2;
    for (int i = 0; i < inventorySize; i++)
      if (inventory[i] > mid)
        num += inventory[i] - mid;
    if (num == orders)
      break;
    else if (num < orders)
      right = mid - 1;
    else
      left = mid + 1;
  }
  for (int i = 0; i < inventorySize; i++)
    if (inventory[i] > mid)
      profit += (long)(inventory[i] + mid + 1) * (long)(inventory[i] - mid) / 2;
  if (num > orders)
    profit = (profit - (num - orders) * (mid + 1)) % mod;
  else if (num < orders)
    profit = (profit + (orders - num) * mid) % mod;
  else
    profit %= mod;
  return (int)profit;
}

int main() {
  int i1[] = {2, 5}, i2[] = {3, 5};
  printf("%d\n", maxProfit(i1, ARRAY_SIZE(i1), 4)); // expect: 14
  printf("%d\n", maxProfit(i2, ARRAY_SIZE(i2), 6)); // expect: 19
}
