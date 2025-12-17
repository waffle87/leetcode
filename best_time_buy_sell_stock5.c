// 3573. Best Time to Buy and Sell Stock V
#include "leetcode.h"

/*
 * you are given an integer array 'prices' where 'prices[i]' is the price of a
 * stock in dollars on the i'th day, and an integer 'k'. you are allowed to make
 * at most 'k' transactions, where each transaction can be either of the
 * following: normal transaction is buy on day 'i', then sell on a later day 'j'
 * where 'i < j'. short selling transaction where you sell on day 'i', then buy
 * back on a later day 'j' where 'i < j'. note that you must complete each
 * transaction betfore starting another. additionally, you can't buy or sell on
 * the same day you are selling or buying back as part of a previous
 * transaction. return the maximum total profit you can earn by making at most
 * 'k' transactions.
 */

void swap(long long ***a, long long ***b) {
  long long **tmp = *a;
  *a = *b;
  *b = tmp;
}

long long maximumProfit(int *prices, int pricesSize, int k) {
  long long **prev = (long long **)malloc((k + 1) * sizeof(long long *));
  long long **curr = (long long **)malloc((k + 1) * sizeof(long long *));
  for (int i = 0; i <= k; i++) {
    prev[i] = (long long *)malloc(3 * sizeof(long long));
    curr[i] = (long long *)malloc(3 * sizeof(long long));
    for (int j = 0; j < 3; j++)
      prev[i][j] = INT_MIN;
  }
  for (int i = 0; i <= k; i++)
    prev[i][0] = 0;
  for (int i = 0; i < pricesSize; i++) {
    for (int j = k; j >= 0; j--) {
      curr[j][0] = prev[j][0];
      curr[j][0] = fmax(curr[j][0], prev[j][1] + prices[i]);
      curr[j][0] = fmax(curr[j][0], prev[j][2] - prices[i]);
      curr[j][1] = prev[j][1];
      curr[j][2] = prev[j][2];
      if (j < k) {
        curr[j][1] = fmax(prev[j][1], prev[j + 1][0] - prices[i]);
        curr[j][2] = fmax(prev[j][2], prev[j + 1][0] + prices[i]);
      }
    }
    swap(&prev, &curr);
  }
  long long ans = prev[0][0];
  for (int i = 0; i <= k; i++) {
    free(prev[i]);
    free(curr[i]);
  }
  free(prev);
  free(curr);
  return ans;
}

int main() {
  int p1[] = {1, 7, 9, 8, 2}, p2[] = {12, 16, 19, 19, 8, 1, 19, 13, 9};
  printf("%lld\n", maximumProfit(p1, ARRAY_SIZE(p1), 2)); // expect: 14
  printf("%lld\n", maximumProfit(p2, ARRAY_SIZE(p2), 3)); // expect: 36
}
