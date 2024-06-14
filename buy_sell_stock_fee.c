// 714. Best Time to Buy and Sell Stock with Transaction Fee
#include <math.h>
#include <stdio.h>

/*
 * given an array 'prices' where 'prices[i]' is the price of a given stock on
 * the i'th day, and an integer 'fee' representing a transaction fee. find the
 * maximum profit you can achieve. you may complete as many transactions as youl
 * like, but you need to pay the transaction fee for each transaction. note: you
 * may not engage in multiple transactions simultaneously (ie. you must sell the
 * stock before you buy again)
 */

int maxProfit(int *prices, int prices_size, int fee) {
  int pos = -1 * prices[0], profit = 0;
  for (int i = 1; i < prices_size; i++) {
    pos = fmax(pos, profit - prices[i]);
    profit = fmax(profit, pos + prices[i] - fee);
  }
  return profit;
}

int main() {
  int p1[] = {1, 3, 2, 8, 4, 9}, ps1 = 6, f1 = 2;
  int p2[] = {1, 3, 7, 5, 10, 3}, ps2 = 6, f2 = 3;
  printf("%d\n", maxProfit(p1, ps1, f1)); // expect: 8
  printf("%d\n", maxProfit(p2, ps2, f2)); // expect: 8
}
