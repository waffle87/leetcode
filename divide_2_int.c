// 29. Divide Two Integers
#include "leetcode.h"

/*
 * Given two integers 'dividend' and 'divisor', divide two integers without
 * using multiplication, division, or mod operations. the integer division
 * should truncate toward zero, which means losing its fractional part. for
 * example, 8.345 would be truncated to 8. return the quotient after dividing
 * 'dividend' by 'divisor'.
 */

int divide(int dividend, int divisor) {
  if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;
  long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
  int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
  while (dvd >= dvs) {
    long temp = dvs, m = 1;
    while (temp << 1 <= dvd) {
      temp <<= 1;
      m <<= 1;
    }
    dvd -= temp;
    ans += m;
  }
  return sign * ans;
}

int main() {
  printf("%d\n", divide(10, 3)); // expect: 3
  printf("%d\n", divide(7, -3)); // expect: -2
}
