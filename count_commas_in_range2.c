// 3871. Count Commas in Range II
#include "leetcode.h"

/*
 * you are given an integer 'n'. return the total number of commas used when
 * writing all integers from '[1, n]' in standard number formatting.
 */

long long countCommas(long long n) {
  long long count = 0;
  if (n >= 1000LL)
    count += n - 999LL;
  if (n >= 1000000LL)
    count += n - 999999LL;
  if (n >= 1000000000LL)
    count += n - 999999999LL;
  if (n >= 1000000000000LL)
    count += n - 999999999999LL;
  if (n >= 1000000000000000LL)
    count += n - 999999999999999LL;
  return count;
}

int main() {
  long long r1 = countCommas(1002);
  long long r2 = countCommas(998);
  printf("%lld\n", r1);
  assert(r1 == 3);
  printf("%lld\n", r2);
  assert(r2 == 0);
}
