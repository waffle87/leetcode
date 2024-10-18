// 372. Super Pow
#include "leetcode.h"

/*
 * your task is to calculate `a^b % 1337` where 'a' is a positive integer and
 * 'b' is an extremely large positive integer given in the form of an array
 */

/*
 * the number 1337 only has two divisors: 7 and 191 (excluding 1 and itself), so
 * see if 'a' has a divisor of either of these. also note that 7 and 191 are
 * prime numbers, meaning we can use euler's theorem, or really just fermat's
 * little theorem if the mod 'n' is prime.
 */

int power(int x, int n, int mod) {
  int res = 1;
  for (x %= mod; n; x *= x % mod, n >>= 1)
    if (n & 1)
      res *= x % mod;
  return res;
}

int superPow(int a, int *b, int bSize) {
  if (!(a % 1337))
    return 0;
  int n = 0;
  for (int i = 0; i < bSize; i++)
    n = (n * 10 + b[i]) % 1140;
  if (!n)
    n += 1140;
  return power(a, n, 1337);
}

int main() {
  int b1[] = {3}, b2[] = {1, 0}, b3[] = {4, 3, 3, 8, 5, 2};
  printf("%d\n", superPow(2, b1, ARRAY_SIZE(b1))); // expect: 8
  printf("%d\n", superPow(2, b2, ARRAY_SIZE(b2))); // expect: 1024
  printf("%d\n", superPow(1, b3, ARRAY_SIZE(b3))); // expect: 1
}
