// 1808. Maximize Number of Nice Divisors
#include <stdio.h>

/*
 * you are given a positive integer 'prime_factors'. you are asked to construct
 * a positive integer 'n' that satisfies the following conditions.
 * - the number of prime factors of 'n' (not necessarily distinct) is at most
 * 'prime_factors'
 * - the number of nice divisors of 'n' is maximised. note that a divisor of 'n'
 * nice if it is divisible by every prime factor of 'n'. for example if 'n =
 * 12', then its prime factors are '[2,2,3]', then '6' and '12' are nice
 * divisors, while '3' and '4' are not. return the number of nice divisors of
 * 'n'. since that number can be too large, return it modulo 10e9+7. note that a
 * prime number is a natural number greater than 1 that is not a product of two
 * smaller natural numbers. the prime factors of a number 'n' is a list of prime
 * numbers such that their product equals 'n'
 */

long modpow(long base, int exp, int mod) {
  long res = 1;
  for (; exp; exp >>= 1) {
    res *= (exp & 1 ? base : 1) % mod;
    base *= (base % mod);
  }
  return res;
}

int maxNiceDivisors(int prime_factors) {
  int st[6] = {1, 2, 3, 4, 5, 6}, mod = 1e9 + 7;
  return prime_factors < 6 ? st[prime_factors]
                           : st[3 + prime_factors % 3] *
                                 modpow(3, prime_factors / 3 - 1, mod) % mod;
}

int main() {
  printf("%d\n", maxNiceDivisors(5)); // expect: 6
  printf("%d\n", maxNiceDivisors(8)); // expect: 18
}
