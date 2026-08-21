// 3116. Kth Smallest Amount With Single Denomination Combination
#include "leetcode.h"

/*
 * you are given an integer array 'coins' representing coins of different
 * denominations and an integer 'k'. you have an infinite number of coins of
 * each denomination. however, you are not allowed to combine coins of different
 * denominations. return the k'th smallest amount that can be made using these
 * coins.
 */

long long gcd(long long a, long long b) {
  while (b) {
    long long tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

long long count(long long x, int m, long long *lcm) {
  long long res = 0;
  for (int mask = 1; mask < m; mask++) {
    if (lcm[mask] > x)
      continue;
    if (__builtin_popcount(mask) & 1)
      res += x / lcm[mask];
    else
      res -= x / lcm[mask];
  }
  return res;
}

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

long long findKthSmallest(int *coins, int coinsSize, int k) {
  qsort(coins, coinsSize, sizeof(int), cmp);
  int *new_coins = (int *)malloc(coinsSize * sizeof(int));
  int new_size = 0;
  for (int i = 0; i < coinsSize; i++) {
    bool flag = true;
    for (int j = 0; j < new_size; j++)
      if (!(coins[i] % new_coins[j])) {
        flag = false;
        break;
      }
    if (flag)
      new_coins[new_size++] = coins[i];
  }
  int n = new_size, m = 1 << n;
  long long *lcm = (long long *)malloc(m * sizeof(long long));
  long long l = k, r = (long long)new_coins[0] * k + 1;
  lcm[0] = 1;
  for (int mask = 1; mask < m; mask++) {
    int pre = mask & (mask - 1);
    int i = __builtin_ctz(mask);
    long long tmp = lcm[pre] / gcd(lcm[pre], new_coins[i]);
    if (tmp <= r / new_coins[i])
      lcm[mask] = tmp * new_coins[i];
    else
      lcm[mask] = r + 1;
  }
  while (l < r) {
    long long x = l + (r - l) / 2;
    if (count(x, m, lcm) >= k)
      r = x;
    else
      l = x + 1;
  }
  long long ans = l;
  free(new_coins);
  free(lcm);
  return ans;
}

int main() {
  int c1[] = {3, 6, 9}, c2[] = {5, 2};
  long long r1 = findKthSmallest(c1, ARRAY_SIZE(c1), 3);
  long long r2 = findKthSmallest(c2, ARRAY_SIZE(c2), 7);
  printf("%lld\n", r1);
  assert(r1 == 9);
  printf("%lld\n", r2);
  assert(r2 == 12);
}
