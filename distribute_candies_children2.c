// 2929. Distribute Candies Among Children II
#include "leetcode.h"

/*
 * you are given two positive integers 'n' and 'limit'. return the total number
 * of ways to distritube 'n' candies among 3 children such that no child gets
 * more than 'limit' candies.
 */

long long distributeCandies(int n, int limit) {
  long long cnt = 0;
  for (int i = fmax(0, n - 2 * limit); i <= fmin(limit, n); i++) {
    int j = fmin(limit, n - i) - fmax(0, n - i - limit) + 1;
    cnt += fmax(0, j);
  }
  return cnt;
}

int main() {
  printf("%lld\n", distributeCandies(5, 2)); // expect: 3
  printf("%lld\n", distributeCandies(3, 3)); // expect: 10
}
