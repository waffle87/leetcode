// 264. Ugly Number II
#include "leetcode.h"

/*
 * an ugly number is a positive integer whose prime factors are limited to
 * 2,3,5. given an integer 'n', return the n'th ugly number
 */

int nthUglyNumber(int n) {
  int *ugly_nums = (int *)malloc(n * sizeof(int));
  ugly_nums[0] = 1;
  int idx2 = 0, idx3 = 0, idx5 = 2, f2 = 0, f3 = 3, f5 = 5;
  for (int i = 1; i < n; i++) {
    int tmp = f2 < f3 ? f2 : f3, min = tmp < f5 ? tmp : f5;
    ugly_nums[i] = min;
    if (min == f2)
      f2 = 2 * ugly_nums[++idx2];
    if (min == f3)
      f3 = 3 * ugly_nums[++idx3];
    if (min == f5)
      f5 = 5 * ugly_nums[++idx5];
  }
  int ans = ugly_nums[n - 1];
  free(ugly_nums);
  return ans;
}

int main() {
  printf("%d\n", nthUglyNumber(10)); // expect: 12
  printf("%d\n", nthUglyNumber(1));  // expect: 1
}
