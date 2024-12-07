// 3116. Kth Smallest Amount With Single Denomination Combination
#include "leetcode.h"

/*
 * you are given an integer array 'coins' representing coins of different
 * denominations and an integer 'k'. you have an infinite number of coins of
 * each denomination. however, you are not allowed to combine coins of different
 * denominations. return the k'th smallest amount that can be made using these
 * coins.
 */

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int cnt(int *coins, int coinsSize, int x) {
  int sum = 0;
  for (int mask = 1; mask < (1 << coinsSize); mask++) {
    int bits = __builtin_popcountll(mask);
    int least_common = 1;
    for (int j = 0; j < coinsSize; j++)
      if (mask & (1 << j))
        least_common = lcm(least_common, coins[j]);
    if (bits & 1)
      sum += x / least_common;
    else
      sum -= x / least_common;
  }
  return sum;
}

int bin_search(int *coins, int coinsSize, int k) {
  int left = 1, right = 25LL * 2e9;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (cnt(coins, coinsSize, mid) < k)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

long long findKthSmallest(int *coins, int coinsSize, int k) {
  return bin_search(coins, coinsSize, k);
}

int main() {
  int c1[] = {3, 6, 9}, c2[] = {5, 2};
  printf("%lld\n", findKthSmallest(c1, ARRAY_SIZE(c1), 3)); // expect: 9
  printf("%lld\n", findKthSmallest(c2, ARRAY_SIZE(c2), 7)); // expect: 12
}
