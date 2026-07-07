// 3754. Concatenate Non-Zero Digits and Multiply by Sum I
#include "leetcode.h"

/*
 * you are given an integer 'n'. from a new integer 'x' by concatenating all the
 * non-zero digits of 'n' in their original order. if there are no non-zero
 * digits, 'x = 0'. let 'sum' be the sum of digits in 'x'. return an integer
 * representing the value of 'x * sum'.
 */

long long sumAndMultiply(int n) {
  long long x = 0, s = 0, m = 1;
  while (n) {
    x = (n % 10) * m + x;
    if (n % 10)
      m *= 10;
    s += n % 10;
    n /= 10;
  }
  return x * s;
}

int main() {
  long long r1 = sumAndMultiply(10203004);
  long long r2 = sumAndMultiply(1000);
  printf("%lld\n", r1);
  assert(r1 == 12340);
  printf("%lld\n", r2);
  assert(r2 == 1);
}
