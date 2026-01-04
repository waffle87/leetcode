// 1390. Four Divisors
#include "leetcode.h"

/*
 * given an integer array 'nums', return the sum of divisors of the integers in
 * that array that have exactly four divisors. if there is no such integer in
 * the array, return 0.
 */

bool prime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int sum_one(int n) {
  int p = (int)round(cbrt(n));
  if ((long)p * p * p == n && prime(p))
    return 1 + p + p * p + p * p * p;
  for (int i = 2; i * i <= n; i++) {
    if (!(n % i)) {
      int a = i, b = n / i;
      if (a != b && prime(a) && prime(b))
        return 1 + a + b + n;
      return -1;
    }
  }
  return -1;
}

int sumFourDivisors(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    int val = sum_one(nums[i]);
    if (val != -1)
      ans += val;
  }
  return ans;
}

int main() {
  int n1[] = {21, 4, 7}, n2[] = {21, 21}, n3[] = {1, 2, 3, 4, 5};
  printf("%d\n", sumFourDivisors(n1, ARRAY_SIZE(n1))); // expect: 32
  printf("%d\n", sumFourDivisors(n2, ARRAY_SIZE(n2))); // expect: 64
  printf("%d\n", sumFourDivisors(n3, ARRAY_SIZE(n3))); // expect: 0
}
