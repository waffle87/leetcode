// 121. Best Time to Buy and Sell Stock
#include <limits.h>
#include <stdio.h>

/*
 * given an array 'prices' where 'prices[i]' is the price of a given stock on
 * the ith day. maximise profit by choosing a single day to buy one stock and
 * choosing a diff day in future to sell stock. return maximum profit achievable
 * from transaction.
 */

int maxProfit(int *prices, int pricesSize) {
  int lsf = INT_MAX, op = 0, pist = 0;
  for (int i = 0; i < pricesSize; i++) {
    if (prices[i] < lsf)
      lsf = prices[i];
    pist = prices[i] - lsf;
    if (op < pist)
      op = pist;
  }
  return op;
}

int main() {
  int p1[] = {7, 1, 5, 3, 6, 4}, p2[] = {7, 6, 4, 3, 1};
  printf("%d\n", maxProfit(p1, 6)); // expect: 5
  printf("%d\n", maxProfit(p2, 5)); // expect: 0
}
