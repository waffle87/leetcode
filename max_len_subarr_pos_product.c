// 1567. Maximum Length of Subarray With Positive Product
#include "leetcode.h"

/*
 * given an array of integers 'nums', find the maximum length of subarray where
 * the product of all its elements is positive. a subarray of anarray is a
 * consecutive sequence of zero or more values taken out of that array. return
 * the maximum length of a subarray with positive product.
 */

int getMaxLen(int *nums, int numsSize) {
  int pos = 0, neg = 0, ans = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!nums[i])
      pos = neg = 0;
    else if (nums[i]) {
      pos++;
      if (neg)
        neg++;
    } else {
      int tmp = pos;
      pos = neg ? neg + 1 : 0;
      neg = tmp + 1;
    }
    ans = pos > ans ? pos : ans;
  }
  return ans;
}

int main() {
  int n1[] = {1, -2, -3, 4}, n2[] = {0, 1, -2, -3, -4},
      n3[] = {-1, -2, -3, 0, 1};
  printf("%d\n", getMaxLen(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", getMaxLen(n2, ARRAY_SIZE(n2))); // expect: 3
  printf("%d\n", getMaxLen(n3, ARRAY_SIZE(n3))); // expect: 2
}
