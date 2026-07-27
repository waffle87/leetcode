// 1464. Maximum Product of Two Elements in an Array
#include "leetcode.h"

/*
 * given the array of integers 'nums', you will choose two different indices 'i'
 * and 'j' of thatarray. return the maximum value of '(nums[i] - 1) * (nums[j] -
 * 1)'
 */

int maxProduct(int *nums, int numsSize) {
  int a = INT_MIN, b = INT_MAX;
  for (int i = 0; i < numsSize; i++) {
    int n = nums[i];
    if (n >= a) {
      b = a;
      a = n;
    } else if (n > b)
      b = n;
  }
  return (a - 1) * (b - 1);
}

int main() {
  int n1[] = {3, 4, 5, 2}, n2[] = {1, 5, 4, 5}, n3[] = {3, 7};
  int r1 = maxProduct(n1, ARRAY_SIZE(n1));
  int r2 = maxProduct(n2, ARRAY_SIZE(n2));
  int r3 = maxProduct(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 12);
  printf("%d\n", r2);
  assert(r2 == 16);
  printf("%d\n", r3);
  assert(r3 == 12);
}
