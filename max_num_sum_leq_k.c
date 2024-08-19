// 3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K
#include "leetcode.h"

/*
 * you are given an integer 'k' and an integer 'x'. the price of a number is
 * calculated by the count of set its at positions 'x, 2x, 3x, etc.', in its
 * binary representation, starting from the least significant bit. the following
 * tale contains examples of how price is calculated
 * x    num    binary representation    price
 * ------------------------------------------
 * 1    13     000001101                3
 * 2    13     000001101                1
 * 2    233    011101001                3
 * 3    13     000001101                1
 * 3    362    101101010                2
 * the accumulated price of 'num' is the total price of numbers from 1 to 'num'.
 * 'num' is considered cheap if its accumulated price is less than or equal to
 * 'k'. return the greatest cheap number
 */

long long check(long long n, long long x) {
  long long res = 0, div, sz = 1 + log2(n);
  for (long long i = 0; i < sz; i++) {
    if (((i + 1) % x)) // ensure 'i + 1' is divisible by 'x'
      continue;
    long long pow2i = 1LL << i; // calculate 2^i
    if (!i)
      res += (n + 1) >> 1; // special case when i is 0, which is the msb
    else {
      div = n >> i; // calculate n / 2^i
      if (!div)
        continue;
      res += (div >> 1) * pow2i; // add contribution based on 'div' and 'pow2i'
      if (div & 1)
        res += (n % pow2i) + 1; // add remainder contribution if 'div' is odd
    }
  }
  return res;
}

long long findMaximumNumber(long long k, int x) {
  long long ans = 0, low = 1, high = 1e16, mid;
  while (high - low >= 3) {
    mid = (low + high) >> 1;
    if (check(mid, x) <= k) {
      ans = fmax(ans, mid);
      low = mid + 1;
    } else
      high = mid - 1;
  }
  for (long long i = low; i <= high; i++)
    if (check(i, x) <= k)
      ans = fmax(ans, i);
    else
      break;
  return ans;
}

int main() {
  printf("%lld\n", findMaximumNumber(9, 1)); // expect: 6
  printf("%lld\n", findMaximumNumber(7, 2)); // expect: 9
}
