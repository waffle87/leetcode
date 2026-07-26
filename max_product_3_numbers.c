// 628. Maximum Product of Three Numbers
#include "leetcode.h"

/*
 * given an integer array 'nums', find three numbers whose product is maximum
 * and return the maximum product
 */

int maximumProduct(int *nums, int numsSize) {
  int a = -1001, b = a, c = b;
  int x = 1001, y = x;
  for (int i = 0; i < numsSize; i++) {
    int aa = a, bb = b, xx = x, curr = nums[i];
    a = fmax(a, curr);
    b = fmax(b, fmin(aa, curr));
    c = fmax(c, fmin(bb, curr));
    x = fmin(x, curr);
    y = fmin(y, fmax(xx, curr));
  }
  return fmax(a * b * c, a * x * y);
}

int main() {
  int n1[] = {1, 2, 3};
  int n2[] = {1, 2, 3, 4};
  int n3[] = {-1, -2, -3};
  int r1 = maximumProduct(n1, ARRAY_SIZE(n1));
  int r2 = maximumProduct(n2, ARRAY_SIZE(n2));
  int r3 = maximumProduct(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 24);
  printf("%d\n", r3);
  assert(r3 == -6);
}
