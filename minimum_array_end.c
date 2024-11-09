// 3133. Minimum Array End
#include "leetcode.h"

/*
 * you are given two integers 'n' and 'x'. you have to construct an array of
 * positive integers 'nums'. of size 'n' where for every '0 <= i < n - 1',
 * 'nums[i + 1]' is greater than 'nums[i]', and the result of the bitwise and
 * operation between all elements of 'nums' is 'x'. return the minimum possible
 * value of 'nums[n - 1]'
 */

long long minEnd(int n, int x) {
  n--;
  long long a = x, b;
  for (b = 1; n; b <<= 1)
    if (!(b & x)) {
      a |= (n & 1) * b;
      n >>= 1;
    }
  return a;
}

int main() {
  printf("%lld\n", minEnd(3, 4)); // expect: 6
  printf("%lld\n", minEnd(2, 7)); // expect: 15
}
