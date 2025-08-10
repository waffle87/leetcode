// 869. Reordered Power of 2
#include "leetcode.h"

/*
 * you are given an integer 'n'. we reorder the digits in any order (including
 * the original order) such that the leading digit is not zero. return true if
 * an only if we can do this so that the resulting number is a power of two.
 */

static uint64_t signature(uint32_t n) {
  uint64_t res = 0;
  while (n) {
    res += 1UL << ((n % 10) * 4);
    n /= 10;
  }
  return res;
}

bool reorderedPowerOf2(int n) {
  const uint64_t sig = signature(n);
  for (int i = 0; i < 32; ++i)
    if (sig == signature(1 << i))
      return true;
  return false;
}

int main() {
  printf("%d\n", reorderedPowerOf2(1));  // expect: 1
  printf("%d\n", reorderedPowerOf2(10)); // expect: 0
}
