// 1359. Count All Valid Pickup and Delivery Options
#include <stdio.h>
#include <stdlib.h>

/*
 * given 'n' orders, each order consists in pickup and delivery services. count
 * all valid pickup/delivery possible sequences such that 'delivery[i]' is
 * always after 'pickup[i]'. since the answer may be too large, return it modulo
 * 10^9+7
 */

int countOrders(int n) {
  if (n < 1)
    return 0;
  long combinations = 1L, mod = 1e9 + 7;
  for (int i = 2; i <= n; i++)
    combinations = (combinations * i * (2 * i - 1)) % mod;
  return (int)combinations;
}

int main() {
  printf("%d\n", countOrders(1)); // expect: 1
  printf("%d\n", countOrders(2)); // expect: 6
  printf("%d\n", countOrders(3)); // expect: 90
}
