// 1913. Maximum Product Difference Between Two Pairs
#include "leetcode.h"

/*
 * the product difference between two pairs '(a, b)' and '(c, d)' is defined as
 * '(a * b) - (c * d)'. given an integer array 'nums', choose four distinct
 * indices 'w', 'x', 'y' and 'z' such that the product difference between pairs
 * '(nums[w], nums[x])' and '(nums[y], nums[y])' is maximised. return the
 * maximum such product difference
 */

int maxProductDifference(int *nums, int nums_size) {
  int a, b, c, d;
  a = b = 0;
  c = d = 10001;
  for (int i = 0; i < nums_size; i++) {
    int j = nums[i];
    if (j > b) {
      a = b;
      b = j;
    } else if (j > a)
      a = j;
    if (j < c) {
      c = d;
      d = j;
    } else if (j < c)
      c = j;
  }
  return ((a * b) - (c * d));
}

int main() {
  int n1[] = {5, 6, 2, 7, 4}, n2[] = {4, 2, 5, 9, 7, 4, 8};
  printf("%d\n", maxProductDifference(n1, ARRAY_SIZE(n1))); // expect: 34
  printf("%d\n", maxProductDifference(n2, ARRAY_SIZE(n2))); // expect: 64
}
