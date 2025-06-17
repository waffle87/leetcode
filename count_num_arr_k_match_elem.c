// 3405. Count the Number of Arrays with K Matching Adjacent Elements
#include "leetcode.h"

/*
 * you are given three integers 'n', 'm', and 'k'. a good array 'arr' of size
 * 'n' is defined as follows: each element in 'arr' is in inclusive range '[1,
 * m]', and exactly 'k' indices 'i' where '1 <= i < n' satisfy the condition
 * 'arr[i - 1] == arr[i]'. return the number of good arrays that can be formed.
 * since the answer may be very large, return it modulo 10^9+7.
 */

const int mod = 1e9 + 7;

long long mult(long long n, long long m) { return (n * m) % mod; }

long long power(long long n, long long m) {
  long long res = 1, base = n;
  while (m > 0) {
    if (m & 1)
      res = mult(res, base);
    base = mult(base, base);
    m >>= 1;
  }
  return res;
}

long long inv(long long n) { return power(n, mod - 2); }

long long factorial(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; ++i)
    res = mult(res, i);
  return res;
}

long long combine(long long n, long long m) {
  return mult(factorial(n), inv(mult(factorial(m), factorial(n - m))));
}

int countGoodArrays(int n, int m, int k) {
  return mult(mult(combine(n - 1, n - 1 - k), m), power(m - 1, n - 1 - k));
}

int main() {
  printf("%d\n", countGoodArrays(3, 2, 1)); // expect: 4
  printf("%d\n", countGoodArrays(4, 2, 2)); // expect: 6
  printf("%d\n", countGoodArrays(5, 2, 0)); // expect: 2
}
