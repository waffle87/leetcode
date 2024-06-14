// 2485. Find the Pivot Integer
#include "leetcode.h"

/*
 * given a positive integer 'n', find the pivot integer 'x' such that the sum of
 * all elements between 1 and 'x' inclusively equals the sum of all elements
 * between 'x' and 'n' inclusively. return the pivot integer 'x'. if no such
 * integer exists, return -1. it is guaranteed that there will be at most one
 * pivot index for the given input.
 */

int pivotInteger(int n) {
  int l = 1, r = n, sum = n * (n + 1) / 2;
  while (l < r) {
    int m = (l + r) / 2;
    if (m * m - sum < 0)
      l = m + 1;
    else
      r = m;
  }
  return !(l * l - sum) ? l : -1;
}

int main() {
  printf("%d\n", pivotInteger(8)); // expect: 6
  printf("%d\n", pivotInteger(1)); // expect: 1
  printf("%d\n", pivotInteger(4)); // expect: -1
}
