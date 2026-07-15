// 3658. GCD of Odd and Even Sums
#include "leetcode.h"

/*
 * you are given an integer 'n'. your task is to compute the gcd of two values:
 * 'sumodd': the sum of the smallest 'n' positive odd numbers, and 'sumeven':
 * the sum of the smallest 'n' positive even numbers. return the gcd of 'sumodd'
 * and 'sumeven'
 */

int gcdOfOddEvenSums(int n) { return n; }

int main() {
  int r1 = gcdOfOddEvenSums(4);
  int r2 = gcdOfOddEvenSums(5);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 5);
}
