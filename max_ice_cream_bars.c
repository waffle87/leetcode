// 1833. Maximum Ice Cream Bars
#include "leetcode.h"

/*
 * it is a sweltering summer day, and a boy wants to buy some ice cream bars. at
 * the store, there are 'n' ice cream bars. you are given an array 'costs' of
 * length 'n' where 'costs[i]' is the price of the i'th ice cream bar in coins.
 * the boy initially has 'coins' coins to spend and he wants to buy as many ice
 * cream bars as possible. note, the boy can buy the ice cream bars in any
 * order. return the maximum number of ice cream bars the boy can buy with
 * 'coins' coins. you must solve the problem by counting sort.
 */

int maxIceCream(int *costs, int costsSize, int coins) {
  int max_cost = 0;
  for (int i = 0; i < costsSize; i++)
    max_cost = fmax(max_cost, costs[i]);
  int *freq = (int *)calloc(max_cost + 1, sizeof(int));
  for (int i = 0; i < costsSize; i++)
    freq[costs[i]]++;
  int ans = 0;
  for (int cost = 1; cost <= max_cost; cost++) {
    if (!freq[cost])
      continue;
    int can_buy = freq[cost] < coins / cost ? freq[cost] : coins / cost;
    ans += can_buy;
    coins -= can_buy * cost;
    if (coins < cost)
      break;
  }
  free(freq);
  return ans;
}

int main() {
  int c1[] = {1, 3, 2, 4, 1};
  int c2[] = {10, 6, 8, 7, 7, 8};
  int c3[] = {1, 6, 3, 1, 2, 5};
  int r1 = maxIceCream(c1, ARRAY_SIZE(c1), 7);
  int r2 = maxIceCream(c2, ARRAY_SIZE(c2), 5);
  int r3 = maxIceCream(c3, ARRAY_SIZE(c3), 20);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 6);
}
