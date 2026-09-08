// 3870. Count Commas in Range
#include "leetcode.h"

/*
 * you are given an integer 'n'. return the total number of commas used when
 * writing all integers from '[1, n]' in standard formatting.
 */

int countCommas(int n) { return n < 1000 ? 0 : n - 999; }

int main() {
  int r1 = countCommas(1002);
  int r2 = countCommas(998);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
}
