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

const int MOD = 1e9 + 7;

long long _pow(long long a, long long b) {
  if (!b)
    return 1;
  return b % 2 ? a * _pow(a, b - 1) % MOD : _pow((a * a) % MOD, b / 2);
}

int countGoodNumbers(long long n) {
  long long odd = n / 2, even = n - odd;
  return _pow(20, odd) * ((n % 2) ? 5 : 1) % MOD;
}

int main() {
  printf("%d\n", countGoodNumbers(1));  // expect: 5
  printf("%d\n", countGoodNumbers(4));  // expect: 400
  printf("%d\n", countGoodNumbers(50)); // expect: 564908303
}
