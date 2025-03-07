// 2523. Closest Prime Numbers in Range
#include "leetcode.h"

/*
 * given two positive integers 'left' and 'right', find the two integers 'num1'
 * and 'num2' such that 'left <= num1 < num2 <= right', both 'num1' and 'num2'
 * are prime numbers, and 'num2 - num1' is the minimum amongst all other pairs
 * satisfying the above conditions. return the positive integer array 'ans =
 * [nums1, nums2]'. if there are multiple pairs satisfying these conditions,
 * return the one with the smallest 'num1' value. if no such numbers exist,
 * return '[-1, -1]'.
 */

int *closestPrimes(int left, int right, int *returnSize) {
  int *ans = (int *)malloc(2 * sizeof(int));
  *returnSize = 2;
  ans[0] = -1;
  ans[1] = -1;

  bool *sieve = (bool *)malloc((right + 1) * sizeof(bool));
  memset(sieve, true, (right + 1) * sizeof(bool));
  sieve[0] = sieve[1] = false;
  for (int i = 2; i * i <= right; i++)
    if (sieve[i])
      for (int j = i * i; j <= right; j += i)
        sieve[j] = false;
  int *prime = (int *)malloc((right - left + 1) * sizeof(int));
  int idx = 0;
  for (int i = left; i <= right; i++)
    if (sieve[i])
      prime[idx++] = i;
  free(sieve);
  if (idx < 2) {
    free(prime);
    return ans;
  }
  int min = INT_MAX;
  for (int i = 1; i < idx; i++) {
    int diff = prime[i] - prime[i - 1];
    if (min > diff) {
      min = diff;
      ans[0] = prime[i - 1];
      ans[1] = prime[i];
    }
  }
  free(prime);
  return ans;
}

int main() {
  int rs1, *cp1 = closestPrimes(10, 19, &rs1);
  int rs2, *cp2 = closestPrimes(4, 6, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", cp1[i]); // expect: 11 13
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", cp2[i]); // expect: -1 -1
  printf("\n");
  free(cp1);
  free(cp2);
}
