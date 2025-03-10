// 714. Best Time to Buy and Sell Stock with Transaction Fee
#include "leetcode.h"

/*
 * given an array 'prices' where 'prices[i]' is the price of a given stock on
 * the i'th day, and an integer 'fee' representing a transaction fee. find the
 * maximum profit you can achieve. you may complete as many transactions as youl
 * like, but you need to pay the transaction fee for each transaction. note: you
 * may not engage in multiple transactions simultaneously (ie. you must sell the
 * stock before you buy again)
 */

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    if (n < 2)
      return 0;
    vector<int> hold(n, 0), sold(n, 0);
    hold[0] = -prices[0];
    for (int i = 1; i < n; i++) {
      hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
      sold[i] = max(sold[i - 1], hold[i - 1] - fee + prices[i]);
    }
    return sold[n - 1];
  }
};

int main() {
  Solution obj;
  vector<int> p1 = {1, 3, 2, 8, 4, 9};
  vector<int> p2 = {1, 3, 7, 5, 10, 3};
  printf("%d\n", obj.maxProfit(p1, 2)); // expect: 8
  printf("%d\n", obj.maxProfit(p2, 3)); // expect: 6
}
