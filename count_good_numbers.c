// 1922. Count Good Numbers
#include "leetcode.h"

/*
 * a digit string is good if the digits (0-indexed) at even indices are even and
 * the digits at odd indices are prime (2,3,5,or 7). for example 2582 is good
 * because the digits 2 and 8 at even positions are even and the digits 5 and 2
 * at odd positions are prime. however, 3245 is not good because 3 is at an even
 * index, but is not even. given an integer 'n', return the total number of good
 * digit strings of length 'n'. since the answer may be large, return it modulo
 * 1e9+7. a digit string is a string consisting of digits 0 through 9 that may
 * contain leading zeros.
 */

static int mod = 1e9 + 7;

long long mod_exp(long long n, long long e) {
  int res = 1;
  n %= mod;
  while (e > 0) {
    if (e & 1)
      res = res * n % mod;
    e >>= 1;
    n = n * n % mod;
  }
  return res;
}

int countGoodNumbers(long long n) {
  long long a = mod_exp(5, (n + 1) / 2);
  long long b = mod_exp(4, n / 2);
  return (int)((a * b) % mod);
}

int main() {
  printf("%d\n", countGoodNumbers(1));  // expect: 5
  printf("%d\n", countGoodNumbers(4));  // expect: 400
  printf("%d\n", countGoodNumbers(50)); // expect: 564908303
}
