// 121. Best Time to Buy and Sell Stock
#include "leetcode.h"

/*
 * given an array 'prices' where 'prices[i]' is the price of a given stock on
 * the ith day. maximise profit by choosing a single day to buy one stock and
 * choosing a diff day in future to sell stock. return maximum profit achievable
 * from transaction.
 */

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int lsf = INT_MAX, op = 0, pist = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < lsf)
        lsf = prices[i];
      pist = prices[i] - lsf;
      if (op < pist)
        op = pist;
    }
    return op;
  }
};

int main() {
  Solution obj;
  vector<int> p1 = {7, 1, 5, 3, 6, 4}, p2 = {7, 6, 4, 3, 1};
  cout << obj.maxProfit(p1) << endl; // expect: 5
  cout << obj.maxProfit(p2) << endl; // expect: 0
}
