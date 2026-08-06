// 3345. Smallest Divisible Digit Product I
#include "leetcode.h"

/*
 * you are given two integers 'n' and 't'. return the smallest nmber greater
 * than or equal to 'n' such that the product of its digits is divisible by 't'.
 */

int digit_product(int n) {
  int res = 1;
  while (n > 0) {
    int rem = n % 10;
    res *= rem;
    n /= 10;
  }
  return res;
}

int smallestNumber(int n, int t) {
  while (true) {
    int val = digit_product(n);
    if (!(val % t))
      return n;
    n++;
  }
}

int main() {
  int r1 = smallestNumber(10, 2);
  int r2 = smallestNumber(15, 3);
  printf("%d\n", r1);
  assert(r1 == 10);
  printf("%d\n", r2);
  assert(r2 == 16);
}
