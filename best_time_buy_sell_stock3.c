// 123. Best Time to Buy and Sell Stock III
#include "leetcode.h"

/*
 * you are given an array 'prices' where 'prices[i]' is the price of a given
 * stock on the i'th day. find the maximum profit you can achieve. you may
 * complete at most two transactions. note, you may not engage in multiple
 * transactions simultaneously.
 */

int maxProfit(int *prices, int pricesSize) {
  int *s1 = (int *)calloc(pricesSize, sizeof(int));
  int *s2 = (int *)calloc(pricesSize, sizeof(int));
  int max = INT_MIN, min = prices[0];
  for (int i = 1; i < pricesSize - 1; i++) {
    if (min > prices[i])
      min = prices[i];
    if (max < prices[i] - min)
      max = prices[i] - min;
    s1[i] = max;
  }
  min = INT_MIN, max = prices[pricesSize - 1];
  s2[pricesSize - 1] = 0;
  for (int i = pricesSize - 2; i >= 0; i--) {
    if (prices[i] > max)
      max = prices[i];
    if (min < max - prices[i])
      min = max - prices[i];
    s2[i] = min;
  }
  max = INT_MIN;
  for (int i = 0; i < pricesSize; i++)
    max = max < s1[i] + s2[i] ? s1[i] + s2[i] : max;
  free(s1), free(s2);
  return max;
}

int main() {
  int p1[] = {3, 3, 5, 0, 0, 3, 1, 4}, p2[] = {1, 2, 3, 4, 5},
      p3[] = {7, 6, 4, 3, 1};
  printf("%d\n", maxProfit(p1, ARRAY_SIZE(p1))); // expect: 6
  printf("%d\n", maxProfit(p2, ARRAY_SIZE(p2))); // expect: 4
  printf("%d\n", maxProfit(p3, ARRAY_SIZE(p3))); // expect: 0
}
