// 3622. Check Divisibility by Digit Sum and Product
#include "leetcode.h"

/*
 * you are given a positive integer 'n'. determine whether 'n' is divisible by
 * the sum of the following two values: the digit sum of 'n' (the sum of its
 * digits), or the digit product of 'n' (the product of its digits). return true
 * if 'n' is divisible by this sum, otherwise return false.
 */

bool checkDivisibility(int n) {
  int sum = 0, prod = 1, num = n;
  while (num) {
    sum += num % 10;
    prod *= num % 10;
    num /= 10;
  }
  return (!(n % (sum + prod)));
}

int main() {
  bool r1 = checkDivisibility(99);
  bool r2 = checkDivisibility(23);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
