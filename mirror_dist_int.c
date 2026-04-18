// 3783. Mirror Distance of an Integer
#include "leetcode.h"

/*
 * you are given an integer 'n'. define its mirror distance as 'abs(n -
 * reverse(n))' where 'reverse(n)' is the integer formed by reversing the digits
 * of 'n'. return an integer denoting the mirror distance of 'n'. 'abs(x)'
 * denotes the absolute value of 'x'.
 */

int reverse(int n) {
  int res = 0;
  while (n > 0) {
    res = res * 10 + (n % 10);
    n /= 10;
  }
  return res;
}

int mirrorDistance(int n) {
  int m = reverse(n);
  return abs(m - n);
}

int main() {
  int r1 = mirrorDistance(25);
  int r2 = mirrorDistance(10);
  int r3 = mirrorDistance(7);
  printf("%d\n", r1);
  assert(r1 == 27);
  printf("%d\n", r2);
  assert(r2 == 9);
  printf("%d\n", r3);
  assert(r3 == 0);
}
