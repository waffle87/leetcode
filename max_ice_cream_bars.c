// 1833. Maximum Ice Cream Bars
#include <stdio.h>
#include <stdlib.h>

/*
 * it is a sweltering summer day, and a boy wants to buy some ice cream bars. at
 * the store, there are 'n' ice cream bars. you are given an array 'costs' of
 * length 'n' where 'costs[i]' is the price of the i'th ice cream bar in coins.
 * the boy initially has 'coins' coins to spend and he wants to buy as many ice
 * cream bars as possible. note, the boy can buy the ice cream bars in any
 * order. return the maximum number of ice cream bars the boy can buy with
 * 'coins' coins. you must solve the problem by counting sort.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maxIceCream(int *costs, int costs_size, int coins) {
  int n = costs_size;
  qsort(costs, n, sizeof(int), cmp);
  int ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += costs[i];
    if (sum <= coins)
      ans++;
    else
      break;
  }
  return ans;
}

int main() {
  int c1[] = {1, 3, 2, 4, 1}, c2[] = {10, 6, 8, 7, 7, 8},
      c3[] = {1, 6, 3, 1, 2, 5};
  printf("%d\n", maxIceCream(c1, 5, 7));  // expect: 4
  printf("%d\n", maxIceCream(c2, 6, 5));  // expect: 0
  printf("%d\n", maxIceCream(c3, 6, 20)); // expect: 6
}
