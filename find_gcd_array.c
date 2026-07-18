// 1979. Find Greatest Common Divisor of Array
#include "leetcode.h"

/*
 * given an integer array 'nums', return the greatest common divisor of the
 * smallest number and largest in 'nums'. the greatest common divisor of two
 * numbers is the largest positive integer that evenly divides both numbers.
 */

int gcd(int a, int b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int findGCD(int *nums, int numsSize) {
  int a = INT_MAX, b = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    a = fmin(a, nums[i]);
    b = fmax(b, nums[i]);
  }
  return gcd(a, b);
}

int main() {
  int n1[] = {2, 5, 6, 9, 10};
  int n2[] = {7, 5, 6, 8, 3};
  int n3[] = {3, 3};
  int r1 = findGCD(n1, ARRAY_SIZE(n1));
  int r2 = findGCD(n2, ARRAY_SIZE(n2));
  int r3 = findGCD(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 3);
}
