// 313. Super Ugly Number
#include "leetcode.h"

/*
 * a super ugly number is a positive integer whose prime factors are in the
 * array 'primes'. given an integer 'n' and an array of integers 'primes',
 * return the n'th super ugly number. the n'th super ugly number is guaranteed
 * to fit in a 32-bit integer (signed)
 */

int nthSuperUglyNumber(int n, int *primes, int primes_size) {
  int *idx = (int *)calloc(primes_size, sizeof(int));
  int *nums = (int *)malloc(sizeof(int) * n);
  *nums = 1;
  for (int i = 1; i < n; ++i) {
    int min = INT_MAX;
    for (int j = 0; j < primes_size; ++j)
      min = fmin(min, nums[idx[j]] * primes[j]); // INT_MAX overflows fmin here
    nums[i] = min;
    for (int j = 0; j < primes_size; ++j)
      if (nums[idx[j]] * primes[j] == min)
        ++idx[j];
  }
  return nums[n - 1];
}

int main() {
  int p1[] = {2, 7, 13, 19}, p2[] = {2, 3, 5};
  printf("%d\n", nthSuperUglyNumber(12, p1, ARRAY_SIZE(p1))); // expect: 32
  printf("%d\n", nthSuperUglyNumber(1, p2, ARRAY_SIZE(p2)));  // expect: 1
}
